#include "irrnode.h"

IrrNode::IrrNode():selectedSceneNode(0),first_cube(true)
{
}

void IrrNode::criaCubo(const int* id, IrrSmgr* const smgr, const Pos3df& pos, const Dim3df& dim)
{
    if(smgr){
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cube_node = geo->createCubeMesh(dim);
        irr::scene::IMeshSceneNode *cube_node = smgr->addMeshSceneNode(mesh_cube_node);
        if (cube_node){
          cube_node->setPosition(pos);
//          cube_node->setID(irr::s32 (*id));
//          first_cube = false;
//          cube_node->setParent(  smgr->getSceneNodeFromId(irr::u32(0) ) );
          seletor = smgr->createOctTreeTriangleSelector(cube_node->getMesh(), cube_node, 128);
          cube_node->setTriangleSelector(seletor);
          seletor->drop();
          selectedSceneNode = (irr::scene::ISceneNode*)cube_node;
        }

        this->position = pos;
        this->dimension = dim;
    }
}

void IrrNode::criaCone(){
//    const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();

}

void IrrNode::criaReta(){
//    const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();

}

void IrrNode::criaEsfera(){
//    const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();

}
