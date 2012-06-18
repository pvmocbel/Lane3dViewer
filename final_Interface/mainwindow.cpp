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


    ui->stackedWidget_Lateral->setCurrentIndex(0);
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
    if(cena&&cena->selectedSceneNode){
        const irr::c8* test = cena->selectedSceneNode->getName();
        int id = cena->getIdFromNode(test);

        dim_aux->dimension = param->dimension;
        dim_aux->dimension2 = param->dimension2;
        dim_aux->parametros = param->parametros;
        dim_aux->raio_haste = param->raio_haste;
        dim_aux->position = param->position;
        dim_aux->propriedade  = param->propriedade;
        cena->parametros(dim_aux, id);

        set_selection();        
    }
}
void MainWindow::set_selection(){
    if(cena && cena->selectedSceneNode){

    ui->position_X->setValue(dim_aux->position.X);
    ui->position_Y->setValue(dim_aux->position.Y);
    ui->position_Z->setValue(dim_aux->position.Z);

    ui->propriedade->setCurrentIndex(dim_aux->propriedade);

    pe.setNum(dim_aux->parametros.X);
    pm.setNum(dim_aux->parametros.Y);
    c.setNum(dim_aux->parametros.Z);

    ui->permissividade->setText(pe);
    ui->permeabilidade->setText(pm);
    ui->condutibilidade->setText(c);

    switch((cena->selectedSceneNode->getID()&MASK)){
         case(ID_FLAG_CUBO):
             setPainelCubo();
             cena->setFocus();

             ui->position_X->setEnabled(true);
             ui->position_Y->setEnabled(true);
             ui->position_Z->setEnabled(true);

             ui->cube_dim_X->setValue(dim_aux->dimension.X);
             ui->cube_dim_Y->setValue(dim_aux->dimension.Y);
             ui->cube_dim_Z->setValue(dim_aux->dimension.Z);
             break;

         case(ID_FLAG_ESFERA):
             setPainelEsfera();
             cena->setFocus();

             ui->position_X->setEnabled(true);
             ui->position_Y->setEnabled(true);
             ui->position_Z->setEnabled(true);

             ui->raio_esfera->setValue(dim_aux->dimension.X);
             break;

         case(ID_FLAG_CILINDRO):
             setPainelCilindro();
             cena->setFocus();

             ui->position_X->setEnabled(true);
             ui->position_Y->setEnabled(true);
             ui->position_Z->setEnabled(true);

             ui->raio_cilindro->setValue(dim_aux->dimension.X);
             ui->comprimento_cilindro->setValue(dim_aux->dimension.Y);
             break;

         case(ID_FLAG_CONE):
             setPainelCone();
             cena->setFocus();

             ui->position_X->setEnabled(true);
             ui->position_Y->setEnabled(true);
             ui->position_Z->setEnabled(true);

             ui->raio_cone->setValue(dim_aux->dimension.X);
             ui->comprimento_cone->setValue(dim_aux->dimension.Y);
             break;

         case(ID_FLAG_HASTE):
            setPainelHaste();
            cena->setFocus();

            ui->position_X->setEnabled(false);
            ui->position_Y->setEnabled(false);
            ui->position_Z->setEnabled(false);

            ui->haste_inicial_x->setValue(dim_aux->dimension.X);
            ui->haste_inicial_y->setValue(dim_aux->dimension.Y);
            ui->haste_inicial_z->setValue(dim_aux->dimension.Z);

            ui->haste_final_x->setValue(dim_aux->dimension2.X);
            ui->haste_final_y->setValue(dim_aux->dimension2.Y);
            ui->haste_final_z->setValue(dim_aux->dimension2.Z);

            ui->raio_haste->setValue(dim_aux->raio_haste);
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

    }//end if
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
        float  x, y, z;
        bool ok = false;

        x  = ui->permissividade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
           return;
        }

        Vector3df p;
        p.set(x,y,z);

        param->dimension.set(ui->haste_inicial_x->value(), ui->haste_inicial_y->value(), ui->haste_inicial_z->value());
        param->dimension2.set(ui->haste_final_x->value(), ui->haste_final_y->value(), ui->haste_final_z->value());
        param->raio_haste = ui->raio_haste->value();
        param->type = Haste;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros = p;

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_cube(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();
        float  x, y, z;
        bool ok = false;

        x  = ui->permissividade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
           return;
        }

        qDebug()<<"prop "<<ui->propriedade->currentIndex();

        Vector3df p;
        p.set(x,y,z);
        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->dimension.set(ui->cube_dim_X->value(), ui->cube_dim_Y->value(), ui->cube_dim_Z->value());
        param->type = Cube;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros = p;
        param->propriedade = ui->propriedade->currentIndex();

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_esfera(){
    if(cena && cena->selectedSceneNode){
        nodeParam *param = new nodeParam();
        float  x, y, z;
        bool ok = false;

        x  = ui->permissividade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade->text().toFloat(&ok);
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

        x  = ui->permissividade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade->text().toFloat(&ok);
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

        x  = ui->permissividade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade->text().toFloat(&ok);
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
        float  x, y, z;
        bool ok = false;

        x  = ui->permissividade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
           return;
        }

        Vector3df p;
        p.set(x,y,z);
        param->position.set(ui->position_X->value(), ui->position_Y->value(), ui->position_Z->value());
        param->type = Antenna;
        param->box = cena->selectedSceneNode->getBoundingBox();
        param->parametros = p;

        emit send_changed_dimension(param);
        delete param;
    }
}
void MainWindow::set_material_parametros(){
    if(cena->selectedSceneNode){
        QLocale::setDefault(QLocale::C);

        const irr::c8* test = cena->selectedSceneNode->getName();
        int id = cena->getIdFromNode(test);
        if(id == 0)return;

        float  x, y, z;
        bool ok = false;

        x  = ui->permissividade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
           return;
        }
        y  = ui->permeabilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
           return;
        }
        z  = ui->condutibilidade->text().toFloat(&ok);
        if(!ok){
           QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
           return;
        }

        Vector3df param;
        param.set(x,y,z);
        emit send_changed_material_parametros(param, id);
    }
}
void MainWindow::set_propriedade(){
    const irr::c8* test = cena->selectedSceneNode->getName();
    int id = cena->getIdFromNode(test);
    qDebug()<<"propriedade "<<ui->propriedade->currentIndex();
    if(id == 0)return;
    emit send_changed_propriedade(ui->propriedade->currentIndex(), id);
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

    ui->stackedWidget_Lateral->setCurrentIndex(0);

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
    float  x, y, z;
    bool ok = false;

    x  = ui->permissividade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
       return;
    }
    y  = ui->permeabilidade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
       return;
    }
    z  = ui->condutibilidade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo C tem que ser um numero real");
       return;
    }

    Vector3df p;
    p.set(x,y,z);

    param->dimension.set(ui->haste_inicial_x->value(), ui->haste_inicial_y->value(), ui->haste_inicial_z->value());
    param->dimension2.set(ui->haste_final_x->value(), ui->haste_final_y->value(), ui->haste_final_z->value());
    param->parametros = p;
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

    x  = ui->permissividade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
       return;
    }
    y  = ui->permeabilidade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
       return;
    }
    z  = ui->condutibilidade->text().toFloat(&ok);
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

    x  = ui->permissividade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
       return;
    }
    y  = ui->permeabilidade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
       return;
    }
    z  = ui->condutibilidade->text().toFloat(&ok);
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

    x  = ui->permissividade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
       return;
    }
    y  = ui->permeabilidade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
       return;
    }
    z  = ui->condutibilidade->text().toFloat(&ok);
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

    x  = ui->permissividade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.E tem que ser um numero real");
       return;
    }
    y  = ui->permeabilidade->text().toFloat(&ok);
    if(!ok){
       QMessageBox::warning(0,"Entrada Inválida","O campo P.M tem que ser um numero real");
       return;
    }
    z  = ui->condutibilidade->text().toFloat(&ok);
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
//    ui->stackedWidget_pnLateralObj->setMinimumWidth(200);
//    ui->stackedWidget_Lateral->setMinimumWidth(200);

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
void MainWindow::setPainelCilindro(){
    ui->label_PainelTitulo_1->setText("CILINDRO");
    ui->lineEdit_Name->setText("Cilindro");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(4);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(122);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(122);
}
void MainWindow::setPainelCone(){
    ui->label_PainelTitulo_1->setText("CONE");
    ui->lineEdit_Name->setText("Cone");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(5);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(122);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(122);
}
void MainWindow::setPainelAntenna(){
    ui->label_PainelTitulo_1->setText("Eye Antenna");
    ui->lineEdit_Name->setText("Eye Antenna");
    ui->stackedWidget_Lateral->setCurrentIndex(1);
    ui->stackedWidget_pnLateralObj->setCurrentIndex(6);
    ui->stackedWidget_pnLateralObj->setMinimumHeight(122);
    ui->stackedWidget_pnLateralObj->setMaximumHeight(200);
}

void MainWindow::keyPressEvent( QKeyEvent * event){
    cena->keyPressEvent(event);
    cena->setFocus();
}

