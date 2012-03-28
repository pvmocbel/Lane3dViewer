#include "cena.h"
#include "getdimcube.h"

Cena::Cena():IrrViewer(0),camera(0),light(0),mouse_key_test(false),
    selectedSceneNode(0),highlightedSceneNode(0),collMan(0),duplicateNode_mouse_key(false)
{
    mouse_press_position.set(0,0,0);
    mouse_release_position.set(0,0,0);
    key_m_on = false;
}

Cena::~Cena()
{}

void Cena::cenaIrrlicht()
{
    if (smgr) {
        collMan = smgr->getSceneCollisionManager();
        cenaCameras();
        cenaIluminacao();
        drawIrrlichtScene();
    }
}

void Cena::cenaCameras(){
    if (smgr) {
        camera  = smgr->addCameraSceneNode();
        camera->setPosition(irr::core::vector3df(60,0,0));
        camera->setTarget(irr::core::vector3df(0,0,0));
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

void Cena::cenaVisualizacoes(){

}

void Cena::keyPressEvent(QKeyEvent *event){
    if (smgr) {
        switch(event->key()){
            case (Qt::Key_X):
                removeSceneNode();
                break;
            case (Qt::Key_D):
                duplicateSceneNode();
                break;
            case (Qt::Key_M):
                key_m_on = true;
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
       sendMouseEventToIrrlicht(event, true);
       drawIrrlichtScene();
    }
    event->ignore();
}

void Cena::mouseReleaseEvent( QMouseEvent* event )
{
    if (smgr) {
        sendMouseEventToIrrlicht(event, false);
        if(key_m_on) moveSceneNode(mouse_release_position);
        duplicateNode_mouse_key = false;
        drawIrrlichtScene();
    }
    event->ignore();
}

void Cena::sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown)
{
    if (smgr) {
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

void Cena::insertNode(int id, IrrNode* node){

    if(smgr){
        getDimCube* w = new getDimCube(0);
        w->show();
        w->exec();

        if(w->isOk()){
            Dim3df dim = w->getDimension();
            Pos3df p = w->getPosition();
            node->criaCubo(&id, smgr, p, dim);
            nodes[id] = node;
            drawIrrlichtScene();
        }

        delete w;
    }
}

IrrNode* Cena::getNode(int id){

}

void Cena::moveSceneNode(Vector3df position){
    if(smgr){
        if(highlightedSceneNode!=0 && selectedSceneNode!=0){
            selectedSceneNode->setPosition(Vector3df(position.X+mouse_press_position.X,position.Y-mouse_press_position.Y,0));
        }
    }
}

void Cena::duplicateSceneNode(){
    if(smgr){
        if(highlightedSceneNode!=0 && selectedSceneNode!=0){
            irr::scene::ISceneNode* node =  selectedSceneNode->clone();
            node->setPosition(mouse_release_position);
            node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
            highlightedSceneNode = 0;
        }
    }
}

void Cena::removeSceneNode(){
    if(smgr){
        if(highlightedSceneNode!=0 && selectedSceneNode!=0){
            selectedSceneNode->remove();
            selectedSceneNode = 0;
            highlightedSceneNode = 0;
        }
    }
}

void Cena::drawIrrlichtScene()
{
    if(smgr){
        irr::core::vector3df intersection;
        irr::core::triangle3df tri;
        irr::core::line3df ray = smgr->getSceneCollisionManager()->getRayFromScreenCoordinates(device->getCursorControl()->getPosition(), camera);

        if (highlightedSceneNode){
             highlightedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
             highlightedSceneNode = 0;
        }

        selectedSceneNode = collMan->getSceneNodeAndCollisionPointFromRay(ray, intersection, tri, IDFlag_IsPickable);

        if (selectedSceneNode){
              highlightedSceneNode = selectedSceneNode;
              highlightedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
        }

        video_driver->beginScene( true, true, irr::video::SColor( 255, 128, 128, 128 ));
        smgr->drawAll();
        env->drawAll();
        video_driver->endScene();

    }
}
