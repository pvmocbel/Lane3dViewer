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
    void criaCubo(IrrSmgr* const,
                  const Pos3df&,
                  const Dim3df&,
                  irr::video::IVideoDriver *video_driver);
    void criaReta();
    void criaEsfera();
    void criaCone();
    void criaGizmo( const Pos3df& ,
                    IrrSmgr* const,
//                    irr::scene::IMeshSceneNode **gizmo_X,
                    irr::scene::IMeshSceneNode **gizmo_Y
                   /* irr::scene::IMeshSceneNode **gizmo_Z*/);
};

#endif // IRRNODE_H
