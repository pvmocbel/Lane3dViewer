#ifndef IRRVIEWER_H
#define IRRVIEWER_H

#include <irrlicht.h>
#include <utility>
#include <iostream>
#include <string>
#include <QtGui>
#include <QObject>
#include <map>
#include <stdio.h>
#include <QKeyEvent>
#include "myeventreceiver.h"
#include <stdio.h>
#include <fstream>

typedef irr::core::vector3di intVector;
typedef irr::core::vector3df Pos3df;
typedef irr::core::vector3df Dim3df;
typedef irr::core::vector3df Vector3df;
typedef irr::scene::ISceneManager IrrSmgr;
typedef irr::video::IVideoDriver VideoDriver;

#define PI 3,14159265

enum { MASK = 0xFFFF << 1};
enum { S = 1 << 0, A = 1 << 1, B = 1 << 2, C = 1 << 3 , D = 1<<4};
enum { ID_FLAG_GIZMO_X = 0, ID_FLAG_GIZMO_Y = A, ID_FLAG_GIZMO_Z = B,
       ID_FLAG_CUBO = A|B, ID_FLAG_ESFERA = C, ID_FLAG_CONE = C|A,
       ID_FLAG_CILINDRO = C|B, ID_FLAG_HASTE = C|B|A ,
       ID_FLAG_PONTO = D, ID_FLAG_ANTENNA = A|D};

enum NodeType{Haste, Cube, Esphere, Cone, Cilindro, Antenna};

typedef struct NodeParameters{
    Vector3df position;
    Vector3df dimension;
    Vector3df dimension2;
    float raio_haste;
    Vector3df parametros;
    int propriedade;
    irr::core::aabbox3df box;
    NodeType type;
} nodeParam;

struct nodeDimensions{
    Vector3df dimension;
    Vector3df dimension2;
    Vector3df parametros;
    Vector3df position;
    int propriedade;
    float raio_haste;
};


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

signals:
    void send_position_change();
    void send_dimension();
    void send_selection_call(nodeDimensions*);

public slots:
      virtual void receiver_changed_position_mainwindow(const Pos3df& pos);
      virtual void receiver_changed_dimension(nodeParam*);
      virtual void receiver_changed_material_parameter(const Vector3df&, int);
      virtual void receiver_changed_propriedade(int,int);

};//fim da class irrViewer

#endif // IRRVIEWER_H





