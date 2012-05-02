#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) , cena(0)
{
    ui->setupUi(this);
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(New_triggered()));
}

MainWindow::~MainWindow()
{
    delete ui;    
}

void MainWindow::New_triggered()
{
    Dialog_CGerais* d = new Dialog_CGerais();
    d->show();
    d->exec();
    if (cena) return;
       cena = new Cena();
       cena->resize(2048, 2048);

       ui->gridLayout->addWidget(cena, 0, 0, 2, 1 );

       cena->createIrrichtDevice();
       cena->cenaIrrlicht();
       cena->criaRegiaoAnalise(d->getDimension(), d->getDelta());
    delete d;
}

void MainWindow::Open_triggered()
{
   // ui->lineEdit_LinhaName->setText("Open");
}

void MainWindow::Save_triggered()
{
    //ui->lineEdit_LinhaName->setText("Save");
}

void MainWindow::Posicao_triggered()
{
    //ui->lineEdit_LinhaName->setText("Posição");
}

void MainWindow::Rotacao_triggered()
{
    //ui->lineEdit_LinhaName->setText("Rotação");
}

void MainWindow::Ponto_triggered()
{
    setPainelPonto();
}

void MainWindow::Linha_triggered()
{
    setPainelLinha();
}

void MainWindow::Retangulo_triggered()
{
    //ui->lineEdit_LinhaName->setText("Geom Retangulo");
}

void MainWindow::Circulo_triggered()
{
    //ui->lineEdit_LinhaName->setText("Geom Circulo");
}

void MainWindow::setPainelPonto()
{
    ui->label_PainelTitulo_1->setText("PONTO");
    ui->lineEdit_Name->setText("Ponto");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(0);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(0);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(0);
}

void MainWindow::setPainelLinha()
{
    ui->label_PainelTitulo_1->setText("LINHA");
    ui->lineEdit_Name->setText("Linha");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(122);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(122);
}

void MainWindow::setPainelCubo()
{
    ui->label_PainelTitulo_1->setText("CUBO");
    ui->lineEdit_Name->setText("Cubo");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(2);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(122);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(122);
}

void MainWindow::setPainelEsfera()
{
    ui->label_PainelTitulo_1->setText("ESFERA");
    ui->lineEdit_Name->setText("Helipse");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(3);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(122);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(122);
}

void MainWindow::setPainelCone(){

}

void MainWindow::keyPressEvent( QKeyEvent * event){
    cena->keyPressEvent(event);
}
