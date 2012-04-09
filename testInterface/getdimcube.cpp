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
}

getDimCube::~getDimCube()
{
    delete ui;
}

Pos3df getDimCube::getPosition(){
    return position;
}

Dim3df getDimCube::getDimension(){
    return dimension;
}

bool getDimCube::isOk(){
    return ok;
}

void getDimCube::parser(){

    QLocale::setDefault(QLocale::C);

    float x  = ui->text_x_position->text().toFloat(&ok);
    if(!ok){
        QMessageBox::warning(0,"Entrada Inválida","O campo x tem que ser um numero real");
        return;
    }

    float y  = ui->text_y_position->text().toFloat(&ok);
    if(!ok){
        QMessageBox::warning(0,"Entrada Inválida","O campo y tem que ser um numero real");
        return;
    }
    float z  = ui->text_z_position->text().toFloat(&ok);
    if(!ok){
        QMessageBox::warning(0,"Entrada Inválida","O campo z tem que ser um numero real");
        return;
    }


    float lx  = ui->text_x_dimension->text().toFloat(&ok);
    if(!ok){
        QMessageBox::warning(0,"Entrada Inválida","O campo dimensão x tem que ser um numero real");
        return;
    }
    float ly  = ui->text_y_dimension->text().toFloat(&ok);
    if(!ok){
        QMessageBox::warning(0,"Entrada Inválida","O campo dimensão y tem que ser um numero real");
        return;
    }
    float lz  = ui->text_z_dimension->text().toFloat(&ok);
    if(!ok){
        QMessageBox::warning(0,"Entrada Inválida","O campo dimensão z tem que ser um numero real");
        return;
    }

    position = Pos3df(x,y,z);
    dimension = Dim3df(lx,ly,lz);
    this->close();
}

void getDimCube::abort(){
    ok = false;
    this->close();
}
