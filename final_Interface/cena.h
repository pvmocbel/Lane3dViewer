
#ifndef CENA_H
#define CENA_H

#include <utility>
#include <QObject>
#include <mainwindow.h>
#include <map>
#include <vector>
#include <set>
#include <QKeyEvent>
#include "irrviewer.h"
#include "irrnode.h"

#define PI 3,14159265

class Cena: public IrrViewer
{
//    Q_OBJECT
private:
    irr::scene::ISceneNode *MoveSceneNode;
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
    irr::scene::ISceneNode *selectedSceneNode;

    Cena();
    ~Cena();
    void init();

    bool mouse_key_test;
    irr::core::aabbox3df box;

    float mouseXi;
    float mouseYi;

    float dx;
    float dy;

    void insertCubo(IrrNode* node, const Dim3df& dim, const Pos3df& p);
    void insertEsfera(IrrNode* node);
    void insertCone(IrrNode* node);
    void insertCilindro(IrrNode* node);

    void change_x_position(float x);
    void change_y_position(float y);
    void change_z_position(float z);

    void return_change_x_position(float x);
    void return_change_y_position(float y);
    void return_change_z_position(float z);

    void printRegiaoAnalise(irr::core::aabbox3df box);

    inline void removeSceneNode();
    inline void duplicateSceneNode();

    inline void gizmo();
    void cenaIrrlicht();

    void aproximaObjetoSelecionado();

    inline void selection();
    inline void cenaCameras();
    void criaRegiaoAnalise(const Dim3df& dim, double delta);
    inline void cenaIluminacao();

    void drawIrrlichtScene();

    void keyPressEvent(QKeyEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown);

//signals:
//    void change_value(float);

};  //fim da classe Cena
#endif // CENA_H
