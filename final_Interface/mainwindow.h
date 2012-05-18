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

    void set_haste();
    void set_esfera();
    void set_cube();
    void set_cilindro();
    void set_cone();

    virtual QPaintEngine * paintEngine() const;

    void gerarMalha();

    void return_position_changed();
    void receiver_selection();

    void change_position();

    void receiver_dimesion();

    void setPainelPonto();
    void setPainelHaste();
    void setPainelCubo();
    void setPainelCone();
    void setPainelEsfera();
    void setPainelCilindro();

protected:

private:
    Ui::MainWindow *ui;
    Cena* cena;
    QVBoxLayout     layout;

signals:
    void send_to_cena_changed_position(const Pos3df& pos);
    void send_to_cena_changed_dimension(const Dim3df& dim, int eixo);
    void send_changed_dimension(nodeParam*);
};
#endif // MAINWINDOW_H
