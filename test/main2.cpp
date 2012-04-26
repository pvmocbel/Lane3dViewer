#include <irrlicht.h>
#include <iostream>
using namespace std;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

void criaRegiaAnalise(core::aabbox3df box,video::IVideoDriver* driver){
    driver->setTransform( ETS_WORLD, core::matrix4());
    SMaterial mat;
    mat.Lighting = false;
    driver->setMaterial( mat );
    driver->draw3DBox(box, SColor(255, 50, 50, 50));

    float Xmin = box.MinEdge.X;
    float Ymin = box.MinEdge.Y;
    float Zmin = box.MinEdge.Z;

    float Xmax = box.MaxEdge.X;
    float Ymax = box.MaxEdge.Y;
    float Zmax = box.MaxEdge.Z;

    float deltaX = (Xmax - Xmin)/10.0f;
    float deltaY = (Ymax - Ymin)/10.0f;
    float deltaZ = (Zmax - Zmin)/10.0f;

    irr::core::aabbox3df box_aux;

    for(float x = Xmin; x<Xmax; x+=deltaX)
        for(float y = Ymin; y<Ymax; y+=deltaY)
            for(float z = Zmin; z<Zmax; z+=deltaZ){
                box_aux.MinEdge.set(vector3df(x,y,z));
                box_aux.MaxEdge.set(vector3df(x+deltaX, y+deltaY, z+deltaZ));
                driver->draw3DBox(box_aux, SColor(255,255,0,0));
            }

//    bool test = true; //colocar antes do run para pintar de forma correta a esfera
    // Draw circle on X/Y
//    vector3df pV(25,0, 0 );

//    for( f32 r = 0; r < 2 * PI; r += 2.f*PI/30.f )
//    {
//        f32 px = 25 * cos( r );
//        f32 py = 25 * sin( r );

//        if(test){
//            driver->draw3DLine( vector3df(px-0.01f,py-0.01,0), vector3df( px, py, 0 ), SColor( 255, 0, 255, 0 ));
//            test = false;
//        }
//        else    driver->draw3DLine( pV, vector3df( px, py, 0 ), SColor( 255, 0, 255, 0 ));
//        pV = vector3df( px, py, 0 );
//    }
}

int main()
{
    IrrlichtDevice *device =
            createDevice( video::EDT_BURNINGSVIDEO, dimension2d<u32>(640, 480), 16,
                    false, false, false, 0);
    if (!device)    return 1;

    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();

// Add Light to the Scene
    ILightSceneNode *light = smgr->addLightSceneNode( 0, vector3df() );
    light->getLightData().AmbientColor = SColorf( 0.2f, 0.2f, 0.2f );
    light->getLightData().SpecularColor = SColorf( 1.0f, 1.0f, 1.0f );
    light->getLightData().DiffuseColor = SColorf( 0.8f, 0.8f, 0.8f );
    light->setLightType( ELT_DIRECTIONAL );
    light->setRotation( vector3df( 45.0f, 45.0f, 0.0f ));
    smgr->setAmbientLight( SColorf( 0.2f, 0.2f, 0.2f ));

//    scene::IMeshSceneNode* node = smgr->addCubeSceneNode(20);
//    if (node){
//        node->setMaterialFlag(EMF_LIGHTING, false);
//        smgr->getMeshManipulator()->setVertexColors(node->getMesh(),SColor(250,250,0,0));
//        node->setPosition(core::vector3df(0,0,0) );
//        node->setVisible(false);
//    }

    smgr->addCameraSceneNode(0, vector3df(0,0,-250), vector3df(0,0,0));

    while(device->run())
    {
        core::aabbox3df box;
        box.MinEdge.set(vector3df(-100,-100,-100));
        box.MaxEdge.set(vector3df(100,100,100));

        driver->beginScene(true, true, SColor(250, 100, 150, 150));
        smgr->drawAll();
        guienv->drawAll();
        criaRegiaAnalise(box, driver);

        driver->endScene();
    }
    device->drop();
    return 0;
}
