#include "irrviewer.h"

IrrViewer::IrrViewer(QWidget *_parent=0):QWidget(_parent)
  ,device(0),smgr(0),video_driver(0),env(0),camera(0),
   driveType(irr::video::EDT_BURNINGSVIDEO)
{}


IrrViewer::~IrrViewer()
{
    if (device) {
        device->closeDevice();
        device->run();
        device->drop();
    }
}

void IrrViewer::createIrrichtDevice()
{
    if (device) return;

    irr::SIrrlichtCreationParameters params;

    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NoSystemBackground);

    create(winId(), false, false);

    params.DriverType = driveType;
    params.WindowId = reinterpret_cast<void*>(winId());
    params.WindowSize.Width = width();
    params.WindowSize.Height = height();
    params.EventReceiver = &receiver;

    device = createDeviceEx(params);
    setAttribute(Qt::WA_OpaquePaintEvent);

    video_driver  = device->getVideoDriver();
    smgr  = device->getSceneManager();
    env = device->getGUIEnvironment();
}

void IrrViewer::receiver_changed_position_mainwindow(const Pos3df& pos){
    receiver_changed_position_mainwindow(pos);
}

void IrrViewer::receiver_changed_dimension_mainwindow(const Dim3df& dim, int eixo){
    receiver_changed_dimension_mainwindow(dim, eixo);
}

void IrrViewer::receiver_changed_dimension(nodeParam* param){
    receiver_changed_dimension(param);
}

void IrrViewer::paintEvent( QPaintEvent *event )
{
    if (device) {
        QWidget::paintEvent(event);
        drawIrrlichtScene();
    }
}

void IrrViewer::resizeEvent( QResizeEvent *event )
{
    if (device) {
        irr::core::dimension2d<unsigned> size;
        size.Width = event->size().width();
        size.Height = event->size().height();
        video_driver->OnResize(size);
        if(camera)
            camera->setAspectRatio((float)(size.Width/size.Height));
     }
    QWidget::resizeEvent(event);
}

QPaintEngine* IrrViewer::paintEngine() const
{
    if (device) {
        QWidget::paintEngine();
        return 0;
    }
}

void IrrViewer::drawIrrlichtScene()
{
    if (device) {
        video_driver->beginScene( true, true, irr::video::SColor( 255, 128, 128, 128 ));
        smgr->drawAll();
        env->drawAll();
        video_driver->endScene();
    }
}
