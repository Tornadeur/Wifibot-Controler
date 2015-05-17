#ifndef CONNECTION_H
#define CONNECTION_H

#include <QWidget>

namespace Ui {
class connection;
}

class connection : public QWidget
{
    Q_OBJECT

public:
    explicit connection(QWidget *parent = 0);
    ~connection();

private slots:
    void on_pushButton_clicked();

private:
    Ui::connection *ui;
};

#endif // CONNECTION_H
