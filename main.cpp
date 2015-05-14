#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{

    QApplication application(argc, argv);
    MainWindow* principal = new MainWindow();
    connection* fconnect = new connection();
    QHBoxLayout* layout1 = new QHBoxLayout();
    principal->setCentralWidget(fconnect);




principal->show();
    return application.exec();
}
