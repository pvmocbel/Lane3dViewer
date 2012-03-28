#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
     connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(init()));
    irrwindows=0;
}

MainWindow::~MainWindow(){
    delete irrwindows;
    delete ui;    
}

void MainWindow::init(){
    irrwindows = new IrrQWidget();
    irrwindows->resize(1000,1000);
    ui->gridLayout->addWidget(irrwindows);
    irrwindows->createIrrlichtDevice();
    irrwindows->buildIrrlichtScene();
    irrwindows->drawIrrlichtScene();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
