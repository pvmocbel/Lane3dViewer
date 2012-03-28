#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow),
    cena(0)
{
    ui->setupUi(this);
    connect( ui->start, SIGNAL(clicked()), this, SLOT(initIrrlichtWindow()));
    connect( ui->cria_alguma_coisa, SIGNAL(clicked()), this, SLOT(criaSomenting()));
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

    ui->gridLayout->addWidget(cena, 1, 0, 3, 3);

    cena->createIrrichtDevice();
    cena->cenaIrrlicht();
}

void MainWindow::criaSomenting(){
    int id = cena->get_serialize_id();
    cena->insertNode(id,new IrrNode());
}


void MainWindow::keyPressEvent( QKeyEvent * event){
    cena->keyPressEvent(event);
}
