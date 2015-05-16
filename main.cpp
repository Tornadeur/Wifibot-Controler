#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{

    QApplication application(argc, argv);
    MainWindow* principal = new MainWindow();




principal->show();
    return application.exec();
}
