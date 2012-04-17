#ifndef IRRVIEWER_H
#define IRRVIEWER_H
#include<irrlicht.h>
#include <QtGui>
#include "myeventreceiver.h"

typedef irr::core::vector3df Pos3df;
typedef irr::core::vector3df Dim3df;
typedef irr::core::vector3df Vector3df;
typedef irr::scene::ISceneManager IrrSmgr;

enum { MASK = 0xFFFF << 1};
enum { S = 1 << 0, A = 1 << 1, B = 1 << 2, C = 1 << 3 , D = 1<<4};
enum { ID_FLAG_GIZMO_X = 0, ID_FLAG_GIZMO_Y = A, ID_FLAG_GIZMO_Z = B,
       ID_FLAG_CUBO = A|B, ID_FLAG_ESFERA = C, ID_FLAG_CONE = C|A,
       ID_FLAG_CILINDRO = C|B};

class IrrViewer : public QWidget
{
    Q_OBJECT
protected:
    irr::IrrlichtDevice *device;
    irr::gui::IGUIEnvironment *env;
    irr::scene::ISceneManager* smgr;
    irr::video::E_DRIVER_TYPE driveType;
    irr::video::IVideoDriver *video_driver;
    eventReceiver::MyEventReceiver receiver;

    irr::scene::ICameraSceneNode* camera;
    irr::scene::ILightSceneNode* light;

public:
    IrrViewer(QWidget *);
    ~IrrViewer();

    virtual void drawIrrlichtScene();
    void createIrrichtDevice();
    virtual void paintEvent( QPaintEvent *event );
    virtual void resizeEvent( QResizeEvent *event );
    virtual QPaintEngine * paintEngine() const;

};//fim da class irrViewer

#endif // IRRVIEWER_H





