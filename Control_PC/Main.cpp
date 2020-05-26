#include <QApplication>
#include <cstdio>
#include <Windows.h>
#include "MainWindow.h"

FILE *FileStream;

int main(int argc, char* argv[]) {
	FreeConsole();
	AllocConsole();
	AttachConsole(GetCurrentProcessId());

	freopen_s(&FileStream, "CON", "w", stdout);
	freopen_s(&FileStream, "CON", "w", stderr);

	QApplication::setOrganizationName("DmitryShalaev");
	QApplication::setApplicationName("Control");
	
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	a.exec();

	return 0;
}