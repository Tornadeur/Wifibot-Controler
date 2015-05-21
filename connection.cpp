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
    QString adress = ui->adresse->text();
    quint16 port = quint16(ui->port->text().toInt());
    MainWindow *principal = (MainWindow*)this->parent();
    principal->finterface= new interface(principal);


    if(principal->finterface->Connexion(adress,port)){
    QMessageBox::information(this,"Connection","Connection réussi !");
    principal->finterface->adresse=adress;
    principal->finterface->adresse=port;}
    principal->setCentralWidget(principal->finterface);
    this->deleteLater();

}
