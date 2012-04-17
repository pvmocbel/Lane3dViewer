#include "getdimcone.h"
#include "ui_getdimcone.h"

getDimCone::getDimCone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getDimCone)
{
    position.set(Vector3df(0,0,0));
    dimension.set(Vector3df(0,0,0));
    ui->setupUi(this);
    connect( ui->buttonBox, SIGNAL(accepted()), this, SLOT(parser()));
    connect( ui->buttonBox, SIGNAL(rejected()), this, SLOT(abort()) );
}

getDimCone::~getDimCone()
{
    delete ui;
}

Pos3df getDimCone::getPosition(){ return position;}

Dim3df getDimCone::getDimension(){ return dimension;}

void getDimCone::parser()
{
    double x = ui->position_x->value();
    double y = ui->position_y->value();
    double z = ui->position_z->value();

    double altura  = ui->altura->value();
    double raio  = ui->raio->value();
    double lz  = 0;

    position = Pos3df(x,y,z);
    dimension = Dim3df(altura,raio,lz);
    this->close();
}

void getDimCone::abort(){
       this->close();
}
