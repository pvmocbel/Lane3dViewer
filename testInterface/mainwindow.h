#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "irrviewer.h"
#include "cena.h"
#include"irrnode.h"

class Cena;

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void keyPressEvent( QKeyEvent * event);
     double val;



private:
    Ui::MainWindow *ui;
    Cena* cena;

public slots:
    void initIrrlichtWindow();
    void criaCubo();
    void criaEsfera();
    void criaCone();
    void criaCilindro();
    void receiver(float x);
    void  atualiza_x_position();


signals:
    void change_value(float );   
};

#endif // MAINWINDOW_H
