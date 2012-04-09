#ifndef IRRNODE_H
#define IRRNODE_H

#include"irrviewer.h"

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
};

#endif // IRRNODE_H
