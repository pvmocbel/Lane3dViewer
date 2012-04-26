#include "cena.h"
#include "getdimcube.h"
#include "getdimcone.h"
#include "getdimesfera.h"
#include "getdimcilindro.h"
#include <math.h>


Cena::Cena():IrrViewer(0),light(0),mouse_key_test(false),
    selectedSceneNode(0),collMan(0),duplicateNode_mouse_key(false),
    mouseXi(0),mouseYi(0),dx(0),dy(0),MoveSceneNode(0),aproxima(1.0),afasta(1.0)
{
    camera = 0;

    vetor_normal.set(0,0,0);
    vetor_target.set(0,0,0);
    vetor_normal_n.set(0,0,0);

    mouse_press_position.set(0,0,0);
    mouse_release_position.set(0,0,0);

    key_m_on = false;
    key_w_on = false;
    key_x_on = false;
    key_y_on = false;
    key_z_on = false;

    fat_dx = 0;
    fat_dy = 0;
    fat_dz = 0;

    xi = 0;
    yi = 0;
    zi = 0;

    fator_x_dx = 0;
    fator_x_dy = 0;

    fator_y_dx = 0;
    fator_y_dy = 0;

    fator_z_dx = 0;
    fator_z_dy = 0;

    gizmo_X = 0;
    gizmo_Y = 0;
    gizmo_Z = 0;

    float x[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    matrix.setM(x);
}

Cena::~Cena(){}

void Cena::cenaIrrlicht()
{
    if (smgr) {
        collMan = smgr->getSceneCollisionManager();
        cenaCameras();
        cenaIluminacao();
        criaRegiaoAnalise();
        gizmo();
        drawIrrlichtScene();
    }
}

void Cena::cenaCameras(){
    if (smgr) {
        camera = smgr->addCameraSceneNode();
        camera->setPosition(Vector3df(0,0,-50));
        camera->setTarget(Vector3df(0,0,0));
        smgr->setActiveCamera(camera);
        atualizaFatores();
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

void Cena::cenaVisualizacoes(){}

void Cena::criaRegiaoAnalise(){
    if(smgr)
    {
        video_driver->setTransform( irr::video::ETS_WORLD, irr::core::matrix4());
        irr::video::SMaterial mat;
        mat.Lighting = false;
        video_driver->setMaterial( mat );
        irr::core::aabbox3df box;
        box.MinEdge.set(Vector3df(-50,-50,-50));
        box.MaxEdge.set(Vector3df(50, 50, 50));
        video_driver->draw3DBox(box, irr::video::SColor(255, 250, 150, 150));
    }
}

void Cena::criaRegiaoLivre(){}
void Cena::gizmo(){
    if(smgr)
    {
        IrrNode* node = new IrrNode();
        node->criaGizmo(smgr, &gizmo_X, &gizmo_Y, &gizmo_Z,video_driver);
        drawIrrlichtScene();
    }
}

void Cena::atualizaFatores(){
    if(smgr)
    {
        vetor_normal.set(vetor_target.X - camera->getPosition().X,
                         vetor_target.Y - camera->getPosition().Y,
                         vetor_target.Y - camera->getPosition().Z);

        vetor_normal_n.set(vetor_normal);

        if(vetor_normal_n.X>0)    vetor_normal_n.X = 1;
        else if(vetor_normal_n.X<0)    vetor_normal_n.X = -1;

        if(vetor_normal_n.Y>0)     vetor_normal_n.Y = 1;
        else if(vetor_normal_n.Y<0)   vetor_normal_n.Y = -1;


        if(vetor_normal_n.Z>0)   vetor_normal_n.Z = 1;
        else if(vetor_normal_n.Z<0) vetor_normal_n.Z = -1;

        fat_dx = vetor_normal_n.X;
        fat_dy = vetor_normal_n.Y;
        fat_dz = vetor_normal_n.Z;
    }
}

//--------------------------------EVENTOS-DE-MOUSE-E-TECLADO--------------------------------------//
void Cena::keyPressEvent(QKeyEvent *event){
    if (smgr) {

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_A)){
            key_x_on = true;
            key_y_on = true;
            key_z_on = false;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_S)){
            key_x_on = true;
            key_y_on = false;
            key_z_on = true;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_D)){
            key_x_on = false;
            key_y_on = true;
            key_z_on = true;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_F)){
            key_x_on = true;
            key_y_on = true;
            key_z_on = true;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_Plus)){
                camera->setFOV((aproxima*PI)/(2.5));
                qDebug()<<"FOV = "<<camera->getFOV();
                aproxima +=0.09;
        }


        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_Minus)){
                camera->setFOV((PI)/(2.5+afasta));
                qDebug()<<"FOV = "<<camera->getFOV();
                afasta += 0.01;
        }

        switch(event->key()){

            case (Qt::Key_X):
                key_x_on = true;
                key_y_on = false;
                key_z_on = false;
                break;
            case (Qt::Key_Y):
                key_y_on = true;
                key_x_on = false;
                key_z_on = false;
                break;
            case (Qt::Key_Z):
                key_z_on = true;
                key_x_on = false;
                key_y_on = false;
                break;
            case (Qt::Key_R):
                removeSceneNode();
                break;
            case (Qt::Key_C):
                duplicateSceneNode();
                break;
            case (Qt::Key_M):
                key_m_on = true;
                break;
            case (Qt::Key_W):
                key_w_on = true;
                break;

            case (Qt::Key_1):   //padr�o
                camera->setPosition(Vector3df(0, 0, -1000));
                camera->setTarget(Vector3df(0, 0, 0));
                atualizaFatores();
                break;
            case (Qt::Key_2):   //direita
                camera->setTarget(Vector3df(0, 0, 0));
                camera->setPosition(Vector3df(60, 0, 0));
                atualizaFatores();
                break;
            case (Qt::Key_3):   //esquerda
                camera->setTarget(Vector3df(0,0,0));
                camera->setPosition(Vector3df(-60,0,1));
                atualizaFatores();
                break;
            case (Qt::Key_4):   //tras
                camera->setTarget(Vector3df(0,0,0));
                camera->setPosition(Vector3df(0,0,60));
                atualizaFatores();
                break;
            case (Qt::Key_5):   //topo
                camera->setTarget(Vector3df(0,0,0));
                camera->setPosition(Vector3df(0,60,-0.1));
                atualizaFatores();
                break;
            case (Qt::Key_6):   //base
                camera->setTarget(Vector3df(0,0,0));
                camera->setPosition(Vector3df(0,-60,-0.1));
                atualizaFatores();
                break;
            case (Qt::Key_7):   //base
            camera->setTarget(Vector3df(0,0,0));
            camera->setPosition(Vector3df(0,100,-100));
            atualizaFatores();
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
        key_w_on = false;
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
                dx = fat_dz*dx ;
                MoveSceneNode->setPosition(Vector3df( xi + 0.1*dx , MoveSceneNode->getPosition().Y, MoveSceneNode->getPosition().Z ));

                gizmo_X->setPosition(MoveSceneNode->getPosition());
                gizmo_X->setVisible(true);

                gizmo_Y->setPosition(MoveSceneNode->getPosition());
                gizmo_Y->setVisible(true);

                gizmo_Z->setPosition(MoveSceneNode->getPosition());
                gizmo_Z->setVisible(true);
                drawIrrlichtScene();
            }
            if(key_y_on)
            {
//                dy = fat_dy*dy;
                MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X, yi - 0.1*dy, MoveSceneNode->getPosition().Z ));

                gizmo_X->setPosition(MoveSceneNode->getPosition());
                gizmo_X->setVisible(true);

                gizmo_Y->setPosition(MoveSceneNode->getPosition());
                gizmo_Y->setVisible(true);

                gizmo_Z->setPosition(MoveSceneNode->getPosition());
                gizmo_Z->setVisible(true);
                drawIrrlichtScene();
            }
            if(key_z_on)
            {
                dx = -fat_dx*dx + fat_dy*dy;
                MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X, MoveSceneNode->getPosition().Y, zi + 0.1*(dx)));

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
//-------------------------------FIM-EVENTOS-DE-MOUSE-E-TECLADO--------------------------------------//

//-----------------------------------MODIFICADORES-DE-OBEJTOS--------------------------------------//
void Cena::insertCubo(IrrNode* node)
{
    if(smgr){
        getDimCube* w = new getDimCube(0);
        w->show();
        w->exec();
        if(w->isOk()){
            Dim3df dim = w->getDimension();
            Pos3df p = w->getPosition();
            node->criaCubo(smgr, p, dim, video_driver);
            drawIrrlichtScene();
        }
        delete w;
    }
}

void Cena::insertCone(IrrNode* node)
{
    if(smgr)
    {
        getDimCone *w = new getDimCone();

        w->show();
        w->exec();

        Dim3df dim = w->getDimension();
        Pos3df p = w->getPosition();

        node->criaCone(smgr, p, dim);

        drawIrrlichtScene();
        delete w;
    }
}

void Cena::insertCilindro(IrrNode* node)
{
    if(smgr)
    {
        getDimCilindro*w = new getDimCilindro();

        w->show();
        w->exec();

        Dim3df dim = w->getDimension();
        Pos3df p = w->getPosition();
        node->criaCilindro(smgr, p, dim);

        drawIrrlichtScene();

        delete w;
    }
}

void Cena::insertEsfera(IrrNode* node)
{
    if(smgr)
    {
        getDimEsfera* w = new getDimEsfera(0);

        w->show();
        w->exec();

        double raio = w->getDimension();
        Pos3df p = w->getPosition();
        node->criaEsfera(smgr, p, raio);

        drawIrrlichtScene();

        delete w;
    }
}

void Cena::duplicateSceneNode()
{
    if(smgr){
        if(selectedSceneNode){
            irr::scene::ISceneNode* node =  (irr::scene::ISceneNode*)selectedSceneNode->clone();
            node->setPosition(mouse_release_position);
            node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
            selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
            node->setID(S);
         }
    }
}

void Cena::removeSceneNode()
{
    if(smgr){
        if(selectedSceneNode){
            selectedSceneNode->remove();
            selectedSceneNode = 0;
            gizmo_X->setVisible(false);
            gizmo_Y->setVisible(false);
            gizmo_Z->setVisible(false);
        }
    }
}
//--------------------------------FIM-MODIFICADORES-DE-OBEJTOS--------------------------------------//

//-----------------------------------------SELECAO-E-PINTURA---------------------------------------------//
void Cena::selection()
{
    if(smgr)
    {
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
    }
}

void Cena::drawIrrlichtScene()
{
    if(smgr)
    {
        video_driver->beginScene( true, true, irr::video::SColor( 255, 128, 128, 128 ));
        smgr->drawAll();
        env->drawAll();
        criaRegiaoAnalise();

        video_driver->endScene();
    }
}
//---------------------------------------FIM-SELECAO-E-PINTURA-------------------------------------------//
