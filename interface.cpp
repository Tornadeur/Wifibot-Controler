#include "interface.h"
#include "ui_interface.h"
#include <mainwindow.h>

interface::interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
    this->connecte = false;
    this->foreward = false;
    this->backward = false;
    this->left = false;
    this->right = false;
    this->battery = 0;
    timer = new QTimer();
    //timer->setInterval(100);
    //connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

}

interface::~interface()
{
    delete ui;
}

bool interface::Connexion(QString address, quint16 port){
    qDebug() << "Connexion à " << address << ":" << port;
    this->foreward = false;
    this->backward = false;
    this->left = false;
    this->right = false;
    tcp.connectToHost(address, port);
    if(tcp.waitForConnected(5000)){
        this->connecte = true;
        timer->start();
        this->adresse = address;
        this->port = port;
        ui->webcam->setUrl(QUrl("http://"+ this->adresse +":8080/javascript_simple.html"));
        return true;
    }
    else{
        this->connecte = false;
        return false;
    }
}

void interface::on_pushButton_clicked()
{

    MainWindow* principal = (MainWindow*)this->parent();
    principal->fconnect= new connection(principal);
    principal->setCentralWidget(principal->fconnect);
    this->deleteLater();
}
