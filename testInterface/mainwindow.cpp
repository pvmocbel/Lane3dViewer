#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow),
    cena(0)
{
    ui->setupUi(this);
    val = 0;

    connect( ui->start, SIGNAL(clicked()), this, SLOT(initIrrlichtWindow()));
    connect( ui->cubo, SIGNAL(clicked()), this, SLOT(criaCubo()));
    connect( ui->esfera, SIGNAL(clicked()), this, SLOT(criaEsfera()));
    connect( ui->cone, SIGNAL(clicked()), this, SLOT(criaCone()));
    connect( ui->cilindro, SIGNAL(clicked()), this, SLOT(criaCilindro()));


}

MainWindow::~MainWindow()
{
    delete ui;
    if (cena) {
        delete cena;
    }
}

void MainWindow::atualiza_x_position()
{
    if(cena && cena->selectedSceneNode){
        qDebug()<<"position x"<<cena->selectedSceneNode->getPosition().X;
        ui->position_x->setValue(cena->selectedSceneNode->getPosition().X);
    }

}

void MainWindow::initIrrlichtWindow(){
    if (cena) return;

    cena = new Cena();
    cena->resize(2048, 2048);
    connect(cena, SIGNAL(send_x_changed()),this, SLOT(atualiza_x_position()));

    ui->gridLayout->addWidget(cena, 2, 1, 5, 10 );

    cena->createIrrichtDevice();
    cena->cenaIrrlicht();
}

void MainWindow::criaCubo(){
    cena->insertCubo(new IrrNode());
//    ui->position_x->setValue(val);
}

void MainWindow::criaEsfera(){
    atualiza_x_position();

}

void MainWindow::criaCone(){
    cena->insertCone(new IrrNode());
}

void MainWindow::criaCilindro(){
    cena->insertCilindro(new IrrNode());
}

void MainWindow::keyPressEvent( QKeyEvent * event){
    cena->keyPressEvent(event);
}
