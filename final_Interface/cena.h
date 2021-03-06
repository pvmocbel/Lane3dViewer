#ifndef CENA_H
#define CENA_H

#include <mainwindow.h>
#include "irrviewer.h"
#include "irrnode.h"


typedef struct CELULA{
    intVector position;
    Vector3df dimension;
    double permissividade, permiabilidade, condutibilidade;
}Celula;

typedef std::vector<Celula> CelulaArray;

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

    float fator;
    Vector3df dim;
    double delta;

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

    void parametros(NodeParameters *, int);
    void save();
    void load();
    void geraMalha();
    void geraMalhaCube(irr::core::aabbox3df box, const nodeParam& , FILE *file);
    void geraMalhaCone(const nodeParam &param, FILE *file);
    void geraMalhaEsfera(irr::core::aabbox3df box, const nodeParam&, FILE *file);
    void geraMalhaCilindro(irr::core::aabbox3df box, const nodeParam&, FILE *file);
    void geraMalhaAntenna(const Vector3df &position, FILE *file, FILE* file2);

    void insertHaste(int , IrrNode* node, nodeParam*);
    void insertHasteChanged(IrrNode* node, nodeParam*, int);

    void insertCubo(int, IrrNode* node, nodeParam *);
    void insertCuboChanged(IrrNode* node, nodeParam*, int);

    void insertEsfera(int, IrrNode* node, nodeParam*);
    void insertEsferaChanged(IrrNode* node, nodeParam*, int);

    void insertCone(int, IrrNode* node, nodeParam*);
    void insertConeChanged(IrrNode* node, nodeParam*, int);

    void insertCilindro(int, IrrNode* node, nodeParam*);
    void insertCilindroChanged(IrrNode* node, nodeParam*, int);

    void insertAntenna(int, IrrNode*node, const Vector3df&position);

    int getIdFromNode(std::string nodeName){
        if(nodeId.find(nodeName)==nodeId.end()){
            return 0;
        }
        return nodeId[nodeName];
    }

    int calcula_raio(const intVector& p1, const intVector& p2);
    int calcula_raio2(const intVector& p1, const intVector& p2);

    inline void removeSceneNode();
    void removeChangedSceneNode();
    inline void duplicateSceneNode();

    inline void gizmo();
    void cenaIrrlicht();

    void aproximaObjetoSelecionado();

    inline void selection();
    inline void cenaCameras();
    void criaRegiaoAnalise(const Dim3df& dim, double delta);
    inline void cenaIluminacao();

    void printRegiaoAnalise(irr::core::aabbox3df box);
    void drawIrrlichtScene();
    void keyPressEvent(QKeyEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown);

public slots:
    virtual void receiver_changed_position_mainwindow(const Pos3df& pos);
    virtual void receiver_changed_dimension(nodeParam*);
    virtual void receiver_changed_material_parameter(const Vector3df &, int);
    virtual void receiver_changed_propriedade(int, int);

};  //fim da classe Cena
#endif // CENA_H
