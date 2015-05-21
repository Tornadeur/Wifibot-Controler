#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QTcpSocket>
#include <QTimer>
#include <QUrl>
#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include <QNetworkAccessManager>
#include <QtNetwork>

#define cameraup "/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200"
#define cameradown "/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200"
#define cameraleft "/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"
#define cameraright "/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200"

namespace Ui {
class interface;
}

class interface : public QWidget
{
    Q_OBJECT

public:
    explicit interface(QWidget *parent = 0);
    ~interface();
    bool Connexion(QString,quint16);
    bool foreward;
    bool backward;
    bool left;
    bool right;
    bool connecte;
    QNetworkAccessManager* camera;
    QByteArray buf;
    QString adresse;
    QString port;
    int cpt_ir1;
    int cpt_ir2;
    QTcpSocket tcp;
    QTimer *timer;
    quint16 vitesse;
    quint16 battery;
    quint16 crc16(QByteArray, int);
    void GenMessage();
    void recvMessage();
    void sendMessage();
    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent *event);


private slots:
    void tick();
    void on_pushButton_clicked();

    void on_haut_pressed();

    void on_haut_released();



    void on_bas_released();

    void on_gauche_pressed();

    void on_gauche_released();

    void on_droite_pressed();

    void on_droite_released();

    void on_bas_pressed();

private:
    Ui::interface *ui;
};

#endif // INTERFACE_H
