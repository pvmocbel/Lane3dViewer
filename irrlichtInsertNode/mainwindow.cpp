#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    //-------------------------slots------------------------------//
    connect(ui->start,SIGNAL(clicked()),this,SLOT(init()));
    connect(ui->cubo,SIGNAL(clicked()),this,SLOT(cria_cubo()));
    connect(ui->linha,SIGNAL(clicked()),this,SLOT(cria_linha()));
    connect(ui->esfera,SIGNAL(clicked()),this,SLOT(cria_esfera()));
    connect(ui->cone,SIGNAL(clicked()),this,SLOT(cria_cone()));
    irrwindows = 0;
    n=0;
}

MainWindow::~MainWindow(){  delete ui;  }

void MainWindow::paintEvent( QPaintEvent *event ){
    evento=event;
    n+=1;
    qDebug() << "MainWindow::paintEvent()"<< n;
    QMainWindow::paintEvent(event);
    if(irrwindows!=0) irrwindows->paintEvent(event);
}

void MainWindow::resizeEvent(QResizeEvent *event){
    qDebug() << "QWidget::resizeEvent()";
}

void MainWindow::init(){
    irrwindows = new IrrQWidget();
    irrwindows->resize(2048,2048);
    ui->gridLayout->addWidget(irrwindows,1,1,5,6);
    irrwindows->createIrrlichtDevice();
    irrwindows->buildIrrlichtScene();
}

void MainWindow::cria_cubo(){
    irrwindows->createCubo();
}

void MainWindow::cria_linha(){
    irrwindows->createLinha();
}

void MainWindow::cria_cone(){
    irrwindows->createCone();
}

void MainWindow::cria_esfera(){
    irrwindows->createEsfera();
}
