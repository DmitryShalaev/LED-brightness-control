#include "MainWindow.h"
#include <QApplication>
#include <windows.h>

int main(int argc, char *argv[])
{
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
