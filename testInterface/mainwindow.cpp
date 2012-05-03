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

void MainWindow::receiver(float x){
    val = (double)x;
    qDebug()<<"val = "<<val;
    atualiza_x_position();
}

void MainWindow::atualiza_x_position()
{
//    val = 2.694;
    ui->position_x->setValue((double)(val));
}

void MainWindow::initIrrlichtWindow(){
    if (cena) return;

    cena = new Cena();
    cena->resize(2048, 2048);

    ui->gridLayout->addWidget(cena, 2, 1, 5, 10 );

    cena->createIrrichtDevice();
    cena->cenaIrrlicht();
}

void MainWindow::criaCubo(){
    cena->insertCubo(new IrrNode());
//    ui->position_x->setValue(val);
}

void MainWindow::criaEsfera(){
//    cena->insertEsfera(new IrrNode());
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
