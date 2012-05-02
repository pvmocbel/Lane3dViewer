#include "dialog_cgerais.h"
#include "ui_dialog_cgerais.h"

Dialog_CGerais::Dialog_CGerais(QWidget *parent) :
    QDialog(parent),ui(new Ui::Dialog_CGerais), delta(0), dimX_RL(0), dimY_RL(0), dimZ_RL(0)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(parser()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closer()));
}

Dialog_CGerais::~Dialog_CGerais()
{ delete ui;}

Dim3df Dialog_CGerais::getDimension() const{ return dimension;    }

float Dialog_CGerais::getDelta()const {   return delta;   }

void Dialog_CGerais::parser()
{
    dimX_RL = ui->dim_regiao_livre_x->value();
    dimY_RL = ui->dim_regiao_livre_y->value();
    dimZ_RL = ui->dim_regiao_livre_z->value();
    dimension.set(dimX_RL, dimY_RL, dimZ_RL);

    delta = ui->delta_regiao_livre->value();
    this->close();
}

void Dialog_CGerais::closer(){
    this->close();
}




