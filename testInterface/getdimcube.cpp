#include "getdimcube.h"
#include "ui_getdimcube.h"
#include <QMessageBox>

getDimCube::getDimCube(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getDimCube)
{
    ui->setupUi(this);
    ok = false;
    connect( ui->buttonBox, SIGNAL(accepted()), this, SLOT(parser()));
    connect( ui->buttonBox, SIGNAL(rejected()), this, SLOT(abort()) );
}

getDimCube::~getDimCube(){ delete ui;}

Pos3df getDimCube::getPosition(){ return position;}

Dim3df getDimCube::getDimension(){ return dimension;}

bool getDimCube::isOk(){return ok;}

void getDimCube::parser()
{
    double x = ui->position_x->value();
    double y = ui->position_y->value();
    double z = ui->position_z->value();

    double lx  = ui->dimension_x->value();
    double ly  = ui->dimension_y->value();
    double lz  = ui->dimension_z->value();

    position = Pos3df(x,y,z);
    dimension = Dim3df(lx,ly,lz);
    ok = true;
    this->close();    
}

void getDimCube::abort(){
    ok = false;
    this->close();
}
