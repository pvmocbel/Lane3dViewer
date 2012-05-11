#ifndef CENA_H
#define CENA_H

#include <mainwindow.h>
#include "irrviewer.h"
#include "irrnode.h"

#define PI 3,14159265

typedef struct NodeParameters{
    Vector3df position;
    Vector3df dimension;
    double permissividade, permiabilidade, condutibilidade;
} nodeParam;

typedef std::map<std::string, int> NodeID;
typedef NodeID::iterator No;
typedef std::map<int, nodeParam> MapNode;
typedef MapNode::iterator It;

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

    MapNode myMap;
    NodeID nodeId;
    No no;
    It it;

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

    void insertLinha(int, IrrNode* node, const Pos3df& inicial, const Pos3df& final);
    void insertCubo(int, IrrNode* node, const Dim3df& dim, const Pos3df& p, const Vector3df& parameters);
    void insertEsfera(int, IrrNode* node, const Dim3df& dim, const Pos3df& p, const Vector3df& parameters);
    void insertCone(int, IrrNode* node, const Dim3df &dim, const Pos3df &p, const Vector3df& parameters);
    void insertCilindro(int, IrrNode* node, const Dim3df &dim, const Pos3df &p, const Vector3df& parameters);

    Vector3df getDimensionFromId(int id){
        for(it = myMap.begin(); it != myMap.end(); it++){
            if((it->first) ==  id){
                return it->second.dimension;
                break;
            }
        }
        if(it == myMap.end()){
            Vector3df aux_dim;
            aux_dim.set(1,1,1);
            return aux_dim;
        }
    }

    Vector3df getPositionFromId(int id){
        for(it = myMap.begin(); it != myMap.end(); it++){
            if((it->first) ==  id){
                return it->second.position;
                break;
            }
        }
        if(it == myMap.end()){
            Vector3df aux_dim;
            aux_dim.set(1,1,1);
            return aux_dim;
        }
    }

    double getCondutFromId(int id){
        for(it = myMap.begin(); it != myMap.end(); it++){
            if((it->first) ==  id){
                return it->second.condutibilidade;
                break;
            }
        }
        if(it == myMap.end())
           return 0;
    }

    double getPermiabFromId(int id){
        for(it = myMap.begin(); it != myMap.end(); it++){
            if((it->first) ==  id){
                return it->second.permiabilidade;
                break;
            }
        }
        if(it == myMap.end())
           return 0;
    }

    double getPermissiFromId(int id){
        for(it = myMap.begin(); it != myMap.end(); it++){
            if((it->first) ==  id){
                return it->second.permissividade;
                break;
            }
        }
        if(it == myMap.end())
           return 0;
    }

    int getIdFromNode(std::string nodeName){
        for(no = nodeId.begin(); no != nodeId.end(); no++){
            if((no->first) == nodeName){
                return no->second;
                break;
            }
        }
        return 0;
    }

    void setDimension(int id, Dim3df dim){
//        dimMap[id] = dim;
    }

    void printRegiaoAnalise(irr::core::aabbox3df box);

    inline void removeSceneNode();
    void removeSceneNodeFromNode(irr::scene::ISceneNode*);
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
    virtual void receiver_changed_dimension_mainwindow(const Dim3df& pos, int eixo);

};  //fim da classe Cena
#endif // CENA_H
