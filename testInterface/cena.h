#ifndef CENA_H
#define CENA_H

#include <utility>
#include <map>
#include <vector>
#include <set>
#include <QKeyEvent>
#include "irrviewer.h"
#include "irrnode.h"

class Cena: public IrrViewer
{
private:
    irr::scene::ISceneNode *selectedSceneNode;
    irr::scene::ISceneNode *MoveSceneNode;
    irr::scene::ICameraSceneNode *camera[4];
    irr::scene::ILightSceneNode *light;
    irr::scene::ISceneCollisionManager *collMan;

    irr::scene::IMeshSceneNode *gizmo_X;
    irr::scene::IMeshSceneNode *gizmo_Y;
    irr::scene::IMeshSceneNode *gizmo_Z;

    bool duplicateNode_mouse_key;

    bool key_m_on;
    bool key_w_on;
    bool key_x_on;
    bool key_y_on;
    bool key_z_on;

    double xi;
    double yi;
    double zi;

    Pos3df mouse_press_position;
    Pos3df mouse_release_position;

public:
    Cena();
    ~Cena();

    bool mouse_key_test;

    float mouseXi;
    float mouseYi;
    float dx;
    float dy;

    void insertCubo(IrrNode* node);
    void insertEsfera(IrrNode* node);
    void insertCone(IrrNode* node);
    void insertCilindro(IrrNode* node);

    inline void gizmo();
    void cenaIrrlicht();
    inline void cenaCameras();
    inline void selection();
    inline void cenaIluminacao();
    inline void cenaVisualizacoes();

    inline void removeSceneNode();
    inline void duplicateSceneNode();

    void drawIrrlichtScene();

    void keyPressEvent(QKeyEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown);

};  //fim da classe Cena
#endif // CENA_H
