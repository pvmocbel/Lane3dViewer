
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

typedef std::map<int, Dim3df> DimMap;
typedef DimMap::iterator It;

//typedef std::map<int, irr::c8>

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

    DimMap dimMap;

    Pos3df mouse_press_position;
    Pos3df mouse_release_position;

public:
    Cena();
    ~Cena();
    void init();

    int get_serialize_id(){
       static int id = 0;
       ++id;
       return id;
    }

    irr::scene::ISceneNode *selectedSceneNode;
    irr::core::aabbox3df box;

    bool mouse_key_test;
    float mouseXi;
    float mouseYi;

    float dx;
    float dy;

    void insertCubo(int, IrrNode* node, const Dim3df& dim, const Pos3df& p);
    void insertEsfera(int, IrrNode* node, const Dim3df& dim, const Pos3df& p);
    void insertCone(int, IrrNode* node, const Dim3df &dim, const Pos3df &p);
    void insertCilindro(int, IrrNode* node, const Dim3df &dim, const Pos3df &p);

    const Dim3df& getDimensionFronId(int id){
        return dimMap.find(id)->second;
    }

    void setDimension(int id, const Dim3df& dim){
        dimMap[id] = dim;
    }

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

public slots:
    virtual void receiver_changed_position_mainwindow(const Pos3df& pos);
    virtual void receiver_changed_dimension_mainwindow(const Dim3df& pos);

};  //fim da classe Cena
#endif // CENA_H
