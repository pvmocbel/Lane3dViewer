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
    connect(ui->actionPonto, SIGNAL(triggered()), this, SLOT(ponto_triggered()));
    connect(ui->actionCubo, SIGNAL(triggered()), this, SLOT(cubo_triggered()));
    connect(ui->actionCone, SIGNAL(triggered()), this, SLOT(cone_triggered()));
    connect(ui->actionEsfera, SIGNAL(triggered()), this, SLOT(esfera_triggered()));
    connect(ui->actionCilindro, SIGNAL(triggered()), this, SLOT(cilindro_triggered()));


    connect(ui->position_X, SIGNAL(valueChanged(double)), this, SLOT(change_x_position(double)));
    connect(ui->position_Y, SIGNAL(valueChanged(double)), this, SLOT(change_y_position(double)));
    connect(ui->position_Z, SIGNAL(valueChanged(double)), this, SLOT(change_z_position(double)));

    connect(ui->cube_dim_X, SIGNAL(valueChanged(double)), this , SLOT(change_x_dimension(double)));
    connect(ui->cube_dim_Y, SIGNAL(valueChanged(double)), this , SLOT(change_y_dimension(double)));
    connect(ui->cube_dim_Z, SIGNAL(valueChanged(double)), this , SLOT(change_z_dimension(double)));
}

void MainWindow::return_position_changed(){
    if(cena&&cena->selectedSceneNode){
        ui->position_X->setValue(cena->selectedSceneNode->getPosition().X);
        ui->position_Y->setValue(cena->selectedSceneNode->getPosition().Y);
        ui->position_Z->setValue(cena->selectedSceneNode->getPosition().Z);
    }
}

void MainWindow::change_x_position(double x){
    if(cena && cena->selectedSceneNode) {
        Pos3df pos;
        pos.set(x,cena->selectedSceneNode->getPosition().Y, cena->selectedSceneNode->getPosition().Z);
        emit send_to_cena_changed_position(pos);
    }
}

void MainWindow::change_y_position(double y){
    if(cena && cena->selectedSceneNode){
        Pos3df pos;
        pos.set(cena->selectedSceneNode->getPosition().X, y, cena->selectedSceneNode->getPosition().Z);
        emit send_to_cena_changed_position(pos);
    }
}

void MainWindow::change_z_position(double z){
    if(cena && cena->selectedSceneNode){
        Pos3df pos;
        pos.set(cena->selectedSceneNode->getPosition().X, cena->selectedSceneNode->getPosition().Y, z);
        emit send_to_cena_changed_position(pos);
    }
}

void MainWindow::change_x_dimension(double x){
    if(cena && cena->selectedSceneNode){
        Dim3df dim;
        dim.set(x,1,1);
        qDebug()<<"value change x "<<x;
        emit send_to_cena_changed_dimension(dim);
    }
}

void MainWindow::change_y_dimension(double y){
    if(cena && cena->selectedSceneNode){
        qDebug()<<"value change y "<<y;
        Dim3df dim;
        dim.set(1,y,1);
        emit send_to_cena_changed_dimension(dim);
    }
}

void MainWindow::change_z_dimension(double z){
    if(cena && cena->selectedSceneNode){
        qDebug()<<"value change z "<<z;
        Dim3df dim;
        dim.set(1,1,z);
        emit send_to_cena_changed_dimension(dim);
    }
}

void MainWindow::receiver_dimesion(){
    if(cena && cena->selectedSceneNode){
        ui->cube_dim_X->setValue(cena->selectedSceneNode->getScale().X);
        ui->cube_dim_Y->setValue(cena->selectedSceneNode->getScale().Y);
        ui->cube_dim_Z->setValue(cena->selectedSceneNode->getScale().Z);
    }
}

void MainWindow::new_triggered()
{
    Dialog_CGerais* d = new Dialog_CGerais();

    d->show();
    d->exec();

    if (cena) return;
    cena = new Cena();

    connect(cena, SIGNAL(send_position_change()),this, SLOT(return_position_changed()));
    connect(this, SIGNAL(send_to_cena_changed_position(Pos3df)), cena, SLOT(receiver_changed_position_mainwindow(Pos3df)));

    connect(this, SIGNAL(send_to_cena_changed_dimension(Dim3df)), cena, SLOT(receiver_changed_dimension_mainwindow(Dim3df)));

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
    //ui->lineEdit_LinhaName->setText("Posio");
}

void MainWindow::rotacao_triggered()
{
    //ui->lineEdit_LinhaName->setText("Rotao");
}

void MainWindow::ponto_triggered()
{
    setPainelPonto();
    int id = cena->get_serialize_id();
    Dim3df dim;
    Pos3df pos;
    pos.set(0,0,0);
    dim.set(2, 0, 0);
    cena->insertEsfera(id ,new IrrNode(), dim, pos);
}

void MainWindow::linha_triggered()
{
    setPainelLinha();

}

void MainWindow::cubo_triggered()
{
    setPainelCubo();
    int id = cena->get_serialize_id();
    Dim3df dim;
    Pos3df pos;
    pos.set(0,0,0);
    dim.set(ui->cube_dim_X->value(), ui->cube_dim_Y->value(), ui->cube_dim_Z->value());
    cena->insertCubo(id ,new IrrNode(), dim, pos);
}

void MainWindow::cilindro_triggered()
{
    setPainelCilindro();
    int id = cena->get_serialize_id();
    Dim3df dim;
    Pos3df pos;
    pos.set(0,0,0);
    dim.set(ui->raio_cilindro->value(), ui->comprimento_cilindro->value(), 0);
    cena->insertCilindro(id ,new IrrNode(), dim, pos);
}

void MainWindow::cone_triggered()
{
    setPainelCone();
    int id = cena->get_serialize_id();
    Dim3df dim;
    Pos3df pos;
    pos.set(0,0,0);
    dim.set(ui->raio_cone->value(), ui->comprimento_cone->value(), 0);
    cena->insertCone(id ,new IrrNode(), dim, pos);
}

void MainWindow::esfera_triggered()
{
    setPainelEsfera();
    int id = cena->get_serialize_id();
    Dim3df dim;
    Pos3df pos;
    pos.set(0,0,0);
    dim.set(ui->raio_esfera->value(), 0, 0);
    cena->insertEsfera(id ,new IrrNode(), dim, pos);
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

