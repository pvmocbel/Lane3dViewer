#include "irrnode.h"


IrrNode::IrrNode():selectedSceneNode(0),first_cube(true)
{
}

void IrrNode::criaPonto(IrrSmgr *const smgr, nodeParam* param, const irr::c8 *nodeName){
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_esfera_node = geo->createSphereMesh(param->dimension.X);
        irr::scene::IMeshSceneNode *esfera_node = smgr->addMeshSceneNode(mesh_esfera_node);

        if (esfera_node)
        {
          esfera_node->setPosition(param->position);
          esfera_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          esfera_node->setID(ID_FLAG_PONTO|S);

          seletor = smgr->createOctTreeTriangleSelector(esfera_node->getMesh(), esfera_node, 128);
          esfera_node->setTriangleSelector(seletor);
          seletor->drop();

          esfera_node->setName(nodeName);

          selectedSceneNode = (irr::scene::ISceneNode*)esfera_node;
        }
    }
}

void IrrNode::criaHaste(IrrSmgr *const smgr, nodeParam *param, const irr::c8 *nodeName){
    if(smgr)
    {
        Vector3df angle;
        Vector3df v1,v2,v3,v4;
        v1.set(1,0,0);
        v2.set(0,1,0);
        v3.set(0,0,1);
        v4.set(param->dimension.X-param->position.X,
               param->dimension.Y-param->position.Y,
               param->dimension.Z-param->position.Z);

        double height = sqrt((param->dimension.X-param->position.X)*(param->dimension.X-param->position.X)
                             +(param->dimension.Y-param->position.Y)*(param->dimension.Y-param->position.Y)
                             +(param->dimension.Z-param->position.Z)*(param->dimension.Z-param->position.Z));

        if(param->position.X != param->dimension.X){
            angle.X = 0;
            angle.Y = 0;
            angle.Z = -90;
        }
        else if(param->position.Y != param->dimension.Y){
            angle.X = 0;
            angle.Y = 0;
            angle.Z = 0;
        }
        else if(param->position.Z != param->dimension.Z){
            angle.X = -90;
            angle.Y = 0;
            angle.Z = 0;                        
        }

        float raio = 0.005;

        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cilindro_node = geo->createCylinderMesh(raio, height, 6);
        irr::scene::IMeshSceneNode *cilindro_node = smgr->addMeshSceneNode(mesh_cilindro_node);

        if (cilindro_node)
        {
          cilindro_node->setPosition(param->position);
          cilindro_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          cilindro_node->setID(ID_FLAG_HASTE|S);

          cilindro_node->setRotation(Vector3df(angle.X, angle.Y, angle.Z));

          seletor = smgr->createOctTreeTriangleSelector(cilindro_node->getMesh(), cilindro_node, 128);
          cilindro_node->setTriangleSelector(seletor);
          seletor->drop();

          cilindro_node->setName(nodeName);

          selectedSceneNode = (irr::scene::ISceneNode*)cilindro_node;
        }
    }
}

void IrrNode::criaCubo(IrrSmgr* const smgr, nodeParam* param, const irr::c8 *nodeName)
{
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cube_node = geo->createCubeMesh(param->dimension);
        irr::scene::IMeshSceneNode *cube_node = smgr->addMeshSceneNode(mesh_cube_node);

        if (cube_node)
        {
          cube_node->setPosition(param->position);
          cube_node->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE,true);
          cube_node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
          cube_node->setID(ID_FLAG_CUBO|S);

          seletor = smgr->createOctTreeTriangleSelector(cube_node->getMesh(), cube_node, 32);
          cube_node->setTriangleSelector(seletor);
          seletor->drop();

          cube_node->setName(nodeName);

          selectedSceneNode = (irr::scene::ISceneNode*)cube_node;
        }
    }
}

void IrrNode::criaEsfera(IrrSmgr* const smgr, nodeParam* param, const irr::c8* nodeName){
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_esfera_node = geo->createSphereMesh(param->dimension.X, 8, 8);
        irr::scene::IMeshSceneNode *esfera_node = smgr->addMeshSceneNode(mesh_esfera_node);

        if (esfera_node)
        {
          esfera_node->setPosition(param->position);
          esfera_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          esfera_node->setID(ID_FLAG_ESFERA|S);

          seletor = smgr->createOctTreeTriangleSelector(esfera_node->getMesh(), esfera_node, 128);
          esfera_node->setTriangleSelector(seletor);
          seletor->drop();

          esfera_node->setName(nodeName);

          selectedSceneNode = (irr::scene::ISceneNode*)esfera_node;
        }
    }
}

void IrrNode::criaCilindro(IrrSmgr *const smgr, nodeParam* param, const irr::c8* nodeName){
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cilindro_node = geo->createCylinderMesh(param->dimension.X, param->dimension.Y, 8);
        irr::scene::IMeshSceneNode *cilindro_node = smgr->addMeshSceneNode(mesh_cilindro_node);

        if (cilindro_node)
        {
          cilindro_node->setPosition(param->position);
          cilindro_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          cilindro_node->setID(ID_FLAG_CILINDRO|S);

          seletor = smgr->createOctTreeTriangleSelector(cilindro_node->getMesh(), cilindro_node, 128);
          cilindro_node->setTriangleSelector(seletor);
          seletor->drop();

          cilindro_node->setName(nodeName);

          selectedSceneNode = (irr::scene::ISceneNode*)cilindro_node;
        }
    }
}

void IrrNode::criaCone(IrrSmgr* const smgr, nodeParam* param, const irr::c8 *nodeName)
{
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cone_node = geo->createConeMesh(param->dimension.X, param->dimension.Y, 8);
        irr::scene::IMeshSceneNode *cone_node = smgr->addMeshSceneNode(mesh_cone_node);

        if (cone_node)
        {
          cone_node->setPosition(param->position);
          cone_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          cone_node->setID(ID_FLAG_CONE|S);

          seletor = smgr->createOctTreeTriangleSelector(cone_node->getMesh(), cone_node, 32);
          cone_node->setTriangleSelector(seletor);
          seletor->drop();

          cone_node->setName(nodeName);

          selectedSceneNode = (irr::scene::ISceneNode*)cone_node;
        }

    }

}

void IrrNode::criaGizmo(IrrSmgr* const smgr,
                        irr::scene::IMeshSceneNode** gizmo_X,
                        irr::scene::IMeshSceneNode** gizmo_Y,
                        irr::scene::IMeshSceneNode** gizmo_Z,
                        const irr::core::aabbox3df& box)

{
    const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();

    irr::scene::IMesh *mesh_gizmo_X = geo->createArrowMesh( 2,
                                                            4,
                                                            box.MaxEdge.X+0.01,
                                                            box.MaxEdge.X,
                                                            0.001f,
                                                            0.01f,
                                                            irr::video::SColor(255,0,0,255),
                                                            irr::video::SColor(255,0,0,255) );
    irr::scene::IMesh *mesh_gizmo_Y = geo->createArrowMesh( 2,
                                                            4,
                                                            box.MaxEdge.Y+0.01,
                                                            box.MaxEdge.Y,
                                                            0.001f,
                                                            0.01f,
                                                            irr::video::SColor(255,0,255,0),
                                                            irr::video::SColor(255,0,255,0) );
    irr::scene::IMesh *mesh_gizmo_Z = geo->createArrowMesh( 2,
                                                            4,
                                                            box.MaxEdge.Z+0.01,
                                                            box.MaxEdge.Z,
                                                            0.001f,
                                                            0.01f,
                                                            irr::video::SColor(255,255,0,0),
                                                            irr::video::SColor(255,255,0,0) );

    (*gizmo_X) = smgr->addMeshSceneNode(mesh_gizmo_X);
    (*gizmo_Y) = smgr->addMeshSceneNode(mesh_gizmo_Y);
    (*gizmo_Z) = smgr->addMeshSceneNode(mesh_gizmo_Z);

    if((*gizmo_X)&& (*gizmo_Y) && (*gizmo_Z))
    {
        (*gizmo_X)->setID(ID_FLAG_GIZMO_X);
        (*gizmo_X)->setPosition(Vector3df(0, 0, 0));
        (*gizmo_X)->setRotation(Vector3df(0,0,-90));
        (*gizmo_X)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*gizmo_X)->setVisible(false);

        (*gizmo_Y)->setID(ID_FLAG_GIZMO_Y);
        (*gizmo_Y)->setPosition(Vector3df(0, 0, 0));
        (*gizmo_Y)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*gizmo_Y)->setVisible(false);

        (*gizmo_Z)->setID(ID_FLAG_GIZMO_Z);
        (*gizmo_Z)->setPosition(Vector3df(0, 0, 0));
        (*gizmo_Z)->setRotation(Vector3df(-90,0,0));
        (*gizmo_Z)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*gizmo_Z)->setVisible(false);
    }
    mesh_gizmo_X->drop();
    mesh_gizmo_Y->drop();
    mesh_gizmo_Z->drop();
}

void IrrNode::gizmosRegiaoAnalise(IrrSmgr* const smgr,
                        irr::scene::IMeshSceneNode **r_analise_gizmo_X,
                        irr::scene::IMeshSceneNode **r_analise_gizmo_Y,
                        irr::scene::IMeshSceneNode **r_analise_gizmo_Z,
                        const Dim3df& dim)
{
    const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();


    irr::scene::IMesh *mesh_gizmo_X = geo->createArrowMesh( 2,
                                                            4,
                                                            dim.X+0.1,
                                                            dim.X,
                                                            0.005,
                                                            0.03,
                                                            irr::video::SColor(255,0,0,255),
                                                            irr::video::SColor(255,0,0,255) );
    irr::scene::IMesh *mesh_gizmo_Y = geo->createArrowMesh( 2,
                                                            4,
                                                            dim.X+0.1,
                                                            dim.X,
                                                            0.005,
                                                            0.03,
                                                            irr::video::SColor(255,0,255,0),
                                                            irr::video::SColor(255,0,255,0) );
    irr::scene::IMesh *mesh_gizmo_Z = geo->createArrowMesh( 2,
                                                            4,
                                                            dim.X+0.1,
                                                            dim.X,
                                                            0.005,
                                                            0.03,
                                                            irr::video::SColor(255,255,0,0),
                                                            irr::video::SColor(255,255,0,0) );

    (*r_analise_gizmo_X) = smgr->addMeshSceneNode(mesh_gizmo_X);
    (*r_analise_gizmo_Y) = smgr->addMeshSceneNode(mesh_gizmo_Y);
    (*r_analise_gizmo_Z) = smgr->addMeshSceneNode(mesh_gizmo_Z);

    if((*r_analise_gizmo_X)&& (*r_analise_gizmo_Y) && (*r_analise_gizmo_Z))
    {
        (*r_analise_gizmo_X)->setPosition(Vector3df(-dim.X*0.5,
                                                    -dim.Y*0.5,
                                                    dim.Z*0.5));
        (*r_analise_gizmo_X)->setRotation(Vector3df(0,0,-90));
        (*r_analise_gizmo_X)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*r_analise_gizmo_X)->setVisible(true);

        (*r_analise_gizmo_Y)->setPosition(Vector3df(-dim.X*0.5,
                                                    -dim.Y*0.5,
                                                    dim.Z*0.5));
        (*r_analise_gizmo_Y)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*r_analise_gizmo_Y)->setVisible(true);

        (*r_analise_gizmo_Z)->setPosition(Vector3df(-dim.X*0.5,
                                                    -dim.Y*0.5,
                                                    dim.Z*0.5));
        (*r_analise_gizmo_Z)->setRotation(Vector3df(-90,0,0));
        (*r_analise_gizmo_Z)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*r_analise_gizmo_Z)->setVisible(true);
    }
}

