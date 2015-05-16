#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <connection.h>
#include "credits.h"

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

private:
    Ui::MainWindow *ui;
    connection* fconnect;
};

#endif // MAINWINDOW_H
