#ifndef IRRVIEWER_H
#define IRRVIEWER_H
#include<irrlicht.h>
#include <QtGui>
#include "myeventreceiver.h"

typedef irr::core::vector3df Pos3df;
typedef irr::core::vector3df Dim3df;
typedef irr::scene::ISceneManager IrrSmgr;

enum {ID_IsNotPickable = 0, IDFlag_IsPickable = 1 << 0, IDFlag_IsHighlightable = 1 << 1 };

typedef irr::core::vector3df Vector3df;

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





