#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow),
    cena(0)
{
    ui->setupUi(this);
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

void MainWindow::initIrrlichtWindow(){
    if (cena) return;

    cena = new Cena();
    cena->resize(2048, 2048);

    ui->gridLayout->addWidget(cena, 1, 0, 5, 5);

    cena->createIrrichtDevice();
    cena->cenaIrrlicht();
}

void MainWindow::criaCubo(){
    cena->insertCubo(new IrrNode());
}

void MainWindow::criaEsfera(){
    cena->insertEsfera(new IrrNode());
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
