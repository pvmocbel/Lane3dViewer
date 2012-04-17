#include "getdimcilindro.h"
#include "ui_getdimcilindro.h"

getDimCilindro::getDimCilindro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getDimCilindro)
{
    position.set(Vector3df(0,0,0));
    dimension.set(Vector3df(0,0,0));
    ui->setupUi(this);
    connect( ui->buttonBox, SIGNAL(accepted()), this, SLOT(parser()));
    connect( ui->buttonBox, SIGNAL(rejected()), this, SLOT(abort()) );
}

getDimCilindro::~getDimCilindro()
{
    delete ui;
}

Pos3df getDimCilindro::getPosition(){ return position;}

Dim3df getDimCilindro::getDimension(){ return dimension;}

void getDimCilindro::parser()
{
    double x = ui->position_x->value();
    double y = ui->position_y->value();
    double z = ui->position_z->value();

    double lx  = ui->raio->value();
    double ly  = ui->comprimento->value();

    position = Pos3df(x,y,z);
    dimension = Dim3df(lx,ly,0);
    this->close();
}

void getDimCilindro::abort(){
     this->close();
}
