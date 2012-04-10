#include "irrnode.h"

IrrNode::IrrNode():selectedSceneNode(0),first_cube(true)
{
}

void IrrNode::criaCubo(const int* id, IrrSmgr* const smgr, const Pos3df& pos, const Dim3df& dim, irr::video::IVideoDriver *video_driver)
{
    if(smgr){
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cube_node = geo->createCubeMesh(dim);
        irr::scene::IMeshSceneNode *cube_node = smgr->addMeshSceneNode(mesh_cube_node);
        if (cube_node){
          cube_node->setPosition(pos);
          cube_node->setMaterialTexture(0,video_driver->getTexture("./media/rockwall.jpg"));
          cube_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          cube_node->setID(IDFlag_IsPickable);
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

void IrrNode::criaGizmo(irr::scene::ISceneNode* node, IrrSmgr* const smgr, irr::scene::IMeshSceneNode* gizmo_X,
                        irr::scene::IMeshSceneNode* gizmo_Y, irr::scene::IMeshSceneNode* gizmo_Z)
{
    const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();

    irr::scene::IMesh *mesh_gizmo_X = geo->createArrowMesh( 4, 8, 20.0f, 10.0f, 0.08f, 0.3f, irr::video::SColor(255,235,200,100), irr::video::SColor(255) );
//    irr::scene::IMesh *mesh_gizmo_Y = geo->createArrowMesh( 4, 8, 20.0f, 10.0f, 0.08f, 0.3f, irr::video::SColor(255,235,200,100), irr::video::SColor(255) );
//    irr::scene::IMesh *mesh_gizmo_Z = geo->createArrowMesh( 4, 8, 20.0f, 10.0f, 0.08f, 0.3f, irr::video::SColor(255,235,200,100), irr::video::SColor(255) );

    gizmo_X = smgr->addMeshSceneNode(mesh_gizmo_X);
//    gizmo_Y = smgr->addMeshSceneNode(mesh_gizmo_Y);
//    gizmo_Z = smgr->addMeshSceneNode(mesh_gizmo_Z);

    if(gizmo_X /*&& gizmo_Y && gizmo_Z*/){

//        gizmo_X->setPosition(Vector3df(node->getPosition().X, node->getPosition().Y, node->getPosition().Z));
        gizmo_X->setID(IDFlag_IsPickable|1<<2);
        gizmo_X->setPosition(Vector3df(0,0,0));
        seletor = smgr->createOctTreeTriangleSelector(gizmo_X->getMesh(),gizmo_X,128);
        gizmo_X->setTriangleSelector(seletor);
        seletor->drop();
        selectedSceneNode = (irr::scene::ISceneNode*)gizmo_X;

//        gizmo_Y->setRotation(Vector3df(0,0,90));
////        gizmo_Y->setPosition(Vector3df(node->getPosition().X, node->getPosition().Y, node->getPosition().Z));
//        gizmo_Y->setPosition(Vector3df(0,0,0));
//        seletor = smgr->createOctTreeTriangleSelector(gizmo_Y->getMesh(),gizmo_Y,128);
//        gizmo_Y->setTriangleSelector(seletor);
//        seletor->drop();

//        gizmo_Z->setRotation(Vector3df(-90,0,0));
////        gizmo_Z->setPosition(Vector3df(node->getPosition().X, node->getPosition().Y, node->getPosition().Z));
//        seletor = smgr->createOctTreeTriangleSelector(gizmo_Z->getMesh(),gizmo_Z,128);
//        gizmo_Z->setTriangleSelector(seletor);
//        seletor->drop();
    }
}
