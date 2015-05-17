#include "interface.h"
#include "ui_interface.h"
#include <mainwindow.h>

interface::interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
}

interface::~interface()
{
    delete ui;
}

void interface::on_pushButton_clicked()
{
    MainWindow* principal = (MainWindow*)this->parent();
    principal->fconnect= new connection(principal);
    principal->setCentralWidget(principal->fconnect);
    this->deleteLater();
}
