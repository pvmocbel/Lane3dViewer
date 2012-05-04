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

public slots:
    void initIrrlichtWindow();
    void criaCubo();
    void criaEsfera();
    void criaCone();
    void criaCilindro();
    void atualiza_x_position();

private:
    Ui::MainWindow *ui;
    Cena* cena;
};

#endif // MAINWINDOW_H
