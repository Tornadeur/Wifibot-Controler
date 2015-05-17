#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <connection.h>
#include <credits.h>
#include <interface.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionA_propos_triggered();

public :
    Ui::MainWindow *ui;
    connection* fconnect;
 interface* finterface;
};

#endif // MAINWINDOW_H
