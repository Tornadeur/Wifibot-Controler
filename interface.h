#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

namespace Ui {
class interface;
}

class interface : public QWidget
{
    Q_OBJECT

public:
    explicit interface(QWidget *parent = 0);
    ~interface();

private slots:
    void on_pushButton_clicked();

private:
    Ui::interface *ui;
};

#endif // INTERFACE_H
