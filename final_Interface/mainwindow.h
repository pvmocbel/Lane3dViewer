#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <irrlicht.h>
#include "dialog_cgerais.h"
#include "cena.h"

class Dialog_CGerais;
class  Cena;

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
     void init();

     double va;

     virtual void paintEvent( QPaintEvent *event );
     virtual void resizeEvent( QResizeEvent *event );
     virtual QPaintEngine * paintEngine() const;

public slots:
    void new_triggered();
    void open_triggered();
    void save_triggered();

    void posicao_triggered();
    void rotacao_triggered();

    void return_position_changed();

    void change_x_position(double);
    void change_y_position(double);
    void change_z_position(double);

    void ponto_triggered();
    void linha_triggered();
    void cubo_triggered();
    void cone_triggered();
    void cilindro_triggered();
    void esfera_triggered();

    void setPainelPonto();
    void setPainelLinha();
    void setPainelCubo();
    void setPainelCone();
    void setPainelEsfera();
    void setPainelCilindro();

protected:

private:
    Ui::MainWindow *ui;
    Cena* cena;
    QVBoxLayout     layout;
};
#endif // MAINWINDOW_H
