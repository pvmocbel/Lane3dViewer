#include "irrqwidget.h"

IrrQWidget::IrrQWidget(QWidget *parent) : QWidget(parent){
    i = 10;
    idevice = 0;
    driverType = irr::video::EDT_OPENGL;
    selectedSceneNode = 0;
    highlightedSceneNode = 0;
    seletor = 0;
    rot = 0;
}

IrrQWidget::~IrrQWidget(){
    if (idevice != 0){
        idevice->closeDevice();
        iscene->drop();
        iguienv->drop();
        idevice->drop();
    }
}
//----------------------------------METODOS-IRRLICHT----------------------------//
void IrrQWidget::createIrrlichtDevice(){
    if(idevice!=0)
        return;
    SIrrlichtCreationParameters params;
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NoSystemBackground);
    create(winId(), false, false);
    params.DriverType = driverType;
    params.WindowId = reinterpret_cast<void*>(winId());
    params.WindowSize.Width = width();
    params.WindowSize.Height = height();
    params.EventReceiver = &receiver;
    idevice = createDeviceEx(params);
    setAttribute(Qt::WA_OpaquePaintEvent);

    idriver  = idevice->getVideoDriver();
    iscene = idevice->getSceneManager();
    iguienv = idevice->getGUIEnvironment();
}
void IrrQWidget::buildIrrlichtScene(){
    if(idevice != 0){
        collMan = iscene->getSceneCollisionManager();
        //--------------------------------------FORMA-GEOMETRICA------------------------------------//
        geo = iscene->getGeometryCreator();
        mesh_cube = geo->createCubeMesh(vector3df(20,20,20));
        cube = iscene->addMeshSceneNode(mesh_cube);
        if (cube){
            cube->setMaterialFlag(EMF_LIGHTING, false);
            cube->setPosition(core::vector3df(0,0,100));
            cube->setID(IDFlag_IsPickable);
            seletor = iscene->createOctTreeTriangleSelector(cube->getMesh(), 0, 128);
            cube->setTriangleSelector(seletor);
            seletor->drop();
        }

        mesh_cube = geo->createCubeMesh(vector3df(20,20,20));
        cube2 = iscene->addMeshSceneNode(mesh_cube);
        if (cube2){
            cube2->setMaterialFlag(EMF_LIGHTING, false);
            cube2->setPosition(core::vector3df(0,40,100));
            cube2->setID(IDFlag_IsPickable);
            seletor = iscene->createOctTreeTriangleSelector(cube2->getMesh(), 0, 128);
            cube2->setTriangleSelector(seletor);
            seletor->drop();
        }
        posicao = cube->getPosition();
//        if(seguidor){
//            mesh_seguidor = geo->createCylinderMesh(1.0f,150.0f,10,SColor(255, 255, 0, 0),true,0.f);
//            seguidor = iscene->addMeshSceneNode(mesh_seguidor);
//            seguidor->setPosition(vector3df(40,0,100));
//            seguidor->setRotation(vector3df(90,0,0));
//        }
        //--------------------------------------ILUMINAÇÃO---------------------------------//
        ILightSceneNode *light = iscene->addLightSceneNode();
        light->setLightType( ELT_DIRECTIONAL );
        light->setRotation( vector3df( 45.0f, 45.0f, 0.0f ));
        light->getLightData().AmbientColor = SColorf( 0.2f, 0.2f, 0.2f, 1.0f );
        light->getLightData().DiffuseColor = SColorf( 0.8f, 0.8f, 0.8f, 1.0f );
        //---------------------------------------CAMERA-----------------------------------//
         myCursor = idevice->getCursorControl();
         camera = iscene->addCameraSceneNode();
         camera->setPosition(vector3df(0,0,0));
     }
}
void IrrQWidget::drawIrrlichtScene(){
    if(idevice != 0){
       rot+=1;
       vector3df intersection;
       triangle3df tri;
       line3df ray = iscene->getSceneCollisionManager()->getRayFromScreenCoordinates(idevice->getCursorControl()->getPosition(), camera);
//       createSeguidor(ray);
       if (highlightedSceneNode){
            highlightedSceneNode->setMaterialFlag(EMF_WIREFRAME, false);
            highlightedSceneNode = 0;
        }
         selectedSceneNode = collMan->getSceneNodeAndCollisionPointFromRay(ray, intersection, tri, IDFlag_IsPickable);
       if (selectedSceneNode){
             highlightedSceneNode = selectedSceneNode;
             highlightedSceneNode->setMaterialFlag(EMF_WIREFRAME, true);
             highlightedSceneNode->setRotation(vector3df(0,rot,0));
       }
       idriver->beginScene( true, true, SColor( 255, 128, 128, 128 ));
       iscene->drawAll();
       iguienv->drawAll();
       idriver->endScene();
    }
}

//---------------------------------FIM-METODOS-IRRLICHT----------------------------//

//-------------------------------------METODOS-QT---------------------------------//
void IrrQWidget::resizeEvent(QResizeEvent* event){
    if ( idevice != 0 ){
        dimension2d<unsigned> size;
        size.Width = event->size().width();
        size.Height = event->size().height();
        idriver->OnResize(size);
     }
    QWidget::resizeEvent(event);
}
void IrrQWidget::paintEvent( QPaintEvent *event ){
    if ( idevice != 0 ){
        QWidget::paintEvent(event);
        drawIrrlichtScene();
    }
}

QPaintEngine * IrrQWidget::paintEngine() const{
    if ( idevice != 0 ){
        QWidget::paintEngine();
        return 0;
    }
}
//------------------------------------FIM-METODOS-QT---------------------------------//
void IrrQWidget::createSeguidor(line3df line){
//    if(seguidor!=0){
//        seguidor->setPosition(vector3df(line.start.X,line.start.Y,0));
////        seguidor->setPosition(vector3df(,myCursor->getPosition().Y,0));
//    }
}

//-------------------------------------EVENTOS-DE-MOUSE---------------------------------------//
void IrrQWidget::sendMouseEventToIrrlicht(QMouseEvent* event, bool pressedDown){
        irr::SEvent irrEvent;
        irrEvent.EventType = irr::EET_MOUSE_INPUT_EVENT;

        switch (event->button())
        {
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
            return; // Cannot handle this mouse event
        }
        irrEvent.MouseInput.X = event->x()-(idriver->getScreenSize().Width)/2;
        irrEvent.MouseInput.Y = -event->y()+ (idriver->getScreenSize().Height)/2;
        qDebug()<<"MOUSE X "<< irrEvent.MouseInput.X<<"\tMOUSE Y "<<irrEvent.MouseInput.Y;
        irrEvent.MouseInput.Wheel = 0.0f; // Zero is better than undefined
        idevice->postEventFromUser(irrEvent);
        qDebug()<<"MOUSE X "<< idevice->getCursorControl()->getPosition().X<<"\tMOUSE Y "<<idevice->getCursorControl()->getPosition().Y;
}
void IrrQWidget::mouseMoveEvent(QMouseEvent *event){
    if (idevice != 0){
        sendMouseEventToIrrlicht(event, false);
        drawIrrlichtScene();
    }
    event->ignore();
}
void IrrQWidget::mousePressEvent( QMouseEvent* event ){
    if (idevice != 0){
            sendMouseEventToIrrlicht(event, true);
            drawIrrlichtScene();
    }
    event->ignore();
}
void IrrQWidget::mouseReleaseEvent( QMouseEvent* event){
    if (idevice != 0){
            sendMouseEventToIrrlicht(event, false);
            drawIrrlichtScene();
    }
    event->ignore();
}
//------------------------------------FIM-EVENTOS-DE-MOUSE---------------------------------------//
