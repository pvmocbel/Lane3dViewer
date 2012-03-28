#ifndef CENA_H
#define CENA_H

#include <utility>
#include <map>
#include <vector>
#include <set>
#include <QKeyEvent>
#include "irrviewer.h"
#include "irrnode.h"

typedef std::pair<int, int> PairInt;
typedef std::map<int, std::map<int, std::set<int> > > MapNodes;

typedef irr::core::vector3df Vector3df;

class Cena: public IrrViewer
{
private:

    irr::scene::ISceneNode *highlightedSceneNode;
    irr::scene::ISceneNode *selectedSceneNode;
    irr::scene::ICameraSceneNode *camera;
    irr::scene::ILightSceneNode *light;
    irr::scene::ISceneCollisionManager *collMan;

    std::map<int, IrrNode*> nodes;

    bool duplicateNode_mouse_key;
    bool key_m_on;

    Vector3df mouse_press_position;
    Vector3df mouse_release_position;

public:
    Cena();

    ~Cena();

    int get_serialize_id(){
        static int id = 0;
        ++id;
        return id;
    }

    bool mouse_key_test;

    void insertNode(int id, IrrNode* node);
    IrrNode* getNode(int id);

    void cenaIrrlicht();
    inline void cenaCameras();
    inline void cenaIluminacao();
    inline void cenaVisualizacoes();

    inline void removeSceneNode();
    inline void duplicateSceneNode();
    inline void moveSceneNode(Vector3df );

    void drawIrrlichtScene();

    void keyPressEvent(QKeyEvent *event);

    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown);

};  //fim da classe Cena

#endif // CENA_H
