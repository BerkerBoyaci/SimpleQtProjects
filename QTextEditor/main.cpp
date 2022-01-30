#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("Test");
    a.setOrganizationDomain("https://github.com/BerkerBoyaci");
    a.setApplicationName("App");
    a.setApplicationDisplayName("Application");
    a.setApplicationVersion("0.0.1");


    MainWindow w;
    w.show();
    return a.exec();
}
