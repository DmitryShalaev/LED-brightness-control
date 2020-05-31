#include "MainWindow.h"
#include "QDebug"
#include "ui_MainWindow.h"

void MainWindow::AutomationCallback(const bool init) {
	Automatically.Timer->stop();

	if (init) {
		Automatically.ExternalCounter = Automatically.InternalCounter = Automatically.ControlValueChanges = 0;
		Automatically.LUXRequested = false;
	}

	if (VectorHostNodes.size() > Automatically.ExternalCounter) {

		const uint16_t HostNodeID = VectorHostNodes.at(Automatically.ExternalCounter);
		NodeStatus HostNodeStatus = HashNodesStatus->value(HostNodeID);

		if (!ui->RB_TurnOffLight->isChecked() || HostNodeStatus.DetectMovement) {

			if (!Automatically.LUXRequested) {
				Automatically.LUXRequested = true;

				memset(dataToSend, 0, sizeof(dataToSend));
				dataToSend[1] = LUX;
				Send(dataToSend, false, HostNodeID);

				Automatically.Timer->start(1000);
				return;
			}

			if (Automatically.InternalCounter == 0) {
				Automatically.ControlValueChanges = 0;
				if (abs(ui->SB_MaintainLux->value() - HostNodeStatus.LX) > ui->SB_MaintainLuxDeadband->value()) {
					if ((ui->SB_MaintainLux->value() - HostNodeStatus.LX) > 0) {
						if ((HostNodeStatus.ControlValue + ui->SB_MaintainLuxStep->value()) <= 255) {
							HostNodeStatus.ControlValue += ui->SB_MaintainLuxStep->value();
							Automatically.ControlValueChanges++;
						}
					} else {
						if ((HostNodeStatus.ControlValue - ui->SB_MaintainLuxStep->value()) >= 0) {
							HostNodeStatus.ControlValue -= ui->SB_MaintainLuxStep->value();
							Automatically.ControlValueChanges++;
						}
					}
				}

				HashNodesStatus->insert(HostNodeID, HostNodeStatus);
			}

			if (Automatically.ControlValueChanges != 0) {

				if (HostNodeStatus.SlavesNodes.size() > Automatically.InternalCounter) {

					const uint16_t SlavesNodeID = HostNodeStatus.SlavesNodes.at(Automatically.InternalCounter).toInt();
					Automatically.InternalCounter++;

					NodeStatus SlavesNodeStatus = HashNodesStatus->value(SlavesNodeID);
					SlavesNodeStatus.PWM1 = HostNodeStatus.ControlValue;
					SlavesNodeStatus.PWM2 = HostNodeStatus.ControlValue;
					SlavesNodeStatus.PWM3 = HostNodeStatus.ControlValue;
					HashNodesStatus->insert(SlavesNodeID, SlavesNodeStatus);

					memset(dataToSend, 0, sizeof(dataToSend));
					dataToSend[1] = ALLPWM;
					dataToSend[2] = HostNodeStatus.ControlValue;
					Send(dataToSend, false, SlavesNodeID);

					Automatically.Timer->start(1000);
					return;
				}

			}

			Automatically.InternalCounter = 0;
			Automatically.ExternalCounter++;
			Automatically.LUXRequested = false;
			AutomationCallback();
			return;
		}
	}

	Automatically.ExternalCounter = Automatically.InternalCounter = 0;
	Automatically.LUXRequested = false;

	Automatically.Timer->start(Automatically.ControlValueChanges != 0
															? ((((ui->TE_PWMSpeed->time().minute() * 60 + ui->TE_PWMSpeed->time().second()) * 1000) /
																255) * ui->SB_MaintainLuxStep->value())
															: ((ui->TE_PWMSpeed->time().minute() * 60 + ui->TE_PWMSpeed->time().second()) * 1000));
}
