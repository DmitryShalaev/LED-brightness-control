#include <QDebug>
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "../general/id.h"

void MainWindow::ProcessingReceivedData(const uint8_t Data[]) {
	const auto R_ID = static_cast<uint16_t>(((Data[1] & 0xE0) << 3) | Data[0]);
	if (!HashNodesStatus->contains(R_ID)) {
		qCritical() << "ERROR:A data packet received from an unknown node with ID" << R_ID << "will be ignored";
		return;
	}

	NodeStatus Node = HashNodesStatus->value(R_ID);

	switch (Data[1] & 0x1F) {
		case INIT:

			if ((Data[2] & 0x01) == 0x01)
				Node.logicIO |= 0x01;
			else
				Node.logicIO &= ~0x01;

			if ((Data[2] & 0x02) == 0x02)
				Node.logicIO |= 0x02;
			else
				Node.logicIO &= ~0x02;

			if ((Data[2] & 0x04) == 0x04)
				Node.logicIO |= 0x04;
			else
				Node.logicIO &= ~0x04;

			if ((Data[2] & 0x08) == 0x08)
				Node.logicIO |= 0x08;
			else
				Node.logicIO &= ~0x08;

			Node.PWM1 = Data[3];
			Node.PWM2 = Data[4];
			Node.PWM3 = Data[5];

			break;

		case OUT_1:

			if (Data[2] == ON)
				Node.logicIO |= 0x01;
			else
				Node.logicIO &= ~0x01;

			break;

		case OUT_2:

			if (Data[2] == ON)
				Node.logicIO |= 0x02;
			else
				Node.logicIO &= ~0x02;

			break;

		case OUT_3:

			if (Data[2] == ON)
				Node.logicIO |= 0x04;
			else
				Node.logicIO &= ~0x04;

			break;

		case OUT_4:

			if (Data[2] == ON)
				Node.logicIO |= 0x08;
			else
				Node.logicIO &= ~0x08;

			break;

		case ADC:

			Node.ADC1 = static_cast<double>((((Data[2] & 0xF0) << 4) | Data[3]) * 3.3 / 4095);

			Node.ADC2 = static_cast<double>((((Data[2] & 0x0F) << 8) | Data[4]) * 3.3 / 4095);

			break;

		case IN_1:

			if (Data[2] == ON)
				Node.logicIO |= 0x10;
			else
				Node.logicIO &= ~0x10;

			break;

		case IN_2:

			if (Data[2] == ON)
				Node.logicIO |= 0x20;
			else
				Node.logicIO &= ~0x20;

			break;

		case IN_3:

			if (Data[2] == ON)
				Node.logicIO |= 0x40;
			else
				Node.logicIO &= ~0x40;

			break;

		case LUX:

			Node.LX = static_cast<double>(((Data[2] << 8) | Data[3]) / 1.2);

			break;

		case CONNECTED:

			MasterID = R_ID;
			qDebug() << "Master ID : " << QString().setNum(MasterID);
			Connected();

			break;

		default: ;
	}

	HashNodesStatus->insert(R_ID, Node);
	if (ui->CB_ID->currentText().toUInt() == R_ID) {
		UpdateMainWindow();
	}
}
