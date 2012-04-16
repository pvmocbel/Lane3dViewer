#include "cena.h"
#include "getdimcube.h"

Cena::Cena():IrrViewer(0),light(0),mouse_key_test(false),
    selectedSceneNode(0),collMan(0),duplicateNode_mouse_key(false),
    mouseXi(0),mouseYi(0),dx(0),dy(0),pivo(0),seta_pivo(0),MoveSceneNode(0)
{
    camera[0] = 0;
    camera[1] = 0;
    camera[2] = 0;
    camera[3] = 0;
    mouse_press_position.set(0,0,0);
    mouse_release_position.set(0,0,0);
    key_m_on = false;
    key_w_on = false;
    locked = true;
    yi = 0;
    gizmo_X= 0;
    gizmo_Y = 0;
    gizmo_Z = 0;
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

void Cena::gizmo(){
    if(smgr && key_m_on && selectedSceneNode )
    {
        IrrNode* node = new IrrNode();
        node->criaGizmo(selectedSceneNode,smgr, &gizmo_X, gizmo_Y, gizmo_Z);
        drawIrrlichtScene();
    }
}

void Cena::cenaCameras(){
    if (smgr) {
        camera[0] = smgr->addCameraSceneNode(0, Vector3df(0, 0, -50), Vector3df(0, 0, 0));
        camera[1] = smgr->addCameraSceneNode(0, Vector3df(50, 0, 0), Vector3df(0, 0, 0));
        camera[2] = smgr->addCameraSceneNode(0, Vector3df(0, 50, 0), Vector3df(0, 0, 0));
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
                gizmo();
                key_m_on =true;
                break;
            case (Qt::Key_W):
                key_w_on = true;
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
        selection();
        mouseXi = event->x();
        mouseYi = device->getCursorControl()->getPosition().Y;
        if(pivo) yi = pivo->getPosition().Y;
       sendMouseEventToIrrlicht(event, true);
//       (key_m_on)?(false):(true);
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
        if(MoveSceneNode!=0 && seta_pivo!=0 && key_m_on )
        {
            dx = event->x() - mouseXi;
            dy = device->getCursorControl()->getPosition().Y - mouseYi;
            seta_pivo->setPosition(Vector3df(MoveSceneNode->getPosition().X, yi - 0.1*dy, MoveSceneNode->getPosition().Z));
            MoveSceneNode->setPosition(seta_pivo->getPosition());
            drawIrrlichtScene();            
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

void Cena::insertNode(IrrNode* node)
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

void Cena::duplicateSceneNode()
{
    if(smgr){
        if(selectedSceneNode){
            irr::scene::ISceneNode* node =  selectedSceneNode->clone();
            node->setPosition(mouse_release_position);
            node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
            selectedSceneNode = 0;
        }
    }
}

void Cena::removeSceneNode()
{
    if(smgr){
        if(selectedSceneNode){
            selectedSceneNode->remove();
            selectedSceneNode = 0;
        }
    }
}

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

        pivo = collMan->getSceneNodeAndCollisionPointFromRay(ray, intersection, tri, S);

        if(pivo){
            if((pivo->getID() & MASK) == ID_FLAG_GIZMO_Y)   seta_pivo = pivo;
           else{
               selectedSceneNode = pivo;
               if(gizmo_X)
                   gizmo_X->setPosition(selectedSceneNode->getPosition());
            }
        }
        else selectedSceneNode = 0;

         if (selectedSceneNode){
             MoveSceneNode = selectedSceneNode;
             selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
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
        video_driver->endScene();
    }
}
