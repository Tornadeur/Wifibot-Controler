#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fconnect = new connection(this);
    this->setCentralWidget(fconnect);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionA_propos_triggered()
{
    credits popup;
    popup.setModal(true);
    popup.exec();
}
