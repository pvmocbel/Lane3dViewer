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

    void criaCilindro(IrrSmgr* const smgr, const Pos3df& pos, const Dim3df& dim);

    void criaEsfera(IrrSmgr* const smgr, const Pos3df& pos, const double raio);

    void criaCone(IrrSmgr* const smgr, const Pos3df& pos, const Dim3df& dim);

    void criaGizmo( IrrSmgr* const,
                    irr::scene::IMeshSceneNode **gizmo_X,
                    irr::scene::IMeshSceneNode **gizmo_Y,
                    irr::scene::IMeshSceneNode **gizmo_Z,
                    irr::video::IVideoDriver *video_driver);

    void criaRegiaoLivre(IrrSmgr* const,
                         const Dim3df&);

    void criaRegiaoAnalise(IrrSmgr* const,
                           const Dim3df&);
};

#endif // IRRNODE_H
