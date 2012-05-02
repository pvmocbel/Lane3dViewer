#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <irrlicht.h>
#include "dialog_cgerais.h"
#include "cena.h"

class Dialog_CGerais;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void keyPressEvent( QKeyEvent * event);

private slots:
    void New_triggered();
    void Open_triggered();
    void Save_triggered();

    void Posicao_triggered();
    void Rotacao_triggered();

    void Ponto_triggered();
    void Linha_triggered();
    void Retangulo_triggered();
    void Circulo_triggered();

    void setPainelPonto();
    void setPainelLinha();
    void setPainelCubo();
    void setPainelCone();
    void setPainelEsfera();

protected:

private:
    Ui::MainWindow *ui;
    Cena* cena;
    QVBoxLayout     layout;    
};
#endif // MAINWINDOW_H
