#include "cena.h"

Cena::Cena():IrrViewer(0),light(0),mouse_key_test(false),
    selectedSceneNode(0),collMan(0),duplicateNode_mouse_key(false),
    mouseXi(0),mouseYi(0),dx(0),dy(0),MoveSceneNode(0),aproxima(0.1),afasta(0.1)
{
    init();
}

Cena::~Cena(){}

void Cena::init(){
    camera = 0;

    camera_01 = false;
    camera_02 = false;
    camera_03 = false;
    camera_04 = false;
    camera_05 = false;
    camera_06 = false;

    dim.set(0,0,0);

    mouse_press_position.set(0,0,0);
    mouse_release_position.set(0,0,0);

    key_m_on = false;
    key_x_on = false;
    key_y_on = false;
    key_z_on = false;

    xi = 0;
    yi = 0;
    zi = 0;

    box.MinEdge.set(0,0,0);
    box.MaxEdge.set(0,0,0);

    r_analise_gizmo_X = 0;
    r_analise_gizmo_Y = 0;
    r_analise_gizmo_Z = 0;

    gizmo_X = 0;
    gizmo_Y = 0;
    gizmo_Z = 0;
}
void Cena::cenaIrrlicht()
{
    if (smgr) {
        collMan = smgr->getSceneCollisionManager();
        cenaCameras();
        cenaIluminacao();
        gizmo();
        emit send_dimension();
        drawIrrlichtScene();
    }
}
void Cena::cenaCameras(){
    if (smgr) {
        camera = smgr->addCameraSceneNode();
        camera->setPosition(Vector3df(0,0,(box.MinEdge.Z-0.9)));
        camera->setTarget(Vector3df(0,0,0));
        camera_01 = true;
        smgr->setActiveCamera(camera);
    }
}
void Cena::cenaIluminacao(){
    if (smgr) {
        light = smgr->addLightSceneNode();
        light->setLightType( irr::video::ELT_DIRECTIONAL );
        light->setRotation( irr::core::vector3df( 45.0f, 45.0f, 0.0f ));
        light->getLightData().AmbientColor = irr::video::SColorf( 0.2f, 0.2f, 0.2f, 1.0f );
        light->getLightData().DiffuseColor = irr::video::SColorf( 0.8f, 0.8f, 0.8f, 1.0f );
    }
}

void Cena::criaRegiaoAnalise(const Dim3df& dim, double delta){
    if(smgr)
    {
        IrrNode* node = new IrrNode();

        this->dim = dim;
        this->delta = delta;

        box.MinEdge.set(-(irr::f32)(dim.X*0.5),
                        -(irr::f32)(dim.Y*0.5),
                        -(irr::f32)(dim.Z*0.5));

        box.MaxEdge.set((irr::f32)(dim.X*0.5),
                        (irr::f32)(dim.Y*0.5),
                        (irr::f32)(dim.Z*0.5));

        node->gizmosRegiaoAnalise(smgr, &r_analise_gizmo_X, &r_analise_gizmo_Y, &r_analise_gizmo_Z, dim);

        drawIrrlichtScene();
        delete node;
    }
}
void Cena::printRegiaoAnalise(irr::core::aabbox3df box){
    if((video_driver) &&
       (box.MinEdge.X !=0) && (box.MinEdge.Y !=0) &&(box.MinEdge.Z !=0) &&
       (box.MaxEdge.X !=0) && (box.MaxEdge.Y !=0) &&(box.MaxEdge.Z !=0) )
    {
        video_driver->setTransform( irr::video::ETS_WORLD, irr::core::matrix4());
        irr::video::SMaterial mat;
        mat.Lighting = false;

        video_driver->setMaterial( mat );
        video_driver->draw3DBox(box, irr::video::SColor(255, 250, 150, 150));
    }
}

void Cena::gizmo(){
    if(smgr)
    {
        IrrNode* node = new IrrNode();
        node->criaGizmo(smgr, &gizmo_X, &gizmo_Y, &gizmo_Z, box);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::receiver_changed_position_mainwindow(const Pos3df &pos)
{
    if(smgr && selectedSceneNode){
        selectedSceneNode->setPosition(pos);
        const irr::c8* test = selectedSceneNode->getName();
        int id = getIdFromNode(test);

        nodeParam aux = myMap[id];
        aux.position = pos;
        myMap[id] = aux;

        gizmo_X->setPosition(selectedSceneNode->getPosition());
        gizmo_X->setVisible(true);

        gizmo_Y->setPosition(selectedSceneNode->getPosition());
        gizmo_Y->setVisible(true);

        gizmo_Z->setPosition(selectedSceneNode->getPosition());
        gizmo_Z->setVisible(true);
        drawIrrlichtScene();
    }
}
void Cena::receiver_changed_dimension(nodeParam* param){
    if(smgr && selectedSceneNode)
    {
        const irr::c8* test = selectedSceneNode->getName();
        int id = getIdFromNode(test);

        irr::c8 name[50];

        nodeParam aux = myMap[id];
        aux = *param;
        myMap[id] = aux;

        qDebug()<<"position"<<" x "<<aux.position.X<<" y "<<aux.position.Y<<" z "<<aux.position.Z;
        switch((selectedSceneNode->getID()&MASK)){
             case(ID_FLAG_CUBO):
                 qDebug()<<"cubo";
                 removeChangedSceneNode();
                 insertCuboChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;

             case(ID_FLAG_ESFERA):
                 qDebug()<<"esfera";
                 removeChangedSceneNode();
                 insertEsferaChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;

             case(ID_FLAG_CILINDRO):
                 qDebug()<<"cilindro";
                 removeChangedSceneNode();
                 insertCilindroChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;

             case(ID_FLAG_CONE):
                 qDebug()<<"cone";
                 removeChangedSceneNode();
                 insertConeChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;

             case(ID_FLAG_HASTE):
                 qDebug()<<"haste";
                 removeChangedSceneNode();
                 insertHasteChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;
         }//fim switch
        drawIrrlichtScene();
    }//fim smgr
}
void Cena::geraMalha(){
    if(smgr)
    {
        FILE *file = fopen("bm.in","w+");
        if(!file){
            qDebug()<<"falha na leitura do arquivo";
            return;
        }
        int count  = 0;
//        for(it = myMap.begin(); it != myMap.end(); it++){

        NodeType type = myMap[1].type;
        irr::core::aabbox3df box = myMap[1].box;
        intVector position;
        int raio;

        switch(type)
        {
            case (Cube):
                qDebug()<<"cube gera malha";
                geraMalhaCube(box, file);
                break;

            case(Cone):
                qDebug()<<"cone gera malha";
                geraMalhaCone(box, myMap[1].dimension, file);
                break;

            case(Cilindro):
                qDebug()<<"cilindro gera malha";
                geraMalhaCilindro(box, myMap[1].dimension, file);
                break;

            case(Esphere):
                qDebug()<<"esphere gera malha";
                geraMalhaEsfera(box, myMap[1].dimension, file );
                break;

            case(Haste):
                qDebug()<<"haste gera malha";
                break;

             default:
                break;
        }
        fprintf(file,"%d \n",-1);
        fclose(file);

    }//smgr
}
void Cena::geraMalhaCube(const irr::core::aabbox3df &box, FILE *file){
    int x_inicial = (int)((box.MinEdge.X-this->box.MinEdge.X)/delta);
    int x_final = (int)((box.MaxEdge.X-this->box.MinEdge.X)/delta);

    int y_inicial = (int)((box.MinEdge.Y-this->box.MinEdge.Y)/delta);
    int y_final = (int)((box.MaxEdge.Y-this->box.MinEdge.Y)/delta);

    int z_inicial = (int)((box.MinEdge.Z-this->box.MinEdge.Z)/delta);
    int z_final = (int)((box.MaxEdge.Z-this->box.MinEdge.Z)/delta);

    fprintf(file,"%d %d %d %d %d %d \n",x_inicial, x_final, z_inicial, z_final, y_inicial, y_final);
}
void Cena::geraMalhaCilindro(const irr::core::aabbox3df &box, const Vector3df &dimension, FILE *file){
    intVector position;
    position.set((int)((myMap[1].position.X-this->box.MinEdge.X)/delta),
                 (int)((myMap[1].position.Y-this->box.MinEdge.Y)/delta),
                 (int)((myMap[1].position.Z-this->box.MinEdge.Z)/delta));

    int raio = (int)((dimension.X)/delta);

    for(int j = (int)((box.MinEdge.Y-this->box.MinEdge.Y)/delta); j<=(int)((box.MaxEdge.Y-this->box.MinEdge.Y)/delta); j++){
        for(int i = (int)((box.MinEdge.X-this->box.MinEdge.X)/delta); i<=(int)((box.MaxEdge.X - this->box.MinEdge.X)/delta); i++){
            for(int k = (int)((box.MinEdge.Z-this->box.MinEdge.Z)/delta); k<=(int)((box.MaxEdge.Z - this->box.MinEdge.Z)/delta); k++){
                position.set(position.X,j,position.Z);
                int novo_raio = calcula_raio2(position, intVector(i,j,k));
                if(novo_raio<raio*raio)
                    fprintf(file,"%d %d %d %d %d %d \n", i, i, k, k, j, j);
            }
        }
    }

}
void Cena::geraMalhaCone(const irr::core::aabbox3df &box, const Vector3df & dim, FILE* file){

    intVector position;
    position.set((int)((myMap[1].position.X-this->box.MinEdge.X)/delta),
                 (int)((myMap[1].position.Y-this->box.MinEdge.Y)/delta),
                 (int)((myMap[1].position.Z-this->box.MinEdge.Z)/delta));
    double h = dim.Y/delta;
    double tang = (dim.Y/dim.X);
    double p = delta/tang;
    double raio = dim.X;
    double raio_cone = 0;

    int raio_cilindro = 0;
    int count = 0;

    for(double j = 0; j<dim.Y; j=j+delta){
        raio_cone = raio - count*p;
        qDebug()<<"count "<<count;
        if(raio_cone>=delta)
        {
            raio_cilindro = (int)(raio_cone/delta);
            for(int i = (int)((-raio_cilindro-this->box.MinEdge.X)/delta); i<=(int)((raio_cilindro-this->box.MinEdge.X)/delta); i++)
                for(int k = (int)((-raio_cilindro-this->box.MinEdge.Z)/delta); k<=(int)((raio_cilindro-this->box.MinEdge.Z)/delta); k++){
                    position.set(position.X, (int)(h+count), position.Z);
                    int novo_raio = calcula_raio2(position, intVector(i,(int)(h+count), k));
                    if(novo_raio<raio_cilindro*raio_cilindro)
                        fprintf(file,"%d %d %d %d %d %d \n", i, i, k, k, (int)(h+count), (int)(h+count));
                }

        }
        count++;
    }
}
void Cena::geraMalhaEsfera(const irr::core::aabbox3df& box, const Vector3df& dim, FILE *file ){
    int raio = 0;
    int count = 0;
    intVector position;

    raio = (int)((myMap[1].dimension.X)/delta);

    position.set((int)((myMap[1].position.X-this->box.MinEdge.X)/delta),
                 (int)((myMap[1].position.Y-this->box.MinEdge.Y)/delta),
                 (int)((myMap[1].position.Z-this->box.MinEdge.Z)/delta));

    for(int i = (int)((box.MinEdge.X-this->box.MinEdge.X)/delta); i<(int)((box.MaxEdge.X - this->box.MinEdge.X)/delta); i++)
    {
        for(int j = (int)((box.MinEdge.Y - this->box.MinEdge.Y)/delta); j<(int)((box.MaxEdge.Y-this->box.MinEdge.Y)/delta); j++)
        {
            for(int k = (box.MinEdge.Z/delta - this->box.MinEdge.Z); k<(int)((box.MaxEdge.Z - this->box.MinEdge.Z)/delta); k++)
            {
                int novo_raio = calcula_raio(position, intVector(i,j,k));
                novo_raio = novo_raio*novo_raio;

                qDebug()<<"raio em celulas  "<<raio;
                qDebug()<<"novoraio em celulas  "<<novo_raio;

                if(novo_raio<=raio*raio)
                    fprintf(file,"%d %d %d %d %d %d \n", i, i, j, j, k, k);
                qDebug()<<"contador..."<<++count;
            }//for k
        }//for j
    }//for i
}
int Cena::calcula_raio(const intVector &p1, const intVector &p2){
    int raio = (p2.X-p1.X)*(p2.X-p1.X) + (p2.Y-p1.Y)*(p2.Y-p1.Y) + (p2.Z-p1.Z)*(p2.Z-p1.Z);
    return raio;
}
int Cena::calcula_raio2(const intVector &p1, const intVector &p2){
    int raio = (p2.X-p1.X)*(p2.X-p1.X) + (p2.Z-p1.Z)*(p2.Z-p1.Z);
    return raio;
}

//--------------------------------EVENTOS-DE-MOUSE-E-TECLADO--------------------------------------//
void Cena::keyPressEvent(QKeyEvent *event){
    if (smgr) {
        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_A))//movimenta objeto em x e y
        {
            key_x_on = true;
            key_y_on = true;
            key_z_on = false;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_S))//movimenta objeto em x e z
        {
            key_x_on = true;
            key_y_on = false;
            key_z_on = true;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_D))//movimenta objeto em y e z
        {
            key_x_on = false;
            key_y_on = true;
            key_z_on = true;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_F))//modivementa objeto nas 3 dimensoes
        {
            key_x_on = true;
            key_y_on = true;
            key_z_on = true;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_P))//aproxima camera
        {
            if(camera_01 && (camera->getPosition().Z < (box.MinEdge.Z))){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z + aproxima*2));
            }
            else if(camera_04 && (camera->getPosition().Z > (box.MaxEdge.Z))){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z - aproxima*2));
            }

            else if(camera_06 && (camera->getPosition().Y < (box.MinEdge.Y) - 1)){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y + aproxima*2,
                                              camera->getPosition().Z ));
            }
            else if(camera_05 && (camera->getPosition().Y > (box.MaxEdge.Y) + 1)){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y - aproxima*2,
                                              camera->getPosition().Z));
            }

            else if(camera_03 && ( camera->getPosition().X < (box.MinEdge.X) )){
                camera->setPosition(Vector3df(camera->getPosition().X + aproxima*2,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z));
            }
            else if(camera_02 && (camera->getPosition().X > (box.MaxEdge.X))){
                camera->setPosition(Vector3df(camera->getPosition().X - aproxima*2,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z));
            }
        }


        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_O))//afasta camera
        {
            if(camera_01 ){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z - afasta*2));
            }
            else if(camera_04){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z + afasta*2));
            }

            else if(camera_06){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y - afasta*2,
                                              camera->getPosition().Z ));
            }
            else if(camera_05){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y + afasta*2,
                                              camera->getPosition().Z));
            }

            else if(camera_03){
                camera->setPosition(Vector3df(camera->getPosition().X - afasta*2,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z));
            }
            else if(camera_02){
                camera->setPosition(Vector3df(camera->getPosition().X + afasta*2,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z));
            }
        }

        switch(event->key()){

            case (Qt::Key_X)://ativa movimentacao em x
                key_x_on = true;
                key_y_on = false;
                key_z_on = false;
                break;

            case (Qt::Key_Y)://ativa movimentacao em y
                key_y_on = true;
                key_x_on = false;
                key_z_on = false;
                break;

            case (Qt::Key_Z)://ativa movimentacao em z
                key_z_on = true;
                key_x_on = false;
                key_y_on = false;
                break;

            case (Qt::Key_R)://remove objeto selecioando
                removeSceneNode();
                break;

            case (Qt::Key_C)://duplica objeto selecionado
                duplicateSceneNode();
                break;

            case (Qt::Key_M)://ativa a movimentacao
                key_m_on = true;
                break;

            case (Qt::Key_W):
                aproximaObjetoSelecionado();
                break;

            case (Qt::Key_1): //camera na posicao padrão
                camera->setPosition(Vector3df(0, 0, this->box.MinEdge.Z-0.9));
                camera->setTarget(Vector3df(0, 0, 0));

                camera_01 = true;
                camera_02 = false;
                camera_03 = false;
                camera_04 = false;
                camera_05 = false;
                camera_06 = false;
                break;

            case (Qt::Key_2):  //camera posionada na direita
                camera->setTarget(Vector3df(0, 0, 0));
                camera->setPosition(Vector3df(this->box.MaxEdge.X+0.9, 0, 0));

                camera_01 = false;
                camera_02 = true;
                camera_03 = false;
                camera_04 = false;
                camera_05 = false;
                camera_06 = false;
                break;

            case (Qt::Key_3):   //camera posicionada na esquerda
                camera->setTarget(Vector3df(0,0,0));
                camera->setPosition(Vector3df(this->box.MinEdge.X-0.9,0,0));

                camera_01 = false;
                camera_02 = false;
                camera_03 = true;
                camera_04 = false;
                camera_05 = false;
                camera_06 = false;
                break;

            case (Qt::Key_4):   //camera posionada na parte de tras
                camera->setTarget(Vector3df(0,0,0));
                camera->setPosition(Vector3df(0,0,this->box.MaxEdge.Z+0.9));

                camera_01 = false;
                camera_02 = false;
                camera_03 = false;
                camera_04 = true;
                camera_05 = false;
                camera_06 = false;
                break;

            case (Qt::Key_5):   //camera posionada no topo
                camera->setTarget(Vector3df(0, 0, 0));
                camera->setPosition(Vector3df(0, this->box.MaxEdge.Y+0.9, 0));

                camera_01 = false;
                camera_02 = false;
                camera_03 = false;
                camera_04 = false;
                camera_05 = true;
                camera_06 = false;
                break;

            case (Qt::Key_6):   //camera posionada na base
                camera->setTarget(Vector3df(0, 0, 0));
                camera->setPosition(Vector3df(0, this->box.MinEdge.Y-0.9, 0));

                camera_01 = false;
                camera_02 = false;
                camera_03 = false;
                camera_04 = false;
                camera_05 = false;
                camera_06 = true;
                break;

            default:
                break;
        }
        drawIrrlichtScene();
   }
   event->ignore();
}
void Cena::mousePressEvent( QMouseEvent* event )
{
    if (smgr) {
        selection();

        mouseXi = device->getCursorControl()->getPosition().X;
        mouseYi = device->getCursorControl()->getPosition().Y;

        if(selectedSceneNode){
            xi = selectedSceneNode->getPosition().X;
            yi = selectedSceneNode->getPosition().Y;
            zi = selectedSceneNode->getPosition().Z;
        }
        sendMouseEventToIrrlicht(event, true);
        drawIrrlichtScene();
    }
    event->ignore();
}
void Cena::mouseReleaseEvent( QMouseEvent* event )
{
    if (smgr) {
        sendMouseEventToIrrlicht(event, false);
        duplicateNode_mouse_key = false;
        drawIrrlichtScene();
    }
    event->ignore();
}
void Cena::mouseMoveEvent(QMouseEvent *event)
{
    if(smgr)
    {
        if(MoveSceneNode!=0 && key_m_on && gizmo_X!=0 && gizmo_Y!=0 && gizmo_Z!=0 )
        {
            dx = device->getCursorControl()->getPosition().X - mouseXi;
            dy = device->getCursorControl()->getPosition().Y - mouseYi;

            if(key_x_on)
            {
                if(camera_01){
                    MoveSceneNode->setPosition(Vector3df( xi + 0.01*dx,
                                                          MoveSceneNode->getPosition().Y,
                                                          MoveSceneNode->getPosition().Z ));
                    emit send_position_change();
                }
                else if(camera_04){
                    MoveSceneNode->setPosition(Vector3df( xi + 0.01*(-dx),
                                                          MoveSceneNode->getPosition().Y,
                                                          MoveSceneNode->getPosition().Z ));
                    emit send_position_change();
                }
                else if(camera_05){
                    MoveSceneNode->setPosition(Vector3df( xi + 0.01*(-dy),
                                                          MoveSceneNode->getPosition().Y,
                                                          MoveSceneNode->getPosition().Z ));
                    emit send_position_change();
                }

                else if(camera_06){
                    MoveSceneNode->setPosition(Vector3df( xi + 0.01*(-dy),
                                                          MoveSceneNode->getPosition().Y,
                                                          MoveSceneNode->getPosition().Z ));
                    emit send_position_change();
                }

                gizmo_X->setPosition(MoveSceneNode->getPosition());
                gizmo_X->setVisible(true);

                gizmo_Y->setPosition(MoveSceneNode->getPosition());
                gizmo_Y->setVisible(true);

                gizmo_Z->setPosition(MoveSceneNode->getPosition());
                gizmo_Z->setVisible(true);
                drawIrrlichtScene();
            }

            else if(key_y_on)
            {
                if(camera_05||camera_06){
                    dy = 0;
                }
                MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X, yi - 0.01*dy, MoveSceneNode->getPosition().Z ));
                emit send_position_change();

                gizmo_X->setPosition(MoveSceneNode->getPosition());
                gizmo_X->setVisible(true);

                gizmo_Y->setPosition(MoveSceneNode->getPosition());
                gizmo_Y->setVisible(true);

                gizmo_Z->setPosition(MoveSceneNode->getPosition());
                gizmo_Z->setVisible(true);
                drawIrrlichtScene();
            }

            else if(key_z_on)
            {
                if(camera_05){
                    MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X,
                                                          MoveSceneNode->getPosition().Y,
                                                          zi + 0.01*(-dx)));
                    emit send_position_change();
                }
                else if(camera_06){
                    MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X,
                                                          MoveSceneNode->getPosition().Y,
                                                          zi + 0.01*(dx)));
                    emit send_position_change();
                }
                else if(camera_02){
                    MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X,
                                                          MoveSceneNode->getPosition().Y,
                                                          zi + 0.01*(dx)));
                    emit send_position_change();
                }

                else if(camera_03){
                    MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X,
                                                          MoveSceneNode->getPosition().Y,
                                                          zi + 0.01*(-dx)));
                    emit send_position_change();
                }

                gizmo_X->setPosition(MoveSceneNode->getPosition());
                gizmo_X->setVisible(true);

                gizmo_Y->setPosition(MoveSceneNode->getPosition());
                gizmo_Y->setVisible(true);

                gizmo_Z->setPosition(MoveSceneNode->getPosition());
                gizmo_Z->setVisible(true);
                drawIrrlichtScene();
            }
        }
    }
    event->ignore();
}
void Cena::sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown)
{
    if (smgr)
    {
        irr::SEvent irrEvent;
        irrEvent.EventType = irr::EET_MOUSE_INPUT_EVENT;

        switch (event->button()){
        case Qt::LeftButton:
            irrEvent.MouseInput.Event = pressedDown ?
                    irr::EMIE_LMOUSE_PRESSED_DOWN : irr::EMIE_LMOUSE_LEFT_UP;
            break;
        case Qt::MidButton:
            irrEvent.MouseInput.Event = pressedDown ?
                    irr::EMIE_MMOUSE_PRESSED_DOWN : irr::EMIE_MMOUSE_LEFT_UP;
            break;
        case Qt::RightButton:
            irrEvent.MouseInput.Event = pressedDown ?
                   irr::EMIE_RMOUSE_PRESSED_DOWN : irr::EMIE_RMOUSE_LEFT_UP;
            break;
        default:
            return;
        }
        irrEvent.MouseInput.X = event->x() - (video_driver->getScreenSize().Width)/2;
        irrEvent.MouseInput.Y = -event->y() + (video_driver->getScreenSize().Height)/2;
        irrEvent.MouseInput.Wheel = 0.0f;

        if(pressedDown) mouse_press_position.set(irrEvent.MouseInput.X,irrEvent.MouseInput.Y,0);
        else if(!pressedDown) mouse_release_position.set(irrEvent.MouseInput.X,irrEvent.MouseInput.Y,0);

        device->postEventFromUser(irrEvent);
    }
    event->ignore();
}
//-------------------------------FIM-EVENTOS-DE-MOUSE-E-TECLADO------------------------------------//

//-----------------------------------MODIFICADORES-DE-OBEJTOS--------------------------------------//
void Cena::insertHaste(int id, IrrNode *node, nodeParam* param){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaHaste(smgr, param, nodeName);

        irr::scene::ISceneNode *aux = node->getNode();

        nodeParam *haste_parameters = new nodeParam;
        haste_parameters->dimension.set(param->dimension);
        haste_parameters->position.set(param->position);
        haste_parameters->parametros.set(param->parametros);
        haste_parameters->box = aux->getBoundingBox();
        haste_parameters->type = param->type;

        myMap[id] = *haste_parameters;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete haste_parameters;
        delete node;
    }
}
void Cena::insertHasteChanged(IrrNode* node, nodeParam* param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        node->criaHaste(smgr, param, nodeName);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::insertCubo(int id, IrrNode* node, nodeParam* param)
{
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaCubo(smgr, param, nodeName);

        irr::scene::ISceneNode *aux = node->getNode();

        nodeParam *cube_parameters = new nodeParam;
        cube_parameters->dimension.set(param->dimension);
        cube_parameters->position.set(param->position);
        cube_parameters->parametros.set(param->parametros);
        cube_parameters->box = aux->getBoundingBox();
        cube_parameters->type = Cube;

        myMap[id] = *cube_parameters;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete cube_parameters;
        delete node;
    }
}
void Cena::insertCuboChanged(IrrNode *node, nodeParam* param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        node->criaCubo(smgr, param, nodeName);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::insertEsfera(int id, IrrNode* node, nodeParam* param)
{
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaEsfera(smgr, param, nodeName);

        irr::scene::ISceneNode *aux = node->getNode();

        nodeParam *esfera_parameters = new nodeParam;
        esfera_parameters->dimension.set(param->dimension);
        esfera_parameters->position.set(param->position);
        esfera_parameters->parametros.set(param->parametros);
        esfera_parameters->type = Esphere;
        esfera_parameters->box = aux->getBoundingBox();

        myMap[id] = *esfera_parameters;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete esfera_parameters;
        delete node;
    }
}
void Cena::insertEsferaChanged(IrrNode *node, nodeParam *param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        node->criaEsfera(smgr, param, nodeName);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::insertCilindro(int id, IrrNode *node, nodeParam* param)
{
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaCilindro(smgr, param, nodeName);

        irr::scene::ISceneNode *aux = node->getNode();

        nodeParam *cilindro_parameters = new nodeParam;
        cilindro_parameters->dimension.set(param->dimension);
        cilindro_parameters->position.set(param->position);
        cilindro_parameters->parametros.set(param->parametros);
        cilindro_parameters->box = aux->getBoundingBox();
        cilindro_parameters->type = Cilindro;

        myMap[id] = *cilindro_parameters;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete cilindro_parameters;
        delete node;
    }
}
void Cena::insertCilindroChanged(IrrNode *node, nodeParam *param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        qDebug()<<"change cilindro, id "<< nodeName;
        node->criaCilindro(smgr, param, nodeName);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::insertCone(int id, IrrNode* node, nodeParam* param)
{
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaCone(smgr, param, nodeName);

        irr::scene::ISceneNode *aux = node->getNode();

        nodeParam *cone_parameters = new nodeParam;
        cone_parameters->dimension.set(param->dimension);
        cone_parameters->position.set(param->position);
        cone_parameters->parametros.set(param->parametros);
        cone_parameters->box = aux->getBoundingBox();
        cone_parameters->type = Cone;

        myMap[id] = *cone_parameters;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete cone_parameters;
        delete node;
    }
}
void Cena::insertConeChanged(IrrNode *node, nodeParam *param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        node->criaCone(smgr, param, nodeName);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::duplicateSceneNode()
{
    if(smgr){
        if(selectedSceneNode){
            irr::scene::IMeshSceneNode* node = (irr::scene::IMeshSceneNode*)selectedSceneNode->clone();

            node->setPosition(mouse_release_position);
            node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
            selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);

            seletor = smgr->createOctreeTriangleSelector(node->getMesh(), node, 32);
            node->setTriangleSelector(seletor);
            seletor->drop();

            selectedSceneNode = (irr::scene::ISceneNode*)node;
         }
    }
}
void Cena::removeSceneNode()
{
    if(smgr && selectedSceneNode)
    {
        const irr::c8* test = selectedSceneNode->getName();
        int id = getIdFromNode(test);
        it = myMap.find(id);
        myMap.erase(it);

        selectedSceneNode->remove();
        selectedSceneNode = 0;
        gizmo_X->setVisible(false);
        gizmo_Y->setVisible(false);
        gizmo_Z->setVisible(false);

    }
}
void Cena::removeChangedSceneNode(){
    if(smgr){
        if(smgr && selectedSceneNode)
        {
            selectedSceneNode->remove();
            selectedSceneNode = 0;
            gizmo_X->setVisible(false);
            gizmo_Y->setVisible(false);
            gizmo_Z->setVisible(false);

        }
    }
}
void Cena::aproximaObjetoSelecionado(){
    if(smgr && selectedSceneNode){
        if(camera_01){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X,
                                          selectedSceneNode->getPosition().Y,
                                          selectedSceneNode->getPosition().Z - 1));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }
        else if(camera_04){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X,
                                          selectedSceneNode->getPosition().Y,
                                          selectedSceneNode->getPosition().Z + 1));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }

        if(camera_06){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X,
                                          selectedSceneNode->getPosition().Y - 1,
                                          selectedSceneNode->getPosition().Z ));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }
        else if(camera_05){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X,
                                          selectedSceneNode->getPosition().Y + 1,
                                          selectedSceneNode->getPosition().Z));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }

        if(camera_03){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X - 1,
                                          selectedSceneNode->getPosition().Y,
                                          selectedSceneNode->getPosition().Z));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }
        else if(camera_02){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X + 1,
                                          selectedSceneNode->getPosition().Y,
                                          selectedSceneNode->getPosition().Z));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }
    }
}
//--------------------------------FIM-MODIFICADORES-DE-OBEJTOS--------------------------------------//

//-----------------------------------------SELECAO-E-PINTURA----------------------------------------//
void Cena::selection()
{
    if(smgr)
    {
        Vector3df dim;
        irr::core::vector3df intersection;
        irr::core::triangle3df tri;
        irr::core::line3df ray = smgr->getSceneCollisionManager()->getRayFromScreenCoordinates(
                                                        device->getCursorControl()->getPosition(),
                                                        smgr->getActiveCamera());
        if (selectedSceneNode){
                    selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                    selectedSceneNode = 0;                    
        }

        selectedSceneNode = collMan->getSceneNodeAndCollisionPointFromRay(ray, intersection, tri, S);

         if (selectedSceneNode){
             MoveSceneNode = selectedSceneNode;
             selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, true);


             IrrNode* node = new IrrNode();

             const irr::c8* test = selectedSceneNode->getName();
             int id = getIdFromNode(test);
             dim = myMap[id].dimension;

             irr::core::aabbox3df box = selectedSceneNode->getBoundingBox();

             gizmo_X->remove();
             gizmo_X = 0;

             gizmo_Y->remove();
             gizmo_Y = 0;

             gizmo_Z->remove();
             gizmo_Z = 0;

             node->criaGizmo(smgr, &gizmo_X, &gizmo_Y, &gizmo_Z, box);
             delete node;             
         }
         else
         {
             MoveSceneNode = 0;

             gizmo_X->setVisible(false);
             gizmo_Y->setVisible(false);
             gizmo_Z->setVisible(false);

             key_x_on = false;
             key_y_on = false;
             key_z_on = false;
         }         
         emit send_selection_call(dim);
    }
}
void Cena::drawIrrlichtScene()
{
    if(smgr)
    {
        video_driver->beginScene( true, true, irr::video::SColor( 255, 128, 128, 128 ));
        smgr->drawAll();
        env->drawAll();
        printRegiaoAnalise(box);

        video_driver->endScene();
    }
}
//---------------------------------------FIM-SELECAO-E-PINTURA--------------------------------------//
