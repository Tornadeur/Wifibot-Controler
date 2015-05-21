#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QTcpSocket>
#include <QTimer>
#include <QUrl>
#include <QMessageBox>

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
    QByteArray buf;
    QString adresse;
    QString port;
    int cpt_ir1;
    int cpt_ir2;
    QTcpSocket tcp;
    QTimer *timer;
    quint16 vitesse;
    quint16 battery;
    quint16 crc16(QByteArray byteArray, int pos);

private slots:
    void on_pushButton_clicked();

private:
    Ui::interface *ui;
};

#endif // INTERFACE_H
