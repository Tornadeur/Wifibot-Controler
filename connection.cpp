#include "connection.h"
#include "ui_connection.h"
#include <mainwindow.h>

connection::connection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::connection)
{

    ui->setupUi(this);


}



connection::~connection()
{
    delete ui;
}

void connection::on_pushButton_clicked() //CONNECTION
{
    QString address = ui->adresse->text();
    quint16 port = quint16(ui->port->text().toInt());
    MainWindow *principal = (MainWindow*)this->parent();
    principal->finterface= new interface(principal);
    principal->setCentralWidget(principal->finterface);
    this->deleteLater();

}
