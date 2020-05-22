#include <QApplication>
#include <stdio.h>
#include <Windows.h>
#include "MainWindow.h"
#include "../general/id.h"

int main(int argc, char* argv[]) {
	FreeConsole();
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);
	freopen("CON", "w", stderr);

	QApplication::setOrganizationName("Control");
	QApplication::setApplicationName("Main");

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}

QString MainWindow::ByteArrayToString(const QByteArray& arr) {
	QString str;
	for (int i = 0; i < PACKET_SIZE; i++)
		if (i != PACKET_SIZE - 1)
			str += QString("%1:").arg(static_cast<unsigned char>(arr[i]), 2, 16, QChar('0')).toUpper();
		else
			str += QString("%1").arg(static_cast<unsigned char>(arr[i]), 2, 16, QChar('0')).toUpper();
	return str;
}
