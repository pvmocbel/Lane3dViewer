#include "irrnode.h"

IrrNode::IrrNode():selectedSceneNode(0),delta(0.0)
{   }


irr::scene::IMesh* IrrNode::createCube(const Vector3df& size)const
{
    irr::scene::SMeshBuffer* buffer = new irr::scene::SMeshBuffer();

    // Create indices
    const irr::u16 u[36] = {   0,2,1,   0,3,2,   1,5,4,   1,2,5,   4,6,7,   4,5,6,
            7,3,0,   7,6,3,   9,5,2,   9,8,5,   0,11,10,   0,10,7};

    buffer->Indices.set_used(36);

    for (irr::u32 i=0; i<36; ++i)
        buffer->Indices[i] = u[i];


    // Create vertices
    irr::video::SColor clr(255,255,255,255);

    buffer->Vertices.reallocate(12);

    buffer->Vertices.push_back(irr::video::S3DVertex(0,0,0, -1,-1,-1, clr, 0, 1));
    buffer->Vertices.push_back(irr::video::S3DVertex(1,0,0,  1,-1,-1, clr, 1, 1));
    buffer->Vertices.push_back(irr::video::S3DVertex(1,1,0,  1, 1,-1, clr, 1, 0));
    buffer->Vertices.push_back(irr::video::S3DVertex(0,1,0, -1, 1,-1, clr, 0, 0));
    buffer->Vertices.push_back(irr::video::S3DVertex(1,0,1,  1,-1, 1, clr, 0, 1));
    buffer->Vertices.push_back(irr::video::S3DVertex(1,1,1,  1, 1, 1, clr, 0, 0));
    buffer->Vertices.push_back(irr::video::S3DVertex(0,1,1, -1, 1, 1, clr, 1, 0));
    buffer->Vertices.push_back(irr::video::S3DVertex(0,0,1, -1,-1, 1, clr, 1, 1));
    buffer->Vertices.push_back(irr::video::S3DVertex(0,1,1, -1, 1, 1, clr, 0, 1));
    buffer->Vertices.push_back(irr::video::S3DVertex(0,1,0, -1, 1,-1, clr, 1, 1));
    buffer->Vertices.push_back(irr::video::S3DVertex(1,0,1,  1,-1, 1, clr, 1, 0));
    buffer->Vertices.push_back(irr::video::S3DVertex(1,0,0,  1,-1,-1, clr, 0, 0));

    // Recalculate bounding box
    buffer->BoundingBox.reset(0,0,0);

    for (irr::u32 i=0; i<12; ++i)
    {
                //buffer->Vertices[i].Pos -= core::vector3df(0.5f, 0.5f, 0.5f);
        buffer->Vertices[i].Pos *= size;
        buffer->BoundingBox.addInternalPoint(buffer->Vertices[i].Pos);
    }

    irr::scene::SMesh* mesh = new irr::scene::SMesh;
    mesh->addMeshBuffer(buffer);
    buffer->drop();

    mesh->recalculateBoundingBox();
    return mesh;
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
        double height = 0;

        if(param->dimension.X != param->dimension2.X){
            height = param->dimension2.X - param->dimension.X;
            angle.X = 0;
            angle.Y = 0;
            angle.Z = -90;
        }
        else if(param->dimension.Y != param->dimension2.Y){
            height = param->dimension2.Y - param->dimension.Y;
            angle.X = 0;
            angle.Y = 0;
            angle.Z = 0;
        }
        else if(param->dimension.Z != param->dimension2.Z){
            height = param->dimension2.Z - param->dimension.Z;
            angle.X = -90;
            angle.Y = 0;
            angle.Z = 0;                        
        }

        float raio = param->raio_haste/1000.0;
        if(raio<0.005) raio = raio*50;

        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();
        irr::scene::IMesh *mesh_cilindro_node = geo->createCylinderMesh(raio, height, 6);
        irr::scene::IMeshSceneNode *cilindro_node = smgr->addMeshSceneNode(mesh_cilindro_node);

        if (cilindro_node)
        {
          cilindro_node->setPosition(param->dimension);
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
         irr::scene::IMesh *mesh_cube_node = createCube(param->dimension);
        color.set(255, 200, 200 ,200);
        switch(param->propriedade){
         case(1):
            color.set(255, 169, 169, 169 );
            break;
        case(2):
            color.set(255, 205, 133, 63 );
            break;
        case(3):
            color.set(255, 221, 221, 221 );
            break;
        case(4):
            color.set(255, 255, 231, 186 );
            break;
        case(5):
            color.set(255, 232, 232, 232 );
            break;
        case(6):
            color.set(255, 139, 71, 38 );
            break;
        }

        irr::scene::IMeshSceneNode *cube_node = smgr->addMeshSceneNode(mesh_cube_node);

        if (cube_node)
        {
           cube_node->setPosition(param->position);
           cube_node->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE,true);
           cube_node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
           cube_node->setID(ID_FLAG_CUBO|S);

           smgr->getMeshManipulator()->setVertexColors(cube_node->getMesh(), color);
           seletor = smgr->createOctTreeTriangleSelector(cube_node->getMesh(), cube_node, 128);
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
        color.set(255, 200, 200 ,200);
        switch(param->propriedade){
         case(1):
            color.set(255, 169, 169, 169 );
            break;
        case(2):
            color.set(255, 205, 133, 63 );
            break;
        case(3):
            color.set(255, 221, 221, 221 );
            break;
        case(4):
            color.set(255, 255, 231, 186 );
            break;
        case(5):
            color.set(255, 232, 232, 232 );
            break;
        case(6):
            color.set(255, 139, 71, 38 );
            break;
        }


        if (esfera_node)
        {
          esfera_node->setPosition(param->position);
          esfera_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          esfera_node->setID(ID_FLAG_ESFERA|S);

          smgr->getMeshManipulator()->setVertexColors(esfera_node->getMesh(), color);
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
        color.set(255, 200, 200 ,200);
        if (cilindro_node)
        {
          cilindro_node->setPosition(param->position);
          cilindro_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          cilindro_node->setID(ID_FLAG_CILINDRO|S);

          smgr->getMeshManipulator()->setVertexColors(cilindro_node->getMesh(), color);
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
         color.set(255, 200, 200 ,200);
        if (cone_node)
        {
          cone_node->setPosition(param->position);
          cone_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          cone_node->setID(ID_FLAG_CONE|S);

          smgr->getMeshManipulator()->setVertexColors(cone_node->getMesh(), color);
          seletor = smgr->createOctTreeTriangleSelector(cone_node->getMesh(), cone_node, 32);
          cone_node->setTriangleSelector(seletor);
          seletor->drop();

          cone_node->setName(nodeName);

          selectedSceneNode = (irr::scene::ISceneNode*)cone_node;
        }
    }
}
void IrrNode::criaAntenna(IrrSmgr *const smgr, const Vector3df& position, const irr::c8 *nodeName){
    if(smgr)
    {
        const irr::scene::IGeometryCreator *geo = smgr->getGeometryCreator();

        irr::scene::IMesh *mesh_plane = geo->createCubeMesh(Vector3df(0.3, delta, 0.3));
        irr::scene::IMesh *mesh_cube_node = geo->createCubeMesh(Vector3df(0.06, 0.09, 0.06));

        irr::scene::IMeshSceneNode *cube_node = smgr->addMeshSceneNode(mesh_cube_node);
        irr::scene::IMeshSceneNode *plane = smgr->addMeshSceneNode(mesh_plane);

        irr::scene::IMesh *mesh_cilindro_node = geo->createCylinderMesh(0.01, 0.03, 10);
        irr::scene::IMeshSceneNode *haste = smgr->addMeshSceneNode(mesh_cilindro_node);

        if (plane)
        {
          plane->setPosition(Vector3df(position.X, (position.Y + 0.15)-0.09/2, position.Z));
          plane->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE,true);
          plane->setMaterialFlag(irr::video::EMF_LIGHTING, true);
          plane->setID(ID_FLAG_ANTENNA);
          plane->setParent(cube_node);
          seletor = smgr->createOctTreeTriangleSelector(plane->getMesh(), plane, 32);
          plane->setTriangleSelector(seletor);
          seletor->drop();

          selectedSceneNode = (irr::scene::ISceneNode*)plane;
        }

        if (cube_node)
        {
          cube_node->setPosition(position);
          cube_node->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE,true);
          cube_node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
          cube_node->setID(ID_FLAG_ANTENNA|S);

          seletor = smgr->createOctTreeTriangleSelector(cube_node->getMesh(), cube_node, 32);
          cube_node->setTriangleSelector(seletor);
          seletor->drop();

          cube_node->setName(nodeName);

          selectedSceneNode = (irr::scene::ISceneNode*)cube_node;
        }

        if (haste)
        {
            haste->setPosition(Vector3df(position.X, (position.Y + 0.09)-0.09/2, position.Z));
          haste->setMaterialFlag(irr::video::EMF_LIGHTING, false);
          haste->setID(ID_FLAG_ANTENNA);
          haste->setParent(cube_node);
          seletor = smgr->createOctTreeTriangleSelector(plane->getMesh(), haste, 128);
          haste->setTriangleSelector(seletor);
          seletor->drop();

          selectedSceneNode = (irr::scene::ISceneNode*)haste;
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
        (*gizmo_Z)->setRotation(Vector3df(90,0,0));
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
        (*r_analise_gizmo_X)->setPosition(Vector3df(0, 0, 0));
        (*r_analise_gizmo_X)->setRotation(Vector3df(0,0,-90));
        (*r_analise_gizmo_X)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*r_analise_gizmo_X)->setVisible(true);

        (*r_analise_gizmo_Y)->setPosition(Vector3df(0,0,0));
        (*r_analise_gizmo_Y)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*r_analise_gizmo_Y)->setVisible(true);

        (*r_analise_gizmo_Z)->setPosition(Vector3df(0,0,0));
        (*r_analise_gizmo_Z)->setRotation(Vector3df(90,0,0));
        (*r_analise_gizmo_Z)->setMaterialFlag(irr::video::EMF_LIGHTING,false);
        (*r_analise_gizmo_Z)->setVisible(true);
    }
}

