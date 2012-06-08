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
    dim_aux = new NodeParameters;
    dim_aux->dimension.set(0,0,0);
    dim_aux->dimension2.set(0,0,0);
    dim_aux->parametros.set(0,0,0);
    dim_aux->position.set(0,0,0);


    ui->painel_lateral->setCurrentIndex(0);
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(new_triggered()));
    connect(ui->actionSave, SIGNAL(triggered()), this , SLOT(save_triggered()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open_triggered()));
    connect(ui->actionPonto, SIGNAL(triggered()), this, SLOT(ponto_triggered()));
    connect(ui->actionCubo, SIGNAL(triggered()), this, SLOT(cubo_triggered()));
    connect(ui->actionLinha, SIGNAL(triggered()), this , SLOT(linha_triggered()));
    connect(ui->actionCone, SIGNAL(triggered()), this, SLOT(cone_triggered()));
    connect(ui->actionEsfera, SIGNAL(triggered()), this, SLOT(esfera_triggered()));
    connect(ui->actionCilindro, SIGNAL(triggered()), this, SLOT(cilindro_triggered()));
    connect(ui->actionEyeAntenna, SIGNAL(triggered()), this , SLOT(antenna_triggered()));
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

void MainWindow::receiver_selection(nodeDimensions* param){
    if(cena&&cena->MoveSceneNode){

    ui->position_X->setValue(param->position.X);
    ui->position_Y->setValue(param->position.Y);
    ui->position_Z->setValue(param->position.Z);

    switch((cena->MoveSceneNode->getID()&MASK)){
         case(ID_FLAG_CUBO):
             setPainelCubo();
             cena->setFocus();

             ui->position_X->setEnabled(true);
             ui->position_Y->setEnabled(true);
             ui->position_Z->setEnabled(true);

             pe.setNum(param->parametros.X);
             pm.setNum(param->parametros.Y);
             c.setNum(param->parametros.Z);

             ui->permissividade_cubo->setText(pe);
             ui->permeabilidade_cubo->setText(pm);
             ui->condutibilidade_cubo->setText(c);

             ui->cube_dim_X->setValue(param->dimension.X);
             ui->cube_dim_Y->setValue(param->dimension.Y);
             ui->cube_dim_Z->setValue(param->dimension.Z);
             break;

         case(ID_FLAG_ESFERA):
             setPainelEsfera();
             cena->setFocus();

             ui->position_X->setEnabled(true);
             ui->position_Y->setEnabled(true);
             ui->position_Z->setEnabled(true);

             pe.setNum(param->parametros.X);
             pm.setNum(param->parametros.Y);
             c.setNum(param->parametros.Z);

             ui->permissividade_esfera->setText(pe);
             ui->permeabilidade_esfera->setText(pm);
             ui->condutibilidade_esfera->setText(c);

             ui->raio_esfera->setValue(param->dimension.X);
             break;

         case(ID_FLAG_CILINDRO):
             setPainelCilindro();
             cena->setFocus();

             ui->position_X->setEnabled(true);
             ui->position_Y->setEnabled(true);
             ui->position_Z->setEnabled(true);

             pe.setNum(param->parametros.X);
             pm.setNum(param->parametros.Y);
             c.setNum(param->parametros.Z);

             ui->permissividade_cilindro->setText(pe);
             ui->permeabilidade_cilindro->setText(pm);
             ui->condutibilidade_cilindro->setText(c);

             ui->raio_cilindro->setValue(param->dimension.X);
             ui->comprimento_cilindro->setValue(param->dimension.Y);
             break;

         case(ID_FLAG_CONE):
             setPainelCone();
             cena->setFocus();

             ui->position_X->setEnabled(true);
             ui->position_Y->setEnabled(true);
             ui->position_Z->setEnabled(true);

             pe.setNum(param->parametros.X);
             pm.setNum(param->parametros.Y);
             c.setNum(param->parametros.Z);

             ui->permissividade_cone->setText(pe);
             ui->permeabilidade_cone->setText(pm);
             ui->condutibilidade_cone->setText(c);

             ui->raio_cone->setValue(param->dimension.X);
             ui->comprimento_cone->setValue(param->dimension.Y);
             break;

         case(ID_FLAG_HASTE):
            setPainelHaste();
            cena->setFocus();

            ui->position_X->setEnabled(false);
            ui->position_Y->setEnabled(false);
            ui->position_Z->setEnabled(false);

            ui->haste_inicial_x->setValue(param->dimension.X);
            ui->haste_inicial_y->setValue(param->dimension.Y);
            ui->haste_inicial_z->setValue(param->dimension.Z);

            ui->haste_final_x->setValue(param->dimension2.X);
            ui->haste_final_y->setValue(param->dimension2.Y);
            ui->haste_final_z->setValue(param->dimension2.Z);

            ui->raio_haste->setValue(param->raio_haste);
            break;

         case(ID_FLAG_PONTO):
            setPainelPonto();
            cena->setFocus();

            break;

        case(ID_FLAG_ANTENNA):
            setPainelAntenna();
            cena->setFocus();

            ui->position_X->setEnabled(true);
            ui->position_Y->setEnabled(true);
            ui->position_Z->setEnabled(true);
            break;
     }

    }
}

void MainWindow::set_haste(){
    if(cena && (cena->selectedSceneNode)){
        nodeParam *param = new nodeParam();

//        if(ui->haste_inicial_x->value() != ui->haste_final_x->value()){
//            if(ui->haste_inicial_x->value()>ui->haste_final_x->value()){
//                float aux = ui->haste_final_x->value();
//                ui->haste_final_x->setValue(ui->haste_inicial_x->value());
//                ui->haste_inicial_x->setValue(aux);
//            }
//            if(ui->haste_inicial_y->value() != ui->haste_final_y->value())
//                ui->haste_final_y->setValue(ui->haste_inicial_y->value());
//            if(ui->haste_inicial_z->value() != ui->haste_final_z->value())
//                ui->haste_final_z->setValue(ui->haste_inicial_z->value());
//        }
//        else if (ui->haste_inicial_y->value() != ui->haste_final_y->value()){
//            if(ui->haste_inicial_y->value()>ui->haste_final_y->value()){
//                float aux = ui->haste_final_y->value();
//                ui->haste_final_y->setValue(ui->haste_inicial_y->value());
//                ui->haste_inicial_y->setValue(aux);
//            }
//            if(ui->haste_inicial_x->value() != ui->haste_final_x->value())
//                ui->haste_final_x->setValue(ui->haste_inicial_x->value());
//            if(ui->haste_inicial_z->value() != ui->haste_final_z->value())
//                ui->haste_final_z->setValue(ui->haste_inicial_z->value());
//        }
//        else if(ui->haste_inicial_z->value() != ui->haste_final_z->value()){
//            if(ui->haste_inicial_z->value()>ui->haste_final_z->value()){
//                float aux = ui->haste_final_z->value();
//                ui->haste_final_z->setValue(ui->haste_inicial_z->value());
//                ui->haste_inicial_z->setValue(aux);
//            }
//            if(ui->haste_inicial_x->value() != ui->haste_final_x->value())
//                ui->haste_final_x->setValue(ui->haste_inicial_x->value());
//            if(ui->haste_inicial_y->value() != ui->haste_final_y->value())
//                ui->haste_final_y->setValue(ui->haste_inicial_y->value());
//        }

        param->dimension.set(ui->haste_inicial_x->value(), ui->haste_inicial_y->value(), ui->haste_inicial_z->value());
        param->dimension2.set(ui->haste_final_x->value(), ui->haste_final_y->value(), ui->haste_final_z->value());
        param->raio_haste = ui->raio_haste->value();
        param->type = Haste;
        param->box = cena->selectedSceneNode->getBoundingBox();

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_cube(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();
        float  x, y, z;
        bool ok = false;

        x  = ui->permissividade_cubo->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade_cubo->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade_cubo->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
           return;
        }

        Vector3df p;
        p.set(x,y,z);
        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->dimension.set(ui->cube_dim_X->value(), ui->cube_dim_Y->value(), ui->cube_dim_Z->value());
        param->type = Cube;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros = p;

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_esfera(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();
        float  x, y, z;
        bool ok = false;

        x  = ui->permissividade_esfera->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade_esfera->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade_esfera->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
           return;
        }

        Vector3df p;
        p.set(x,y,z);
        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->dimension.set(ui->raio_esfera->value(), 0, 0);
        param->type = Esphere;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros = p;

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_cilindro(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();
        float  x, y, z;
        bool ok = false;

        x  = ui->permissividade_cilindro->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade_cilindro->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade_cilindro->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
           return;
        }

        Vector3df p;
        p.set(x,y,z);
        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->dimension.set(ui->raio_cilindro->value(), ui->comprimento_cilindro->value(), 0);
        param->type = Cilindro;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros = p;

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_cone(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();
        float  x, y, z;
        bool ok = false;

        x  = ui->permissividade_cone->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade_cone->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade_cone->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
           return;
        }

        Vector3df p;
        p.set(x,y,z);
        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->dimension.set(ui->raio_cone->value(), ui->comprimento_cone->value(), 0);
        param->type = Cone;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros = p;

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_antenna(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();

        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->type = Antenna;
        param->box = cena->selectedSceneNode->getBoundingBox();

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
    connect(cena, SIGNAL(send_selection_call(nodeDimensions*)), this, SLOT(receiver_selection(nodeDimensions*)));
    connect(this, SIGNAL(send_changed_dimension(nodeParam*)), cena, SLOT(receiver_changed_dimension(nodeParam*)));
    connect(this, SIGNAL(send_changed_material_parametros(Vector3df, int)), cena, SLOT(receiver_changed_material_parameter(Vector3df,int)));

    cena->resize(2048, 2048);
    ui->grid_Interface->addWidget(cena, 0, 0);
    cena->setFocus(Qt::MouseFocusReason);

    cena->createIrrichtDevice();
    cena->cenaIrrlicht();
    cena->criaRegiaoAnalise(d->getDimension(), d->getDelta());

//-------------------position------------------------//
    ui->position_X->setMinimum(0);
    ui->position_Y->setMinimum(0);
    ui->position_Z->setMinimum(0);

    ui->position_X->setSingleStep(d->delta);
    ui->position_Y->setSingleStep(d->delta);
    ui->position_Z->setSingleStep(d->delta);

//-------------------haste------------------------//
    ui->raio_haste->setMinimum(d->delta/10);
    ui->raio_haste->setSingleStep(d->delta);

    ui->haste_inicial_x->setMinimum(0);
    ui->haste_inicial_x->setSingleStep(d->delta);
    ui->haste_inicial_y->setMinimum(0);
    ui->haste_inicial_y->setSingleStep(d->delta);
    ui->haste_inicial_z->setMinimum(0);
    ui->haste_inicial_z->setSingleStep(d->delta);

    ui->haste_final_x->setMaximum(d->dimension.X);
    ui->haste_final_x->setSingleStep(d->delta);
    ui->haste_final_y->setMaximum(d->dimension.Y);
    ui->haste_final_y->setSingleStep(d->delta);
    ui->haste_final_z->setMaximum(d->dimension.Z);
    ui->haste_final_z->setSingleStep(d->delta);

//-------------------cube------------------------//
    ui->cube_dim_X->setMinimum(d->delta);
    ui->cube_dim_X->setSingleStep(d->delta);
    ui->cube_dim_Y->setMinimum(d->delta);
    ui->cube_dim_Y->setSingleStep(d->delta);
    ui->cube_dim_Z->setMinimum(d->delta);
    ui->cube_dim_Z->setSingleStep(d->delta);

//-------------------cilindro------------------------//
    ui->raio_cilindro->setSingleStep(d->delta*4);
    ui->comprimento_cilindro->setMinimum(d->delta);
    ui->comprimento_cilindro->setSingleStep(d->delta);

 //-------------------cone------------------------//
    ui->raio_cone->setMinimum(d->delta*4);
    ui->raio_cone->setSingleStep(d->delta);
    ui->comprimento_cone->setMinimum(d->delta);
    ui->comprimento_cone->setSingleStep(d->delta);

  //-------------------esfera------------------------//
    ui->raio_esfera->setMinimum(d->delta*4);
    ui->raio_esfera->setSingleStep(d->delta);

    ui->painel_lateral->setCurrentIndex(0);

    delete d;
}
void MainWindow::open_triggered()
{
   cena->load();
}
void MainWindow::save_triggered()
{
    cena->save();
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

    param->dimension.set(ui->haste_inicial_x->value(), ui->haste_inicial_y->value(), ui->haste_inicial_z->value());
    param->dimension2.set(ui->haste_final_x->value(), ui->haste_final_y->value(), ui->haste_final_z->value());
    param->type = Haste;
    param->raio_haste = ui->raio_haste->value();

    ui->position_X->setEnabled(false);
    ui->position_Y->setEnabled(false);
    ui->position_Z->setEnabled(false);
    cena->insertHaste(id, new IrrNode(), param);
    delete param;
}
void MainWindow::cubo_triggered()
{
    setPainelCubo();
    int id = cena->get_serialize_id();
    nodeParam *param = new nodeParam();

    float  x, y, z;
    bool ok = false;

    x  = ui->permissividade_cubo->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
       return;
    }
    y  = ui->permeabilidade_cubo->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
       return;
    }
    z  = ui->condutibilidade_cubo->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
       return;
    }

    Vector3df p;
    p.set(x,y,z);

    ui->position_X->setEnabled(true);
    ui->position_Y->setEnabled(true);
    ui->position_Z->setEnabled(true);
    param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
    param->dimension.set(ui->cube_dim_X->value(), ui->cube_dim_Y->value(), ui->cube_dim_Z->value());
    param->parametros = p;
    param->type = Cube;

    cena->insertCubo(id, new IrrNode(), param);
    delete param;
}
void MainWindow::esfera_triggered()
{
    setPainelEsfera();
    int id = cena->get_serialize_id();
    nodeParam *param = new nodeParam();

    float  x, y, z;
    bool ok = false;

    x  = ui->permissividade_esfera->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
       return;
    }
    y  = ui->permeabilidade_esfera->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
       return;
    }
    z  = ui->condutibilidade_esfera->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
       return;
    }

    Vector3df p;
    p.set(x,y,z);

    ui->position_X->setEnabled(true);
    ui->position_Y->setEnabled(true);
    ui->position_Z->setEnabled(true);
    param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
    param->dimension.set(ui->raio_esfera->value(), 0, 0);
    param->parametros = p;
    param->type = Esphere;

    cena->insertEsfera(id, new IrrNode(), param);
    delete param;
}
void MainWindow::cilindro_triggered()
{
    setPainelCilindro();
    int id = cena->get_serialize_id();
    nodeParam *param = new nodeParam();

    float  x, y, z;
    bool ok = false;

    x  = ui->permissividade_cilindro->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
       return;
    }
    y  = ui->permeabilidade_cilindro->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
       return;
    }
    z  = ui->condutibilidade_cilindro->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
       return;
    }

    Vector3df p;
    p.set(x,y,z);

    ui->position_X->setEnabled(true);
    ui->position_Y->setEnabled(true);
    ui->position_Z->setEnabled(true);
    param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
    param->dimension.set(ui->raio_cilindro->value(), ui->comprimento_cilindro->value(), 0);
    param->parametros = p;
    param->type = Cilindro;

    cena->insertCilindro(id ,new IrrNode(), param);
    delete param;
}
void MainWindow::cone_triggered()
{
    setPainelCone();
    int id = cena->get_serialize_id();
    nodeParam *param = new nodeParam();

    float  x, y, z;
    bool ok = false;

    x  = ui->permissividade_cone->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
       return;
    }
    y  = ui->permeabilidade_cone->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
       return;
    }
    z  = ui->condutibilidade_cone->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
       return;
    }

    Vector3df p;
    p.set(x,y,z);

    ui->position_X->setEnabled(true);
    ui->position_Y->setEnabled(true);
    ui->position_Z->setEnabled(true);
    param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
    param->dimension.set(ui->raio_cone->value(), ui->comprimento_cone->value(), 0);
    param->parametros = p;
    param->type = Cone;

    cena->insertCone(id, new IrrNode(), param);
    delete param;
}
void MainWindow::antenna_triggered(){
    setPainelAntenna();
    int id = cena->get_serialize_id();

    ui->position_X->setEnabled(true);
    ui->position_Y->setEnabled(true);
    ui->position_Z->setEnabled(true);

    Vector3df position(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());

    cena->insertAntenna(id, new IrrNode(), position);
}

void MainWindow::setPainelPonto()
{
    ui->label_PainelTitulo_1->setText("PONTO");
    ui->lineEdit_Name->setText("Ponto");
    ui->painel_lateral->setCurrentIndex(1);
    ui->painel_objetos->setCurrentIndex(0);
    ui->painel_objetos->setMinimumHeight(0);
    ui->painel_objetos->setMaximumHeight(0);
    ui->painel_objetos->setMinimumHeight(122);
    ui->painel_objetos->setMaximumHeight(122);
}
void MainWindow::setPainelHaste()
{
    ui->label_PainelTitulo_1->setText("Haste");
    ui->lineEdit_Name->setText("Haste");

    ui->painel_lateral->setCurrentIndex(1);
    ui->painel_objetos->setMinimumHeight(600);
    ui->painel_objetos->setCurrentIndex(1);
    ui->painel_objetos->setMinimumHeight(230);
    ui->painel_objetos->setMaximumHeight(230);

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
    ui->painel_lateral->setCurrentIndex(1);
    ui->painel_objetos->setCurrentIndex(2);
    ui->painel_objetos->setMinimumHeight(200);
    ui->painel_objetos->setMaximumHeight(400);
}
void MainWindow::setPainelEsfera()
{
    ui->label_PainelTitulo_1->setText("ESFERA");
    ui->lineEdit_Name->setText("Helipse");
    ui->painel_lateral->setCurrentIndex(1);
    ui->painel_objetos->setCurrentIndex(3);
    ui->painel_objetos->setMinimumHeight(600);
    ui->painel_objetos->setMaximumHeight(600);
}
void MainWindow::setPainelCilindro(){
    ui->label_PainelTitulo_1->setText("CILINDRO");
    ui->lineEdit_Name->setText("Cilindro");
    ui->painel_lateral->setCurrentIndex(1);
    ui->painel_objetos->setCurrentIndex(4);
    ui->painel_objetos->setMinimumHeight(600);
    ui->painel_objetos->setMaximumHeight(600);
}
void MainWindow::setPainelCone(){
    ui->label_PainelTitulo_1->setText("CONE");
    ui->lineEdit_Name->setText("Cone");
    ui->painel_lateral->setCurrentIndex(1);
    ui->painel_objetos->setCurrentIndex(5);
    ui->painel_objetos->setMinimumHeight(600);
    ui->painel_objetos->setMaximumHeight(600);
}
void MainWindow::setPainelAntenna(){
    ui->label_PainelTitulo_1->setText("Eye Antenna");
    ui->lineEdit_Name->setText("Eye Antenna");
    ui->painel_lateral->setCurrentIndex(1);
    ui->painel_objetos->setCurrentIndex(6);
    ui->painel_objetos->setMinimumHeight(122);
    ui->painel_objetos->setMaximumHeight(200);
}

void MainWindow::keyPressEvent( QKeyEvent * event){
    cena->keyPressEvent(event);
    cena->setFocus();
}

