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
     NodeParameters *dim_aux;
     QString pe, pm, c;
     void set_selection();

public slots:
    void new_triggered();
    void open_triggered();
    void save_triggered();
    void posicao_triggered();
    void rotacao_triggered();
    void ponto_triggered();
    void linha_triggered();
    void cubo_triggered();
    void cone_triggered();
    void cilindro_triggered();
    void esfera_triggered();
    void antenna_triggered();

    void set_haste();
    void set_esfera();
    void set_cube();
    void set_cilindro();
    void set_cone();
    void set_antenna();

    void gerarMalha();

    void receiver_selection(nodeDimensions*);
    void change_position();
    void return_position_changed();

    void setPainelPonto();
    void setPainelHaste();
    void setPainelCubo();
    void setPainelEsfera();
    void setPainelCilindro();
    void setPainelCone();
    void setPainelAntenna();

protected:

private:
    Ui::MainWindow *ui;
    Cena* cena;
    QVBoxLayout     layout;

signals:
    void send_to_cena_changed_position(const Pos3df& pos);
    void send_changed_dimension(nodeParam*);
    void send_changed_material_parametros(const Vector3df&, int);
};
#endif // MAINWINDOW_H
