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
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    camera = new QNetworkAccessManager;

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

void interface::GenMessage(){ //Préparer le message a envoyer
        this->vitesse=ui->ValeurVitesse->value();
        qDebug() << vitesse;
        buf.clear();
        buf.append((char)0xff);
        buf.append((char)0x07);
        if(foreward || backward || left || right)
            if(left || right || (foreward && this->cpt_ir1 > 0))
                buf.append((char)vitesse);
            else if(backward && this->cpt_ir2 > 0)
                buf.append((char)vitesse);
            else
                buf.append((char)0x00);
        else
            buf.append((char)0x00);
        buf.append((char)0x00);
        if(foreward || backward || left || right)
            if(left || right || (foreward && this->cpt_ir1 > 0))
                buf.append((char)vitesse);
            else if(backward && this->cpt_ir2 > 0)
                buf.append((char)vitesse);
            else
                buf.append((char)0x00);
        else
            buf.append((char)0x00);
        buf.append((char)0x00);
        if(this->foreward)
        //avant / avant
            buf.append((char)0b01010000);
        //arrière / avant
        else if(this->left)
            buf.append((char)0b00010000);
        //avant / arrière
        else if(this->right)
            buf.append((char)0b01000000);
        //arrière / arrière
        else if(this->backward)
            buf.append((char)0b00000000);
        else
            buf.append((char)0b01010000);
        quint16 crc = this->crc16(buf, 1);
        buf.append((char)crc);
        buf.append((char)(crc>>8));
    }

void interface::sendMessage(){
    tcp.write(buf);
    tcp.flush();
}

void interface::recvMessage(){
    char recv[21];
    tcp.read(recv, 21);
    this->battery=((unsigned char) recv[2] * 0.5);
    ui->batterylcd->display(battery);
    qDebug() << "Batterie " << battery << endl;
    qDebug() << "recv[0]" << (unsigned char) recv[0] << " recv[1] " << (unsigned char) recv[1];
    this->battery = ((unsigned char) recv[2] * 0.5);
    this->cpt_ir1 = (int) recv[3];
    this->cpt_ir2 = (int) recv[4];
}

void interface::tick(){
    GenMessage();
    sendMessage();
    recvMessage();
}

quint16 interface::crc16(QByteArray byteArray, int pos){
    unsigned char *data = (unsigned char* )byteArray.constData();
    quint16 crc = 0xFFFF;
    quint16 Polynome = 0xA001;
    quint16 Parity = 0;
    for(; pos < byteArray.length(); pos++){
        crc ^= *(data+pos);
        for (unsigned int CptBit = 0; CptBit <= 7 ; CptBit++){
            Parity= crc;
            crc >>= 1;
            if (Parity%2 == true) crc ^= Polynome;
        }
    }
    return crc;
}


void interface::on_pushButton_clicked() //DECONNEXION
{

    MainWindow* principal = (MainWindow*)this->parent();
    principal->fconnect= new connection(principal);
    principal->setCentralWidget(principal->fconnect);
    this->deleteLater();
}

void interface::on_haut_pressed()
{
    this->foreward=true;
    qDebug() << "Avant appuyé";
}

void interface::on_haut_released()
{
    this->foreward=false;
    qDebug() << "Avant relâché";
}


void interface::on_bas_pressed()
{
    this->backward=true;
    qDebug() << "arrière appuyé";
}

void interface::on_bas_released()
{
    this->backward=false;
    qDebug() << "arrière relaché";
}

void interface::on_gauche_pressed()
{
    this->left=true;
    qDebug() << "gauche appuyé";
}

void interface::on_gauche_released()
{
    this->left=false;
    qDebug() << "gauche relâché";
}

void interface::on_droite_pressed()
{
    this->right=true;
    qDebug() << "droite appuyé";
}

void interface::on_droite_released()
{
    this->right=false;
    qDebug() << "droite relâché";
}

//CLAVIER

void interface::keyPressEvent(QKeyEvent *event){
        if(event->key() == Qt::Key_Z){
           this->foreward=true;
        }
        else if(event->key() == Qt::Key_Q ){
           this->left=true;
        }
        else if(event->key() == Qt::Key_S ){
            this->backward=true;
        }
        else if(event->key() == Qt::Key_D ){
             this->right=true;
        }
        else if(event->key() == Qt::Key_8){
            QUrl url("http://"+ this->adresse +":8080"+cameraup);
            camera->get(QNetworkRequest(url));
        }
        else if(event->key() == Qt::Key_2){
            QUrl url("http://" + this->adresse +":8080" + cameradown);
                        camera->get(QNetworkRequest(url));
        }
        else if(event->key() == Qt::Key_4){
            QUrl url("http://" + this->adresse +":8080" + cameraleft);
                        camera->get(QNetworkRequest(url));
        }
        else if(event->key() == Qt::Key_6){
            QUrl url("http://" + this->adresse +":8080" + cameraright);
            camera->get(QNetworkRequest(url));
        }
        else if(event->key() == Qt::Key_5){
            QUrl url("http://" + this->adresse +":8080" + camcenter);
            camera->get(QNetworkRequest(url));
            qDebug() << "Cam centré !";
        }



}
void interface::keyReleaseEvent(QKeyEvent *event){
        if(event->key() == Qt::Key_Z || Qt::Key_Up){
            this->foreward=false;
        }
        else if(event->key() == Qt::Key_Q){
            this->left=false;
        }
        else if(event->key() == Qt::Key_S ){
           this->backward=false;
        }
        else if(event->key() == Qt::Key_D ){
          this->right=false;
        }

}


