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
                 const irr::c8* nodeName);

    void criaLinha(IrrSmgr* const smgr,
                   const Pos3df& pos,
                   const Dim3df& dim,
                   double ang1,
                   double ang2,
                   const irr::c8* nodeName);

    void criaCilindro(IrrSmgr* const smgr,
                      const Pos3df& pos,
                      const Dim3df& dim,
                      const irr::c8* nodeName);

    void criaEsfera(IrrSmgr* const smgr,
                    const Pos3df& pos,
                    const double raio,
                    const irr::c8* nodeName);

    void criaCone(IrrSmgr* const smgr,
                  const Pos3df& pos,
                  const Dim3df& dim,
                  const irr::c8* nodeName);

    void criaGizmo( IrrSmgr* const,
                    irr::scene::IMeshSceneNode **gizmo_X,
                    irr::scene::IMeshSceneNode **gizmo_Y,
                    irr::scene::IMeshSceneNode **gizmo_Z);

    void gizmosRegiaoAnalise( IrrSmgr* const,
                    irr::scene::IMeshSceneNode **r_analise_gizmo_X,
                    irr::scene::IMeshSceneNode **r_analise_gizmo_Y,
                    irr::scene::IMeshSceneNode **r_analise_gizmo_Z,
                    const Dim3df& dim);
};

#endif // IRRNODE_H
