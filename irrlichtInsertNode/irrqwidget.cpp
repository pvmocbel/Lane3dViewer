#include "irrqwidget.h"

IrrQWidget::IrrQWidget(QWidget *parent) : QWidget(parent){
    i = 10;
    idevice = 0;
    iscene = 0;
    idriver = 0;
    rot =0;
    driverType = irr::video::EDT_SOFTWARE;
    selectedSceneNode = 0;
    highlightedSceneNode = 0;
    seletor = 0;
}

IrrQWidget::~IrrQWidget(){
    if (idevice != 0){
        idevice->closeDevice();
        idevice->run();
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
        geo = iscene->getGeometryCreator();

        ILightSceneNode *light = iscene->addLightSceneNode();
        light->setLightType( ELT_DIRECTIONAL );
        light->setRotation( vector3df( 45.0f, 45.0f, 0.0f ));
        light->getLightData().AmbientColor = SColorf( 0.2f, 0.2f, 0.2f, 1.0f );
        light->getLightData().DiffuseColor = SColorf( 0.8f, 0.8f, 0.8f, 1.0f );

        camera = iscene->addCameraSceneNodeFPS();
        camera->setPosition(vector3df(0,0,-90));
        camera->setTarget(vector3df(0,0,0));
    }
}

void IrrQWidget::drawIrrlichtScene(){
    if(idevice != 0){
      rot+=1;
      vector3df intersection;
      triangle3df tri;

      line3df ray = iscene->getSceneCollisionManager()->getRayFromScreenCoordinates(idevice->getCursorControl()->getPosition(), camera);

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

void IrrQWidget::resizeEvent(QResizeEvent* event){
    if ( idevice != 0 ){
        dimension2d<unsigned> size;
        size.Width = event->size().width();
        size.Height = event->size().height();
        idevice->getVideoDriver()->OnResize(size);
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

void IrrQWidget::createCubo(){
    if(idevice!=0){
        IMesh *mesh_cube_node = geo->createCubeMesh(vector3df(20,20,20));
        IMeshSceneNode *cube_node = iscene->addMeshSceneNode(mesh_cube_node);
        if (cube_node){
            cube_node->setPosition(vector3df(40,0,0));
            cube_node->setMaterialFlag(EMF_LIGHTING, false);
            seletor = iscene->createOctTreeTriangleSelector(cube_node->getMesh(), cube_node, 128);
            cube_node->setTriangleSelector(seletor);
            seletor->drop();
            selectedSceneNode = (ISceneNode*)cube_node;
            drawIrrlichtScene();
          }
    }
}

void IrrQWidget::createLinha(){
    if(idevice!=0){
        IMesh *mesh_linha = geo->createCylinderMesh(1.0f,100.0f,10,SColor(255, 255, 0, 0),true,0.f);
        IMeshSceneNode *linha = iscene->addMeshSceneNode(mesh_linha);
        if (linha){
            linha->setMaterialFlag(EMF_LIGHTING, false);
            linha->setPosition(core::vector3df(10,0,0));
            linha->setRotation(core::vector3df(0,0,90));
            seletor = iscene->createOctTreeTriangleSelector(linha->getMesh(), linha, 128);
            linha->setTriangleSelector(seletor);
            seletor->drop();
            selectedSceneNode = (ISceneNode*)linha;
            drawIrrlichtScene();
        }
    }
}

void IrrQWidget::createCone(){
    if(idevice!=0){
        IMesh *mesh_cone = geo->createConeMesh(10.0f,20.0f,40,SColor(),SColor(),0.f);
        IMeshSceneNode *cone2 = iscene->addMeshSceneNode(mesh_cone);
        if (cone2){
                cone2->setMaterialFlag(EMF_LIGHTING, false);
                cone2->setPosition(core::vector3df(0,-35,0));
                seletor = iscene->createOctTreeTriangleSelector(cone2->getMesh(), cone2, 128);
                cone2->setTriangleSelector(seletor);
                seletor->drop();
                selectedSceneNode = (ISceneNode*)cone2;
                drawIrrlichtScene();
        }
    }
}

void IrrQWidget::createEsfera(){
    if(idevice!=0){
        IMesh *mesh_esfera = geo->createSphereMesh(10.0f,16,16);
        IMeshSceneNode *esfera = iscene->addMeshSceneNode(mesh_esfera);
        if (esfera){
                esfera->setMaterialFlag(EMF_LIGHTING, false);
                esfera->setPosition(core::vector3df(20,20,20));
                seletor = iscene->createOctTreeTriangleSelector(esfera->getMesh(), esfera, 128);
                esfera->setTriangleSelector(seletor);
                seletor->drop();
                selectedSceneNode = (ISceneNode*)esfera;
                drawIrrlichtScene();
        }
    }
}
//-----------------------------FIM-OBJETOS-3D-----------------------------------//

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
        irrEvent.MouseInput.X = event->x() - (idriver->getScreenSize().Width)/2;
        irrEvent.MouseInput.Y = event->y() + (idriver->getScreenSize().Height)/2;
        irrEvent.MouseInput.Wheel = 0.0f; // Zero is better than undefined
        idevice->postEventFromUser(irrEvent);
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
