#ifndef IRRNODE_H
#define IRRNODE_H

#include"irrviewer.h"

class IrrNode
{
private:
    irr::scene::ITriangleSelector* seletor;
    irr::scene::ISceneNode* selectedSceneNode;

public:
    IrrNode();
    irr::scene::ISceneNode* getNode()const {return selectedSceneNode;}
    float delta;
    irr::video::SColor color;

    void criaCubo(IrrSmgr* const,
                  nodeParam* param,
                  const irr::c8* nodeName);

    void criaHaste(IrrSmgr* const smgr,
                   nodeParam *param,
                   const irr::c8* nodeName);

    void criaCilindro(IrrSmgr* const smgr,
                      nodeParam *param,
                      const irr::c8* nodeName);

    void criaEsfera(IrrSmgr* const smgr,
                    nodeParam *param,
                    const irr::c8* nodeName);

    void criaPonto(IrrSmgr* const smgr,
                    nodeParam *param,
                    const irr::c8* nodeName);


    void criaCone(IrrSmgr* const smgr,
                  nodeParam *param,
                  const irr::c8* nodeName);

    void criaAntenna(IrrSmgr* const smgr,
                        const Vector3df& position,
                        const irr::c8* nodeName);

    void criaGizmo( IrrSmgr* const,
                    irr::scene::IMeshSceneNode **gizmo_X,
                    irr::scene::IMeshSceneNode **gizmo_Y,
                    irr::scene::IMeshSceneNode **gizmo_Z,
                    const irr::core::aabbox3df& box) ;

    void gizmosRegiaoAnalise( IrrSmgr* const,
                    irr::scene::IMeshSceneNode **r_analise_gizmo_X,
                    irr::scene::IMeshSceneNode **r_analise_gizmo_Y,
                    irr::scene::IMeshSceneNode **r_analise_gizmo_Z,
                    const Dim3df&);

    irr::scene::IMesh* createCube(const Vector3df& size) const;
};

#endif // IRRNODE_H
