#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),cena(0)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cena;
}

void MainWindow::init()
{
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(new_triggered()));
    connect(ui->actionCubo, SIGNAL(triggered()), this, SLOT(cubo_triggered()));
    connect(ui->position_X, SIGNAL(valueChanged(double)), this, SLOT(change_x_position(double)));
    connect(ui->position_Y, SIGNAL(valueChanged(double)), this, SLOT(change_y_position(double)));
    connect(ui->position_Z, SIGNAL(valueChanged(double)), this, SLOT(change_z_position(double)));
}

void MainWindow::change_x_position(double x){
    if(cena && cena->selectedSceneNode)    cena->change_x_position(x);
}

void MainWindow::change_y_position(double y){
    if(cena && cena->selectedSceneNode)    cena->change_y_position(y);
}

void MainWindow::change_z_position(double z){
    if(cena && cena->selectedSceneNode)    cena->change_z_position(z);
}

void MainWindow::return_x_changed(float x){
    ui->position_X->setValue(x);
}

void MainWindow::return_y_changed(float y){
    ui->position_Y->setValue(y);
}

void MainWindow::return_z_changed(float z){
    ui->position_Z->setValue(z);
}

void MainWindow::new_triggered()
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

void MainWindow::open_triggered()
{
   // ui->lineEdit_LinhaName->setText("Open");
}

void MainWindow::save_triggered()
{
    //ui->lineEdit_LinhaName->setText("Save");
}

void MainWindow::posicao_triggered()
{
    //ui->lineEdit_LinhaName->setText("Posi��o");
}

void MainWindow::rotacao_triggered()
{
    //ui->lineEdit_LinhaName->setText("Rota��o");
}

void MainWindow::ponto_triggered()
{
    setPainelPonto();
}

void MainWindow::linha_triggered()
{
    setPainelLinha();
}

void MainWindow::cubo_triggered()
{
    setPainelCubo();
    Dim3df dim;
    Pos3df pos;
    pos.set(0,0,0);
    dim.set(ui->cube_dim_X->value(), ui->cube_dim_Y->value(), ui->cube_dim_Z->value());
    cena->insertCubo(new IrrNode(), dim, pos);
}

void MainWindow::cilindro_triggered()
{
    setPainelCilindro();
}

void MainWindow::cone_triggered()
{
    setPainelCone();
}

void MainWindow::esfera_triggered()
{
    setPainelEsfera();
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
    ui->label_PainelTitulo_1->setText("CONE");
    ui->lineEdit_Name->setText("Cone");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(4);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(122);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(122);
}

void MainWindow::setPainelCilindro(){
    ui->label_PainelTitulo_1->setText("CILINDRO");
    ui->lineEdit_Name->setText("Cilindro");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(5);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(122);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(122);
}


void MainWindow::keyPressEvent( QKeyEvent * event){
    cena->keyPressEvent(event);
}
