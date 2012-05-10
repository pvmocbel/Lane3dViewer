#ifndef DIALOG_CGERAIS_H
#define DIALOG_CGERAIS_H

#include<irrviewer.h>
#include <QDialog>

namespace Ui {
    class Dialog_CGerais;
}

class Dialog_CGerais : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_CGerais(QWidget *parent = 0);
    ~Dialog_CGerais();
    Dim3df getDimension() const ;
    irr::f32 getDelta() const;

private slots:
     void parser();
     void closer();

private:
    Ui::Dialog_CGerais *ui;
    Dim3df dimension;
    irr::f32 dimX_RL, dimY_RL, dimZ_RL, delta;
};

#endif // DIALOG_CGERAIS_H
