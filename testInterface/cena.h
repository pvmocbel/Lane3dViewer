
#ifndef CENA_H
#define CENA_H

#include <utility>
#include <map>
#include <vector>
#include <set>
#include <QKeyEvent>
#include "irrviewer.h"
#include "irrnode.h"

#define PI 3,14159265

class Cena: public IrrViewer
{
private:
    irr::scene::ISceneNode *selectedSceneNode;
    irr::scene::ISceneNode *MoveSceneNode;
    irr::scene::ICameraSceneNode *camera;
    irr::scene::ILightSceneNode *light;
    irr::scene::ISceneCollisionManager *collMan;

    irr::scene::IMeshSceneNode *gizmo_X;
    irr::scene::IMeshSceneNode *gizmo_Y;
    irr::scene::IMeshSceneNode *gizmo_Z;

    Vector3df vetor_normal_n;
    Vector3df vetor_normal;
    Vector3df vetor_target;

    bool duplicateNode_mouse_key;

    bool key_m_on;
    bool key_w_on;
    bool key_x_on;
    bool key_y_on;
    bool key_z_on;

    irr::core::matrix4 matrix;

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

    int fat_dx,fat_dy,fat_dz;

    int fator_x_dx;
    int fator_x_dy;

    int fator_y_dx;
    int fator_y_dy;

    int fator_z_dx;
    int fator_z_dy;


    void insertCubo(IrrNode* node);
    void insertEsfera(IrrNode* node);
    void insertCone(IrrNode* node);
    void insertCilindro(IrrNode* node);

    inline void removeSceneNode();
    inline void duplicateSceneNode();

    inline void gizmo();
    void cenaIrrlicht();

    void atualizaFatores();
    inline void selection();
    inline void cenaCameras();
    inline void criaRegiaoAnalise();
    inline void criaRegiaoLivre();
    inline void cenaIluminacao();
    inline void cenaVisualizacoes();

    void drawIrrlichtScene();

    void keyPressEvent(QKeyEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown);

};  //fim da classe Cena
#endif // CENA_H
