#ifndef IRRNODE_H
#define IRRNODE_H

#include"irrviewer.h"
typedef irr::core::vector3df Vector3df;
class IrrNode
{
private:

    irr::scene::ITriangleSelector* seletor;
    irr::scene::ISceneNode* selectedSceneNode;
    Pos3df position;
    Dim3df dimension;
    bool first_cube;

public:

    IrrNode();
    irr::scene::ISceneNode* getNode()const {return selectedSceneNode;}
    void criaCubo(const int* id, IrrSmgr* const , const Pos3df&, const Dim3df&);
    void criaReta();
    void criaEsfera();
    void criaCone();
    void criaGizmo( irr::scene::ISceneNode* , IrrSmgr* const);
};

#endif // IRRNODE_H
