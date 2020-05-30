#include "MainWindow.h"
#include "QDebug"
#include "ui_MainWindow.h"

#include "../general/id.h"

void MainWindow::AutomationCallback(const bool init) {

	if (init) {
		Automatically.InternalCounter = Automatically.ExternalCounter = 0;
		Automatically.LUXRequested = false;
	}

	do {
		const uint16_t ExternalNodeIndex = HashNodesStatus->keys()[Automatically.ExternalCounter];
		NodeStatus ExternalNode = HashNodesStatus->value(ExternalNodeIndex);

		if (ExternalNode.SlavesNodes.isEmpty()) {
			Automatically.ExternalCounter++;
			Automatically.LUXRequested = false;
			continue;
		}

		if (!Automatically.LUXRequested) {
			Automatically.LUXRequested = true;

			memset(dataToSend, 0, sizeof(dataToSend));
			dataToSend[1] = LUX;
			Send(dataToSend, false, ExternalNodeIndex);

			Automatically.Timer->start(1000);
			return;
		}

		if (Automatically.InternalCounter == 0) {
			ExternalNode.EstimatedValue = ExternalNode.LX / 255; //TODO
			HashNodesStatus->insert(ExternalNodeIndex, ExternalNode);
		}

		const uint16_t InternalNodeIndex = ExternalNode.SlavesNodes.at(Automatically.InternalCounter).toInt();

		if (Automatically.InternalCounter >= ExternalNode.SlavesNodes.size()) {
			Automatically.InternalCounter = 0;
			Automatically.ExternalCounter++;
			Automatically.LUXRequested = false;
			continue;
		}
		Automatically.InternalCounter++;

		NodeStatus InternalNode = HashNodesStatus->value(InternalNodeIndex);
		InternalNode.PWM1 = ExternalNode.EstimatedValue;
		InternalNode.PWM2 = ExternalNode.EstimatedValue;
		InternalNode.PWM3 = ExternalNode.EstimatedValue;
		HashNodesStatus->insert(InternalNodeIndex, InternalNode);

		memset(dataToSend, 0, sizeof(dataToSend));
		dataToSend[1] = ALLPWM;
		dataToSend[2] = ExternalNode.EstimatedValue;
		Send(dataToSend, false, InternalNodeIndex);

		Automatically.Timer->start(1000);
		return;

	}
	while (HashNodesStatus->keys().size() > Automatically.ExternalCounter);

	if (Automatically.ExternalCounter >= HashNodesStatus->keys().size()) {
		Automatically.ExternalCounter = 0;
		Automatically.LUXRequested = false;
		Automatically.Timer->start((ui->TE_PWMSpeed->time().minute() * 60 + ui->TE_PWMSpeed->time().second()) * 1000);
	}
}
