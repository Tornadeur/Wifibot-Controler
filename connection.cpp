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

void connection::on_pushButton_clicked()
{
    MainWindow *principal = (MainWindow*)this->parent();
    principal->finterface= new interface(principal);
    principal->setCentralWidget(principal->finterface);

}
