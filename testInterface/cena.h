
#ifndef CENA_H
#define CENA_H

#include <utility>
#include <QObject>
#include <map>
#include <vector>
#include <set>
#include <QKeyEvent>
#include "irrviewer.h"
#include "irrnode.h"
#include "mainwindow.h"

#define PI 3,14159265

class Cena: public IrrViewer
{
//    Q_OBJECT
private:

    irr::scene::ILightSceneNode *light;
    irr::scene::ISceneCollisionManager *collMan;
    irr::scene::ITriangleSelector* seletor;

    irr::scene::IMeshSceneNode *gizmo_X;
    irr::scene::IMeshSceneNode *gizmo_Y;
    irr::scene::IMeshSceneNode *gizmo_Z;

    irr::scene::IMeshSceneNode *r_analise_gizmo_X;
    irr::scene::IMeshSceneNode *r_analise_gizmo_Y;
    irr::scene::IMeshSceneNode *r_analise_gizmo_Z;

    bool duplicateNode_mouse_key;

    bool key_m_on;
    bool key_x_on;
    bool key_y_on;
    bool key_z_on;

    bool camera_01;
    bool camera_02;
    bool camera_03;
    bool camera_04;
    bool camera_05;
    bool camera_06;

    float aproxima, afasta ;

    double xi;
    double yi;
    double zi;

    Pos3df mouse_press_position;
    Pos3df mouse_release_position;

public:
    Cena();
    ~Cena();

    irr::scene::ISceneNode *selectedSceneNode;
    irr::scene::ISceneNode *MoveSceneNode;

    bool mouse_key_test;
    irr::core::aabbox3df box;

    float mouseXi;
    float mouseYi;

    float dx;
    float dy;

    void insertCubo(IrrNode* node);
    void insertEsfera(IrrNode* node);
    void insertCone(IrrNode* node);
    void insertCilindro(IrrNode* node);

    inline void removeSceneNode();
    inline void duplicateSceneNode();

    inline void gizmo();
    void cenaIrrlicht();

    void aproximaObjetoSelecionado();

    inline void selection();
    inline void cenaCameras();
    inline void criaRegiaoAnalise();
    inline void cenaIluminacao();
    inline void cenaVisualizacoes();

    void drawIrrlichtScene();

    void keyPressEvent(QKeyEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown);

//signals:
//    void send_x_changed();


};  //fim da classe Cena
#endif // CENA_H
