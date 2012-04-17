#include "getdimesfera.h"
#include "ui_getdimesfera.h"

getDimEsfera::getDimEsfera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getDimEsfera)
{
    raio = 0;
    position.set(Vector3df(0,0,0));

    ui->setupUi(this);

    connect( ui->buttonBox, SIGNAL(accepted()), this, SLOT(parser()));
    connect( ui->buttonBox, SIGNAL(rejected()), this, SLOT(abort()) );
}

getDimEsfera::~getDimEsfera()
{
    delete ui;
}

Pos3df getDimEsfera::getPosition(){ return position;}

double getDimEsfera::getDimension(){ return raio;}

void getDimEsfera::parser()
{
    double x = ui->position_x->value();
    double y = ui->position_y->value();
    double z = ui->position_z->value();

    raio  = ui->raio->value();

    position = Pos3df(x, y, z);
    this->close();
}

void getDimEsfera::abort(){
    this->close();
}
