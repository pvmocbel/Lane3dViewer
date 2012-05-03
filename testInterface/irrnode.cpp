#include "irrnode.h"

IrrNode::IrrNode():selectedSceneNode(0),first_cube(true)
{
}

void IrrNode::criaCubo(IrrSmgr* const smgr, const Pos3df& pos, const Dim3df& dim)
{
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cube_node = geo->createCubeMesh(dim);
        irr::scene::IMeshSceneNode *cube_node = smgr->addMeshSceneNode(mesh_cube_node);

        if (cube_node)
        {
          cube_node->setPosition(pos);
          cube_node->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE,true);
          cube_node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
          cube_node->setID(ID_FLAG_CUBO|S);

          seletor = smgr->createOctTreeTriangleSelector(cube_node->getMesh(), cube_node, 32);
          cube_node->setTriangleSelector(seletor);
          seletor->drop();

          selectedSceneNode = (irr::scene::ISceneNode*)cube_node;
     }
        this->position = pos;
        this->dimension = dim;
    }
}

void IrrNode::criaCone(IrrSmgr* const smgr, const Pos3df& pos, const Dim3df& dim)
{
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cone_node = geo->createConeMesh(dim.Y, dim.X, 30);
        irr::scene::IMeshSceneNode *cone_node = smgr->addMeshSceneNode(mesh_cone_node);

        if (cone_node)
        {
          cone_node->setPosition(pos);
          cone_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          cone_node->setID(ID_FLAG_CONE|S);

          seletor = smgr->createOctTreeTriangleSelector(cone_node->getMesh(), cone_node, 32);
          cone_node->setTriangleSelector(seletor);
          seletor->drop();

          selectedSceneNode = (irr::scene::ISceneNode*)cone_node;
        }
        this->position = pos;
        this->dimension = dim;
    }

}

void IrrNode::criaCilindro(IrrSmgr *const smgr, const Pos3df &pos, const Dim3df &dim){
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cilindro_node = geo->createCylinderMesh(dim.X,dim.Y,30);
        irr::scene::IMeshSceneNode *cilindro_node = smgr->addMeshSceneNode(mesh_cilindro_node);

        if (cilindro_node)
        {
          cilindro_node->setPosition(pos);
          cilindro_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          cilindro_node->setID(ID_FLAG_CILINDRO|S);

          seletor = smgr->createOctTreeTriangleSelector(cilindro_node->getMesh(), cilindro_node, 128);
          cilindro_node->setTriangleSelector(seletor);
          seletor->drop();

          selectedSceneNode = (irr::scene::ISceneNode*)cilindro_node;
        }
    }
}

void IrrNode::criaEsfera(IrrSmgr* const smgr, const Pos3df& pos, const double raio){
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_esfera_node = geo->createSphereMesh(raio);
        irr::scene::IMeshSceneNode *esfera_node = smgr->addMeshSceneNode(mesh_esfera_node);

        if (esfera_node)
        {
          esfera_node->setPosition(pos);
          esfera_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          esfera_node->setID(ID_FLAG_ESFERA|S);

          seletor = smgr->createOctTreeTriangleSelector(esfera_node->getMesh(), esfera_node, 128);
          esfera_node->setTriangleSelector(seletor);
          seletor->drop();

          selectedSceneNode = (irr::scene::ISceneNode*)esfera_node;
        }
    }
}

void IrrNode::criaGizmo(IrrSmgr* const smgr,
                        irr::scene::IMeshSceneNode** gizmo_X,
                        irr::scene::IMeshSceneNode** gizmo_Y,
                        irr::scene::IMeshSceneNode** gizmo_Z)
{
    const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();

    irr::scene::IMesh *mesh_gizmo_X = geo->createArrowMesh( 4, 8, 13.0f, 10.0f, 0.08f, 0.3f, irr::video::SColor(255,0,0,255), irr::video::SColor(255,0,0,255) );
    irr::scene::IMesh *mesh_gizmo_Y = geo->createArrowMesh( 4, 8, 13.0f, 10.0f, 0.08f, 0.3f, irr::video::SColor(255,0,255,0), irr::video::SColor(255,0,255,0) );
    irr::scene::IMesh *mesh_gizmo_Z = geo->createArrowMesh( 4, 8, 13.0f, 10.0f, 0.08f, 0.3f, irr::video::SColor(255,255,0,0), irr::video::SColor(255,255,0,0) );

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
                                                            dim.X+8.0f,
                                                            dim.X+1.0f,
                                                            0.5f,
                                                            1.2f,
                                                            irr::video::SColor(150,0,0,150),
                                                            irr::video::SColor(150,0,0,150));

    irr::scene::IMesh *mesh_gizmo_Y = geo->createArrowMesh( 2,
                                                            4,
                                                            dim.Y + 8.0f,
                                                            dim.Y+1.0f,
                                                            0.5f,
                                                            1.2f,
                                                            irr::video::SColor(150,0,150,0),
                                                            irr::video::SColor(150,0,150,0) );

    irr::scene::IMesh *mesh_gizmo_Z = geo->createArrowMesh( 2,
                                                            4,
                                                            dim.Z+8.0f,
                                                            dim.Z+1.0f,/*(box.MaxEdge.Z-box.MinEdge.Z),*/
                                                            0.5f,
                                                            1.2f,
                                                            irr::video::SColor(150,150,0,0),
                                                            irr::video::SColor(150,150,0,0) );

    (*r_analise_gizmo_X) = smgr->addMeshSceneNode(mesh_gizmo_X);
    (*r_analise_gizmo_Y) = smgr->addMeshSceneNode(mesh_gizmo_Y);
    (*r_analise_gizmo_Z) = smgr->addMeshSceneNode(mesh_gizmo_Z);

    if((*r_analise_gizmo_X)&& (*r_analise_gizmo_Y) && (*r_analise_gizmo_Z))
    {
        (*r_analise_gizmo_X)->setPosition(Vector3df(-(dim.X*0.5),
                                                    -(dim.Y*0.5),
                                                    (dim.Z*0.5)));
        (*r_analise_gizmo_X)->setRotation(Vector3df(0,0,-90));
        (*r_analise_gizmo_X)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*r_analise_gizmo_X)->setVisible(true);

        (*r_analise_gizmo_Y)->setPosition(Vector3df(-(dim.X*0.5),
                                                    -(dim.Y*0.5),
                                                    (dim.Z*0.5)));
        (*r_analise_gizmo_Y)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*r_analise_gizmo_Y)->setVisible(true);

        (*r_analise_gizmo_Z)->setPosition(Vector3df(-(dim.X*0.5),
                                                    -(dim.Y*0.5),
                                                    (dim.Z*0.5)));
        (*r_analise_gizmo_Z)->setRotation(Vector3df(-90,0,0));
        (*r_analise_gizmo_Z)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*r_analise_gizmo_Z)->setVisible(true);
    }
}
