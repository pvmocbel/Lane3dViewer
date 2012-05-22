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
    connect(ui->actionLinha, SIGNAL(triggered()), this , SLOT(linha_triggered()));
    connect(ui->actionCone, SIGNAL(triggered()), this, SLOT(cone_triggered()));
    connect(ui->actionEsfera, SIGNAL(triggered()), this, SLOT(esfera_triggered()));
    connect(ui->actionCilindro, SIGNAL(triggered()), this, SLOT(cilindro_triggered()));
}
void MainWindow::gerarMalha(){
    if(cena){
        cena->geraMalha();
    }
}
void MainWindow::return_position_changed(){
    if(cena&&cena->selectedSceneNode){
        ui->position_X->setValue(cena->selectedSceneNode->getPosition().X);
        ui->position_Y->setValue(cena->selectedSceneNode->getPosition().Y);
        ui->position_Z->setValue(cena->selectedSceneNode->getPosition().Z);
    }
}
void MainWindow::change_position(){
    if(cena && cena->selectedSceneNode){
        Pos3df pos ;
        pos.set(ui->position_X->value(),ui->position_Y->value(),ui->position_Z->value());
        emit send_to_cena_changed_position(pos);
    }
}
void MainWindow::receiver_selection(const Vector3df &dim){
    if(cena && cena->selectedSceneNode){

        ui->position_X->setValue(cena->selectedSceneNode->getPosition().X);
        ui->position_Y->setValue(cena->selectedSceneNode->getPosition().Y);
        ui->position_Z->setValue(cena->selectedSceneNode->getPosition().Z);

        switch((cena->selectedSceneNode->getID()&MASK)){
             case(ID_FLAG_CUBO):
                 setPainelCubo();
                 cena->setFocus();
                 ui->cube_dim_X->setValue(dim.X);
                 ui->cube_dim_Y->setValue(dim.Y);
                 ui->cube_dim_Z->setValue(dim.Z);
                 break;

             case(ID_FLAG_ESFERA):
                 setPainelEsfera();
                 cena->setFocus();
                 ui->raio_esfera->setValue(dim.X);
                 break;

             case(ID_FLAG_CILINDRO):
                 setPainelCilindro();
                 cena->setFocus();
                 ui->raio_cilindro->setValue(dim.X);
                 ui->comprimento_cilindro->setValue(dim.Y);
                 break;

             case(ID_FLAG_CONE):
                 setPainelCone();
                 cena->setFocus();
                 ui->raio_cone->setValue(dim.X);
                 ui->comprimento_cone->setValue(dim.Y);
                 break;

             case(ID_FLAG_HASTE):
                setPainelHaste();
                cena->setFocus();
                ui->haste_final_x->setValue(dim.X);
                ui->haste_final_y->setValue(dim.Y);
                ui->haste_final_z->setValue(dim.Z);
                break;

             case(ID_FLAG_PONTO):
                setPainelPonto();
                cena->setFocus();
                break;
         }
    }
}
void MainWindow::receiver_dimesion(){
    if(cena && cena->selectedSceneNode){
        ui->cube_dim_X->setValue(cena->selectedSceneNode->getScale().X);
        ui->cube_dim_Y->setValue(cena->selectedSceneNode->getScale().Y);
        ui->cube_dim_Z->setValue(cena->selectedSceneNode->getScale().Z);
    }
}

void MainWindow::set_haste(){
    if(cena && (cena->selectedSceneNode)){
        nodeParam *param = new nodeParam();

        param->position.set(ui->haste_inicial_x->value(), ui->haste_inicial_y->value(), ui->haste_inicial_z->value());
        param->dimension.set(ui->haste_final_x->value(), ui->haste_final_y->value(), ui->haste_final_z->value());
        param->type = Haste;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_cube(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();

        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->dimension.set(ui->cube_dim_X->value(), ui->cube_dim_Y->value(), ui->cube_dim_Z->value());
        param->type = Cube;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_esfera(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();

        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->dimension.set(ui->raio_esfera->value(), 0, 0);
        param->type = Esphere;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_cilindro(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();

        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->dimension.set(ui->raio_cilindro->value(), ui->comprimento_cilindro->value(), 0);
        param->type = Cilindro;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_cone(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();

        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->dimension.set(ui->raio_cone->value(), ui->comprimento_cone->value(), 0);
        param->type = Cone;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());

        emit send_changed_dimension(param);
        delete param;
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
    connect(cena, SIGNAL(send_selection_call(Vector3df)), this, SLOT(receiver_selection(Vector3df)));
    connect(this, SIGNAL(send_changed_dimension(nodeParam*)), cena, SLOT(receiver_changed_dimension(nodeParam*)));

    cena->resize(2048, 2048);
    ui->grid_Interface->addWidget(cena, 0, 0);
    cena->setFocus(Qt::MouseFocusReason);
    ui->centralWidget->setFocus(Qt::MouseFocusReason);
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
    /*int id = cena->get_serialize_id();

    Vector3df p ;
    p.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());

    cena->insert(id, new IrrNode(), p)*/;
}
void MainWindow::linha_triggered()
{
    setPainelHaste();
    int id = cena->get_serialize_id();
    nodeParam *param = new nodeParam();

    param->position.set(ui->haste_inicial_x->value(), ui->haste_inicial_y->value(), ui->haste_inicial_z->value());
    param->dimension.set(ui->haste_final_x->value(), ui->haste_final_y->value(), ui->haste_final_z->value());
    param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());
    param->type = Haste;

    cena->insertHaste(id, new IrrNode(), param);
    delete param;
}
void MainWindow::cubo_triggered()
{
    setPainelCubo();
    int id = cena->get_serialize_id();
    nodeParam *param = new nodeParam();

    param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
    param->dimension.set(ui->cube_dim_X->value(), ui->cube_dim_Y->value(), ui->cube_dim_Z->value());
    param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());
    param->type = Cube;

    cena->insertCubo(id, new IrrNode(), param);
    delete param;
}
void MainWindow::esfera_triggered()
{
    setPainelEsfera();
    int id = cena->get_serialize_id();
    nodeParam *param = new nodeParam();

    param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
    param->dimension.set(ui->raio_esfera->value(), 0, 0);
    param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());
    param->type = Esphere;

    cena->insertEsfera(id, new IrrNode(), param);
    delete param;
}
void MainWindow::cilindro_triggered()
{
    setPainelCilindro();
    int id = cena->get_serialize_id();
    nodeParam *param = new nodeParam();

    param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
    param->dimension.set(ui->raio_cilindro->value(), ui->comprimento_cilindro->value(), 0);
    param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());
    param->type = Cilindro;

    cena->insertCilindro(id ,new IrrNode(), param);
    delete param;
}
void MainWindow::cone_triggered()
{
    setPainelCone();
    int id = cena->get_serialize_id();
    nodeParam *param = new nodeParam();

    param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
    param->dimension.set(ui->raio_cone->value(), ui->comprimento_cone->value(), 0);
    param->parametros.set(ui->permissividade->value(), ui->permeabilidade->value(), ui->condutibilidade->value());
    param->type = Cone;

    cena->insertCone(id, new IrrNode(), param);
    delete param;
}

void MainWindow::setPainelPonto()
{
    ui->label_PainelTitulo_1->setText("PONTO");
    ui->lineEdit_Name->setText("Ponto");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(0);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(0);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(0);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(122);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(122);
}
void MainWindow::setPainelHaste()
{
    ui->label_PainelTitulo_1->setText("Haste");
    ui->lineEdit_Name->setText("Haste");

    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(230);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(230);

    ui->haste_inicial_x->setMinimumWidth(62);
    ui->haste_inicial_y->setMinimumWidth(62);
    ui->haste_inicial_z->setMinimumWidth(62);

    ui->haste_final_x->setMinimumWidth(62);
    ui->haste_final_y->setMinimumWidth(62);
    ui->haste_final_z->setMinimumWidth(62);
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
    cena->setFocus();
}

