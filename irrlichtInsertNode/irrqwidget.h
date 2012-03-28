#ifndef IRRQWIDGET_H
#define IRRQWIDGET_H
#include <QtGui>
#include <irrlicht.h>
#include "irrqwidget.h"
#include "myeventreceiver.cpp"
#include <math.h>

using namespace irr;
using namespace irr::video;
using namespace irr::core;
using namespace irr::scene;
using namespace irr::gui;

enum {ID_IsNotPickable = 0, IDFlag_IsPickable = 1 << 0, IDFlag_IsHighlightable = 1 << 1 };

class IrrQWidget : public QWidget{
    Q_OBJECT
public:
    IrrQWidget(QWidget *parent = 0);
    ~IrrQWidget();
    void createCubo();
    void createCone();
    void createLinha();
    void createEsfera();
    void drawIrrlichtScene();
    void deleteNo(ISceneNode* node);
    void buildIrrlichtScene();
    void createIrrlichtDevice();
//-------------------------EVENTOS-DE-MOUSE---------------------------//
    void mouseMoveEvent( QMouseEvent* event );
    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown);
//-------------------------PARAMETROS-IRRLICHT---------------------------//
    ISceneManager *getIrrlichtScene(){ return iscene; }
    IVideoDriver *getIrrlichtDrive(){ return idriver; }
    IrrlichtDevice *getIrrlichtDevice(){ return idevice; }

    virtual QPaintEngine * paintEngine() const;
    virtual void resizeEvent( QResizeEvent *event );
    virtual void paintEvent( QPaintEvent *event );

    static const int DESLOC=1<<2;
    static const int ROT=1<<1;
    static const int SCALA=1<<0;
    int rot;
    int MANIPULADOR;
    bool maniATIVA;
signals:
public slots:
protected:
    E_DRIVER_TYPE driverType;

private:
    IrrlichtDevice *idevice;
    ISceneManager *iscene;
    IVideoDriver *idriver;
    IGUIEnvironment *iguienv;
    MyEventReceiver receiver;
    const IGeometryCreator *geo;

    ICameraSceneNode *camera;
    ITriangleSelector* seletor;
    ISceneNode* selectedSceneNode;
    ISceneCollisionManager* collMan;
    ISceneNode* highlightedSceneNode;
    ISceneNode* node2;

    vector3df posicao;
    IMesh* mesh_seguidor;
    IMesh* mesh_cube;
    IMeshSceneNode *seguidor;
    IMeshSceneNode *cube;
    double i;
    double xI, yI, zI;
    double mouseXi,mouseYi,dx,dy;
};
#endif // IRRQWIDGET_H
