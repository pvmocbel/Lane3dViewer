#include "cena.h"
#include "getdimcube.h"

Cena::Cena():IrrViewer(0),light(0),mouse_key_test(false),
    selectedSceneNode(0),highlightedSceneNode(0),
    collMan(0),duplicateNode_mouse_key(false),
    mouseXi(0),mouseYi(0),dx(0),dy(0)
{
    camera[0] = 0;
    camera[1] = 0;
    camera[2] = 0;
    camera[3] = 0;
    mouse_press_position.set(0,0,0);
    mouse_release_position.set(0,0,0);
    key_m_on = false;
}

Cena::~Cena(){}

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
        camera[0] = smgr->addCameraSceneNode(0, Vector3df(50, 0, 0), Vector3df(0, 0, 0));
        camera[1] = smgr->addCameraSceneNode(0, Vector3df(0, 100, 0), Vector3df(0, 0, 0));
        camera[2] = smgr->addCameraSceneNode(0, Vector3df(0, 0, 50), Vector3df(0, 0, 0));
        camera[3] = smgr->addCameraSceneNode(0, Vector3df(0, 10, 10), Vector3df(0, 0, 0));
        smgr->setActiveCamera(camera[0]);
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
                key_m_on =true;
                break;
            case (Qt::Key_1):
                smgr->setActiveCamera(camera[0]);
                break;
            case (Qt::Key_2):
                smgr->setActiveCamera(camera[1]);
                break;
            case (Qt::Key_3):
                smgr->setActiveCamera(camera[2]);
                break;
            case (Qt::Key_4):
                smgr->setActiveCamera(camera[3]);
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
        mouseXi = event->x();
        mouseYi = event->y();
       sendMouseEventToIrrlicht(event, true);
       (key_m_on)?(false):(true);
       drawIrrlichtScene();
    }
    event->ignore();
}

void Cena::mouseReleaseEvent( QMouseEvent* event )
{
    if (smgr) {
        sendMouseEventToIrrlicht(event, false);
        duplicateNode_mouse_key = false;
//        key_m_on = false;
        drawIrrlichtScene();
    }
    event->ignore();
}

void Cena::mouseMoveEvent(QMouseEvent *event)
{
    if(smgr)
    {
        if(highlightedSceneNode!=0 && selectedSceneNode!=0 && key_m_on){
            dx = event->x() - mouseXi;
            dy = event->y() - mouseYi;
            highlightedSceneNode->setPosition(Vector3df(highlightedSceneNode->getPosition().X + 0.3*dx,
                                                        highlightedSceneNode->getPosition().Y - 0.3*dy,
                                                        highlightedSceneNode->getPosition().Z));
            drawIrrlichtScene();
        }

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

void Cena::insertNode(int id, IrrNode* node)
{
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

void Cena::duplicateSceneNode()
{
    if(smgr){
        if(highlightedSceneNode!=0 && selectedSceneNode!=0){
            irr::scene::ISceneNode* node =  selectedSceneNode->clone();
            node->setPosition(mouse_release_position);
            node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
            highlightedSceneNode = 0;
        }
    }
}

void Cena::removeSceneNode()
{
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
        irr::core::line3df ray = smgr->getSceneCollisionManager()->getRayFromScreenCoordinates(device->getCursorControl()->getPosition(), smgr->getActiveCamera());

        if (highlightedSceneNode){
             highlightedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
             highlightedSceneNode = 0;
        }

        selectedSceneNode = collMan->getSceneNodeAndCollisionPointFromRay(ray, intersection, tri, IDFlag_IsPickable);

        if (selectedSceneNode){
              highlightedSceneNode = selectedSceneNode;
              highlightedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
              qDebug()<<"position x ="<<highlightedSceneNode->getPosition().X<<" y = "<<highlightedSceneNode->getPosition().Y<<" z = "<<highlightedSceneNode->getPosition().Z;
        }

        video_driver->beginScene( true, true, irr::video::SColor( 255, 128, 128, 128 ));
        smgr->drawAll();
        env->drawAll();
        video_driver->endScene();

    }
}
