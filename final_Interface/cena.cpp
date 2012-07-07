#include "cena.h"
#include <stdio.h>
#include "mainwindow.h"
Cena::Cena():IrrViewer(0),light(0),mouse_key_test(false),
    selectedSceneNode(0),collMan(0),duplicateNode_mouse_key(false),
    mouseXi(0),mouseYi(0),dx(0),dy(0),MoveSceneNode(0),aproxima(0.02),afasta(0.02),fator(0)
{
    init();
}

Cena::~Cena(){}

void Cena::init(){
    camera = 0;

    camera_01 = false;
    camera_02 = false;
    camera_03 = false;
    camera_04 = false;
    camera_05 = false;
    camera_06 = false;

    dim.set(0,0,0);

    mouse_press_position.set(0,0,0);
    mouse_release_position.set(0,0,0);

    key_m_on = false;
    key_x_on = false;
    key_y_on = false;
    key_z_on = false;

    xi = 0;
    yi = 0;
    zi = 0;

    box.MinEdge.set(0,0,0);
    box.MaxEdge.set(0,0,0);

    r_analise_gizmo_X = 0;
    r_analise_gizmo_Y = 0;
    r_analise_gizmo_Z = 0;

    gizmo_X = 0;
    gizmo_Y = 0;
    gizmo_Z = 0;
}
void Cena::cenaIrrlicht()
{
    if (smgr) {
        collMan = smgr->getSceneCollisionManager();
        cenaCameras();
        cenaIluminacao();
        gizmo();
        emit send_dimension();
        drawIrrlichtScene();
    }
}
void Cena::cenaCameras(){
    if (smgr) {
        camera = smgr->addCameraSceneNode();
        camera->setPosition(Vector3df(dim.X/2, dim.Y/2, -0.9));
        camera->setTarget(Vector3df(dim.X/2, dim.Y/2, dim.Z/2));
        camera_01 = true;
        smgr->setActiveCamera(camera);
    }
}
void Cena::cenaIluminacao(){
    if (smgr) {
        light = smgr->addLightSceneNode();
        light->setLightType( irr::video::ELT_DIRECTIONAL );
        light->setRotation( irr::core::vector3df( 45.0f, 45.0f, 0.0f ));
        light->getLightData().AmbientColor = irr::video::SColorf( 0.2f, 0.2f, 0.2f, 1.0f );
        light->getLightData().DiffuseColor = irr::video::SColorf( 0.8f, 0.8f, 0.8f, 1.0f );
    }
}

void Cena::criaRegiaoAnalise(const Dim3df& dim, double delta){
    if(smgr)
    {
        FILE* out = fopen("simconf.in", "w+");
        IrrNode* node = new IrrNode();

        this->dim = dim;
        this->delta = delta;
        node->delta = delta;
        fator = delta*0.01;

        int ncelulas_x = (int)( round( (dim.X/delta) ) );
        int ncelulas_y = (int)( round( (dim.Y/delta) ) );
        int ncelulas_z = (int)( round( (dim.Z/delta) ) );

        fprintf(out, "%d %d %d %g %d\n", ncelulas_x, ncelulas_z, ncelulas_y, delta, 2000 );

        box.MinEdge.set(0,0,0);
        box.MaxEdge.set(dim.X, dim.Y, dim.Z);

        camera->setPosition(Vector3df(dim.X/2, dim.Y/2, -50*delta));
        camera->setTarget(Vector3df(dim.X/2, dim.Y/2, dim.Z/2));

        node->gizmosRegiaoAnalise(smgr, &r_analise_gizmo_X, &r_analise_gizmo_Y, &r_analise_gizmo_Z, dim);

        drawIrrlichtScene();
        fclose(out);
        delete node;
    }
}
void Cena::printRegiaoAnalise(irr::core::aabbox3df box){
    if((video_driver))
    {
        video_driver->setTransform( irr::video::ETS_WORLD, irr::core::matrix4());
        irr::video::SMaterial mat;
        mat.Lighting = false;

        video_driver->setMaterial( mat );
        video_driver->draw3DBox(box, irr::video::SColor(255, 250, 150, 150));
    }
}
void Cena::gizmo(){
    if(smgr)
    {
        IrrNode* node = new IrrNode();
        node->criaGizmo(smgr, &gizmo_X, &gizmo_Y, &gizmo_Z, box);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::save(){
    if(smgr){
        FILE* out = fopen("map.in","w");
         for(it = myMap.begin(); it != myMap.end(); it++){
             NodeType type = (*it).second.type;
             switch(type){
             case(Haste):
                 fprintf(out, "%d %g %g %g %g %g %g %g %g %g %g\n",
                                1,
                                (*it).second.dimension.X,
                                (*it).second.dimension.Y,
                                (*it).second.dimension.Z,
                                (*it).second.dimension2.X,
                                (*it).second.dimension2.Y,
                                (*it).second.dimension2.Z,
                                (*it).second.raio_haste,
                                (*it).second.parametros.X,
                                (*it).second.parametros.Y,
                                (*it).second.parametros.Z
                                ); //type---haste_i_x---haste_i_y---haste_i_z---haste_f_x---haste_f_y---haste_f_z
                 break;
             case(Cube):
                 fprintf(out, "%d %g %g %g %g %g %g %g %g %g\n",
                                2,
                                (*it).second.position.X,
                                (*it).second.position.Y,
                                (*it).second.position.Z,
                                (*it).second.dimension.X,
                                (*it).second.dimension.Y,
                                (*it).second.dimension.Z,
                                (*it).second.parametros.X,
                                (*it).second.parametros.Y,
                                (*it).second.parametros.Z
                                ); //type--position.x--position.y--position.z--dimension.x--dimension.y--dimension.z
                 break;
             case(Esphere):
                 fprintf(out, "%d %g %g %g %g %g %g %g\n",
                                3,
                                (*it).second.position.X,
                                (*it).second.position.Y,
                                (*it).second.position.Z,
                                (*it).second.dimension.X,
                                 (*it).second.parametros.X,
                                 (*it).second.parametros.Y,
                                 (*it).second.parametros.Z
                                ); //type--position.x--position.y--position.z--raio
                 break;
             case(Cilindro):
                 fprintf(out, "%d %g %g %g %g %g %g %g %g\n",
                                4,
                                (*it).second.position.X,
                                (*it).second.position.Y,
                                (*it).second.position.Z,
                                (*it).second.dimension.X,
                                (*it).second.dimension.Y,
                                (*it).second.parametros.X,
                                (*it).second.parametros.Y,
                                (*it).second.parametros.Z
                                ); //type--position.x--position.y--position.z--raio--altura
                 break;
             case(Cone):
                 fprintf(out, "%d %g %g %g %g %g %g %g\n",
                                5,
                                (*it).second.position.X,
                                (*it).second.position.Y,
                                (*it).second.position.Z,
                                (*it).second.dimension.X,
                                (*it).second.dimension.Y,
                                (*it).second.parametros.X,
                                (*it).second.parametros.Y,
                                (*it).second.parametros.Z
                                ); //type--position.x--position.y--position.z--raio--altura
                 break;
             }//end switch type

         }//end for map
         fclose(out);
    }//fim if smgr
}
void Cena::load(){
    if(smgr){
        FILE* input = fopen("map.in","r");
        rewind(input);
        float temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10;
        NodeParameters *param = new NodeParameters;
        int type, id;

        while(!feof(input)){
            fscanf(input, "%d", &type);
            switch(type){
            case(1):    //haste
                fscanf(input, "%g %g %g %g %g %g %g %g %g %g",&temp1, &temp2, &temp3,
                                                              &temp4, &temp5, &temp6,
                                                              &temp7, &temp8, &temp9,
                                                              &temp10);//hi.x--hi.y--hi.z--hf.x--hfy-hfz-raio

                param->dimension.set(temp1, temp2, temp3);
                param->dimension2.set(temp4, temp5, temp6);
                param->raio_haste = temp7;
                param->parametros.set(temp8, temp9, temp10);
                id = get_serialize_id();
                insertHaste(id, new IrrNode(), param);

                break;

            case(2):    //cubo
                fscanf(input, "%g %g %g %g %g %g %g %g %g ",&temp1, &temp2, &temp3,
                                                            &temp4, &temp5, &temp6,
                                                            &temp7, &temp8, &temp9);//p.x--p.y--p.z--d.x--dy--dz

                param->position.set(temp1, temp2, temp3);
                param->dimension.set(temp4, temp5, temp6);
                param->parametros.set(temp7, temp8, temp9);
                id = get_serialize_id();
                insertCubo(id, new IrrNode(), param);

                break;

            case(3):    //esfera
                fscanf(input, "%g %g %g %g %g %g %g",&temp1, &temp2, &temp3,
                                                    &temp4, &temp5, &temp6,
                                                    &temp7);//p.x--p.y--p.z--raio

                param->position.set(temp1, temp2, temp3);
                param->dimension.set(temp4, 0, 0);
                param->parametros.set(temp5, temp6, temp7);
                id = get_serialize_id();
                insertEsfera(id, new IrrNode(), param);

                break;

            case(4):    //cilindro
                fscanf(input, "%g %g %g %g %g %g %g %g",&temp1, &temp2, &temp3,
                                                        &temp4, &temp5, &temp6,
                                                        &temp7, &temp8 );//p.x--p.y--p.z--raio--altura

                param->position.set(temp1, temp2, temp3);
                param->dimension.set(temp4, temp5, 0);
                param->parametros.set(temp6, temp7, temp8);
                id = get_serialize_id();
                insertCilindro(id, new IrrNode(), param);

                break;

            case(5):    //cone
                fscanf(input, "%g %g %g %g %g %g %g %g",&temp1, &temp2, &temp3,
                                                        &temp4, &temp5, &temp6,
                                                        &temp7, &temp8 );//p.x--p.y--p.z--raio--altura

                param->position.set(temp1, temp2, temp3);
                param->dimension.set(temp4, temp5, 0);
                param->parametros.set(temp6, temp7, temp8);
                id = get_serialize_id();
                insertCone(id, new IrrNode(), param);

                break;

            }//end switch

        }   //end while

        delete param;
        fclose(input);
    }//end if smgr
}

void Cena::parametros( NodeParameters * param, int id){
    if(smgr){
        myMap[id].dimension = param->dimension;
        myMap[id].dimension2 = param->dimension2;
        myMap[id].raio_haste = param->raio_haste;
        myMap[id].parametros = param->parametros;
        myMap[id].position = param->position;
        myMap[id].propriedade = param->propriedade;
    }
}


void Cena::receiver_changed_position_mainwindow(const Pos3df &pos)
{
    if(smgr && selectedSceneNode){
        selectedSceneNode->setPosition(pos);
        const irr::c8* test = selectedSceneNode->getName();
        int id = getIdFromNode(test);

        nodeParam aux = myMap[id];
        aux.position = pos;
        myMap[id] = aux;

        gizmo_X->setPosition(selectedSceneNode->getPosition());
        gizmo_X->setVisible(true);

        gizmo_Y->setPosition(selectedSceneNode->getPosition());
        gizmo_Y->setVisible(true);

        gizmo_Z->setPosition(selectedSceneNode->getPosition());
        gizmo_Z->setVisible(true);
        drawIrrlichtScene();
    }
}
void Cena::receiver_changed_dimension(nodeParam* param){
    if(smgr && selectedSceneNode)
    {
        const irr::c8* test = selectedSceneNode->getName();
        int id = getIdFromNode(test);

        irr::c8 name[50];

        nodeParam aux = myMap[id];
        aux = *param;
        myMap[id] = aux;

        qDebug()<<"position"<<" x "<<aux.position.X<<" y "<<aux.position.Y<<" z "<<aux.position.Z;
        switch((selectedSceneNode->getID()&MASK)){
             case(ID_FLAG_CUBO):
                 qDebug()<<"cubo";
                 removeChangedSceneNode();
                 insertCuboChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;

             case(ID_FLAG_ESFERA):
                 qDebug()<<"esfera";
                 removeChangedSceneNode();
                 insertEsferaChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;

             case(ID_FLAG_CILINDRO):
                 qDebug()<<"cilindro";
                 removeChangedSceneNode();
                 insertCilindroChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;

             case(ID_FLAG_CONE):
                 qDebug()<<"cone";
                 removeChangedSceneNode();
                 insertConeChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;

             case(ID_FLAG_HASTE):
                 qDebug()<<"haste";
                 removeChangedSceneNode();
                 insertHasteChanged(new IrrNode(), param, id);
                 sprintf(name, "%d", id);
                 selectedSceneNode  = smgr->getSceneNodeFromName(name);
                 selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                 break;

            default:
                break;
         }//fim switch
        drawIrrlichtScene();
    }//fim smgr
}
void Cena::receiver_changed_material_parameter(const Vector3df &param, int id){
    myMap[id].parametros = param;
}
void Cena::receiver_changed_propriedade(int valor, int id){
    myMap[id].propriedade = valor;
    qDebug()<<"Receiver prop valor "<<valor;
}

void Cena::geraMalha(){
    if(smgr)
    {
        FILE *file = fopen("bd.in","w+");
        FILE *haste = fopen("hastes.in","w+");
        if(!file){
            qDebug()<<"falha na leitura do arquivo";
            return;
        }
        if(!haste){
            qDebug()<<"falha na leitura do arquivo";
            return;
        }

        for(it = myMap.begin(); it != myMap.end(); it++)
        {
            NodeType type = (*it).second.type;
            irr::core::aabbox3df box = (*it).second.box;

            switch(type)
            {
                case (Cube):
                    qDebug()<<"cube gera malha";
                    geraMalhaCube(box, (*it).second, file);
                    break;

                case(Cone):
                    qDebug()<<"cone gera malha";
                    geraMalhaCone((*it).second, file);
                    break;

                case(Cilindro):
                    qDebug()<<"cilindro gera malha";
                    geraMalhaCilindro(box, (*it).second, file);
                    break;

                case(Esphere):
                    qDebug()<<"esphere gera malha";
                    geraMalhaEsfera(box, (*it).second, file );
                    break;

                case(Antenna):
                    qDebug()<<"eye antenna gera malha";
                    geraMalhaAntenna((*it).second.position, file, haste);
                    break;

                case(Haste):
                    qDebug()<<"haste gera malha";
                    if((*it).second.dimension.X != (*it).second.dimension2.X)
                        fprintf(haste, "%d %d %d %d %d %d %f \n", (int)( ((*it).second.dimension.X + fator)/delta ),
                                                          (int)( ( ( (*it).second.dimension2.X + fator)/delta) ) - 1,
                                                          (int)( ( ((*it).second.dimension.Z + fator)/delta) ),
                                                           0,
                                                          (int)( ( ( (*it).second.dimension.Y + fator)/delta) ),
                                                           0,
                                                          ( (*it).second.raio_haste) );
                    else if((*it).second.dimension.Y != (*it).second.dimension2.Y)
                        fprintf(haste, "%d %d %d %d %d %d %f \n", (int)( ( ( (*it).second.dimension.X + fator)/delta) ),
                                                          0,
                                                          (int)( ( ((*it).second.dimension.Z + fator)/delta) ),
                                                          0,
                                                          (int)( ( ( (*it).second.dimension.Y + fator)/delta) ),
                                                          (int)( ( ( (*it).second.dimension2.Y + fator)/delta) ) - 1,
                                                          ((*it).second.raio_haste));
                    else if((*it).second.dimension.Z != (*it).second.dimension2.Z)
                        fprintf(haste, "%d %d %d %d %d %d %f \n", (int)( ( ((*it).second.dimension.X + fator)/delta) ),
                                                          0,
                                                          (int)( ( ((*it).second.dimension.Z + fator)/delta) ),
                                                          (int)( ( ((*it).second.dimension2.Z + fator)/delta) ) - 1,
                                                          (int)( ( ( (*it).second.dimension.Y + fator)/delta) ),
                                                          0,
                                                          ((*it).second.raio_haste));
                    break;

                 default:
                    break;
            }
        }//fim for map
        fprintf(file,"%d \n",-1);
        fprintf(haste,"%d \n",-1);
        fclose(file);
        fclose(haste);
    }//smgr
}
void Cena::geraMalhaCube(irr::core::aabbox3df box, const nodeParam & param, FILE *file){

    qDebug()<<"box min x "<<box.MinEdge.X + fator + param.position.X
            <<" y "<<box.MinEdge.Y+param.position.Y <<" z "<<box.MinEdge.Z+param.position.Z;
    qDebug()<<"box max x "<<box.MaxEdge.X+param.position.X<<
              " y "<<box.MaxEdge.Y+param.position.Y<<" z "<<box.MaxEdge.Z+param.position.Z;

    int x_inicial = (int)( ( (box.MinEdge.X + param.position.X + fator) / delta) );
    int x_final = (int)( ( (box.MaxEdge.X + param.position.X + fator) / delta) ) - 1;

    int y_inicial = (int)( ( (box.MinEdge.Y + param.position.Y + fator) / delta) );
    int y_final = (int)( ( (box.MaxEdge.Y + param.position.Y + fator) / delta) ) - 1;

    int z_inicial = (int)( ( (box.MinEdge.Z + param.position.Z + fator) / delta) );
    int z_final = (int)( ( (box.MaxEdge.Z + param.position.Z + fator) / delta) ) - 1;

    double va = param.position.X;
    std::cout<<va;

    qDebug()<<"xi "<< x_inicial<< "x f"<<x_final;
    qDebug()<<"yi "<< y_inicial<< "y f"<<y_final;
    qDebug()<<"zi "<< z_inicial<< "z f"<<z_final;

    fprintf(file,"%d %d %d %d %d %d %g %g %g\n",x_inicial+26, x_final+26,
                                                z_inicial+26, z_final+26,
                                                y_inicial+26, y_final+26,
                                                param.parametros.X,
                                                param.parametros.Z,
                                                1.0);
}
void Cena::geraMalhaCilindro(irr::core::aabbox3df box, const nodeParam &param, FILE *file){
    intVector position;
    position.set(0,0,0);

    float raio = (param.dimension.X);

    for(float j = box.MinEdge.Y; j< box.MaxEdge.Y; j = j + delta)
        for(float i = box.MinEdge.X; i< box.MaxEdge.X; i = i + delta)
            for(float k = box.MinEdge.Z; k< box.MaxEdge.Z; k = k + delta)
            {
                position.set(position.X, (int)( round(j/delta) ), position.Z);
                int novo_raio = calcula_raio2(position, intVector((int)( (i/delta)  ),
                                                                  (int)( (j/delta)  ),
                                                                  (int)( (k/delta)) ) );

                if(novo_raio < (int)(round (raio/delta) )*(int)( (raio/delta) ))
                    fprintf(file,"%d %d %d %d %d %d \n", (int)( ( (i + param.position.X + fator)/delta) ),
                                                         (int)( ( (i + param.position.X + fator)/delta) ),
                                                         (int)( ( (k + param.position.Z + fator)/delta) ),
                                                         (int)( ( (k + param.position.Z + fator)/delta) ),
                                                         (int)( ( (j + param.position.Y + fator)/delta) ),
                                                         (int)( ( (j + param.position.Y + fator)/delta) )
                                                         );  //end fprintf
            }   //end for k



}
void Cena::geraMalhaCone(const nodeParam &param, FILE* file){
    intVector position;

    position.set(0,0,0);

    double h = param.dimension.Y/delta;
    double tang = (param.dimension.Y/param.dimension.X);
    double p = delta/tang;
    double raio = param.dimension.X;
    double raio_cone = 0;

    int raio_cilindro = 0;
    int count = 0;

    for(float j = 0; j < param.dimension.Y; j=j+delta){
        raio_cone = raio - count*p;
        if(raio_cone>=delta)
        {
            raio_cilindro = (int)( round(raio_cone/delta) );
            for(float i = (-raio_cilindro); i <= (raio_cilindro); i=i+delta)
                for(float k = (-raio_cilindro ); k <= (raio_cilindro); k=k+delta)
                {
                    position.set(position.X, (int)(j), position.Z);
                    int novo_raio = calcula_raio2(position, intVector( (int)( (i/delta) ),
                                                                       (int)( ((j)/delta) ),
                                                                       (int)( (k/delta) ) ) );
                    if(novo_raio<=raio_cilindro*raio_cilindro)
                        fprintf(file,"%d %d %d %d %d %d \n", (int)( ( (i + param.position.X + fator)/delta) ),
                                                             (int)( ( (i + param.position.X + fator)/delta) ),
                                                             (int)( ( (k + param.position.Z + fator)/delta) ),
                                                             (int)( ( (k + param.position.Z + fator)/delta) ),
                                                             (int)( ( (j+param.position.Y + fator)/delta) ),
                                                             (int)( ( (j+param.position.Y + fator)/delta) )
                                                            );  //end fprintf
                }   //end for k

        }   //end if raio
        count++;
    }   //end for j
}
void Cena:: geraMalhaEsfera(irr::core::aabbox3df box, const nodeParam &param, FILE *file ){

   intVector position(0,0,0);
   int raio = (int)( round(param.dimension.X/delta) );

   for(float i = box.MinEdge.X; i <= box.MaxEdge.X; i=i+delta)
      for(float j = box.MinEdge.Y; j <= box.MaxEdge.Y; j=j+delta)
          for(float k = box.MinEdge.Z; k <= box.MaxEdge.Z; k=k+delta)
           {
               int novo_raio = calcula_raio(position, intVector((int)( (i/delta)),
                                                                (int)( (j/delta)),
                                                                (int)( (k/delta)) ) );
               if(novo_raio <= raio*raio)
                   fprintf(file,"%d %d %d %d %d %d \n", (int)( ( (i + param.position.X + fator)/delta) ),
                                                        (int)( ( (i + param.position.X + fator)/delta) ),
                                                        (int)( ( (k + param.position.Z + fator)/delta) ),
                                                        (int)( ( (k + param.position.Z + fator)/delta) ),
                                                        (int)( ( (j + param.position.Y + fator)/delta) ),
                                                        (int)( ( (j + param.position.Y + fator)/delta) )
                                                        );  //end fprintf
            }   //end for k
}
void Cena::geraMalhaAntenna(const Vector3df &position, FILE *file, FILE *file2){
 //--cubo
    int xinicial = -(int)(0.03/delta);
    int xfinal = (int)(0.03/delta);

    int yinicial = -(int)(0.09/delta);
    int yfinal = (int)(0.09/delta);

    int zinicial = -(int)(0.03/delta);
    int zfinal = (int)(0.03/delta);

    fprintf(file, "%d %d %d %d %d %d\n", xinicial + (int)(position.X/delta) + (int)(this->box.MinEdge.X/delta),
                                       xfinal + (int)(position.X/delta) + (int)(this->box.MinEdge.X/delta),
                                       zinicial + (int)(position.Z/delta) + (int)(this->box.MinEdge.Z/delta),
                                       zfinal + (int)(position.Z/delta) + (int)(this->box.MinEdge.Z/delta),
                                       yinicial + (int)(position.Y/delta) + (int)(this->box.MinEdge.Y/delta),
                                       yfinal + (int)(position.Y/delta) + (int)(this->box.MinEdge.Y/delta));

 //--haste
    xinicial = 0;
    xfinal = 0;

    yinicial = 0;
    yfinal = (int)(0.03/delta)-1;

    zinicial = 0;
    zfinal = 0;

    fprintf(file2, "%d %d %d %d %d %d %f\n", xinicial + (int)(position.X/delta) - (int)(this->box.MinEdge.X/delta),
                                             xfinal ,
                                             zinicial + (int)(position.Y/delta) - (int)(this->box.MinEdge.Y/delta),
                                             zfinal ,
                                             yinicial + (int)((position.Y + 0.09)/delta) - (int)(this->box.MinEdge.Y/delta),
                                             yfinal + (int)((position.Y + 0.09)/delta) - (int)(this->box.MinEdge.Y/delta),
                                             7.5);

 //--plano
    xinicial = -(int)(0.3/delta);
    xfinal = (int)(0.3/delta);

    yinicial = 0;
    yfinal = 0;

    zinicial = -(int)(0.3/delta);
    zfinal = (int)(0.3/delta);

    fprintf(file, "%d %d %d %d %d %d\n", xinicial + (int)(position.X/delta) - (int)(this->box.MinEdge.X/delta),
                                        xfinal + (int)(position.X/delta) - (int)(this->box.MinEdge.X/delta),
                                        zinicial + (int)(position.Y/delta) - (int)(this->box.MinEdge.Z/delta),
                                        zfinal + (int)(position.Y/delta) - (int)(this->box.MinEdge.Z/delta),
                                        yinicial + (int)((position.Y + 0.15)/delta) - (int)(this->box.MinEdge.Y/delta),
                                        yfinal + (int)((position.Y + 0.15)/delta) - (int)(this->box.MinEdge.Y/delta));
}

int Cena::calcula_raio(const intVector &p1, const intVector &p2){
    int raio = (p2.X-p1.X)*(p2.X-p1.X) + (p2.Y-p1.Y)*(p2.Y-p1.Y) + (p2.Z-p1.Z)*(p2.Z-p1.Z);
    return raio;
}
int Cena::calcula_raio2(const intVector &p1, const intVector &p2){
    int raio = (p2.X-p1.X)*(p2.X-p1.X) + (p2.Z-p1.Z)*(p2.Z-p1.Z);
    return raio;
}
//--------------------------------EVENTOS-DE-MOUSE-E-TECLADO--------------------------------------//
void Cena::keyPressEvent(QKeyEvent *event){
    if (smgr) {
        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_A))//movimenta objeto em x e y
        {
            key_x_on = true;
            key_y_on = true;
            key_z_on = false;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_S))//movimenta objeto em x e z
        {
            key_x_on = true;
            key_y_on = false;
            key_z_on = true;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_D))//movimenta objeto em y e z
        {
            key_x_on = false;
            key_y_on = true;
            key_z_on = true;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_F))//modivementa objeto nas 3 dimensoes
        {
            key_x_on = true;
            key_y_on = true;
            key_z_on = true;
        }

        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_P))//aproxima camera
        {
            if(camera_01 && (camera->getPosition().Z < (camera->getTarget().X - 10*delta))){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z + delta*2));
            }
            else if(camera_04 && (camera->getPosition().Z > (box.MaxEdge.Z + 10*delta))){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z - delta*2));
            }

            else if(camera_06 && (camera->getPosition().Y < (box.MinEdge.Y - 10*delta))){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y + delta*2,
                                              camera->getPosition().Z ));
            }
            else if(camera_05 && (camera->getPosition().Y > (box.MaxEdge.Y + 10*delta))){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y - delta*2,
                                              camera->getPosition().Z));
            }

            else if(camera_03 && ( camera->getPosition().X < (box.MinEdge.X - 10*delta) )){
                camera->setPosition(Vector3df(camera->getPosition().X + delta*2,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z));
            }
            else if(camera_02 && (camera->getPosition().X > (box.MaxEdge.X + 10*delta))){
                camera->setPosition(Vector3df(camera->getPosition().X - delta*2,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z));
            }
        }


        if((event->modifiers() == Qt::ShiftModifier) && (event->key() == Qt::Key_O))//afasta camera
        {
            if(camera_01 ){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z - afasta*2));
            }
            else if(camera_04){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z + afasta*2));
            }

            else if(camera_06){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y - afasta*2,
                                              camera->getPosition().Z ));
            }
            else if(camera_05){
                camera->setPosition(Vector3df(camera->getPosition().X,
                                              camera->getPosition().Y + afasta*2,
                                              camera->getPosition().Z));
            }

            else if(camera_03){
                camera->setPosition(Vector3df(camera->getPosition().X - afasta*2,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z));
            }
            else if(camera_02){
                camera->setPosition(Vector3df(camera->getPosition().X + afasta*2,
                                              camera->getPosition().Y,
                                              camera->getPosition().Z));
            }
        }

        switch(event->key()){

            case (Qt::Key_X)://ativa movimentacao em x
                key_x_on = true;
                key_y_on = false;
                key_z_on = false;
                break;

            case (Qt::Key_Y)://ativa movimentacao em y
                key_y_on = true;
                key_x_on = false;
                key_z_on = false;
                break;

            case (Qt::Key_Z)://ativa movimentacao em z
                key_z_on = true;
                key_x_on = false;
                key_y_on = false;
                break;

            case (Qt::Key_R)://remove objeto selecioando
                removeSceneNode();
                break;

            case (Qt::Key_C)://duplica objeto selecionado
                duplicateSceneNode();
                break;

            case (Qt::Key_M)://ativa a movimentacao
                key_m_on = true;
                break;

            case (Qt::Key_W):
                aproximaObjetoSelecionado();
                break;

            case (Qt::Key_1): //camera na posicao padrão
                camera->setPosition(Vector3df(dim.X/2, dim.Y/2, -50*delta));
                camera->setTarget(Vector3df(dim.X/2, dim.Y/2, dim.Z/2));

                camera_01 = true;
                camera_02 = false;
                camera_03 = false;
                camera_04 = false;
                camera_05 = false;
                camera_06 = false;
                break;

            case (Qt::Key_2):  //camera posionada na direita
                camera->setTarget(Vector3df(dim.X/2, dim.Y/2, dim.Z/2));
                camera->setPosition(Vector3df(dim.X+50*delta, dim.Y/2, dim.Z/2));

                camera_01 = false;
                camera_02 = true;
                camera_03 = false;
                camera_04 = false;
                camera_05 = false;
                camera_06 = false;
                break;

            case (Qt::Key_3):   //camera posicionada na esquerda
                camera->setTarget(Vector3df(dim.X/2, dim.Y/2, dim.Z/2));
                camera->setPosition(Vector3df(-50*delta, dim.Y/2, dim.Z/2));

                camera_01 = false;
                camera_02 = false;
                camera_03 = true;
                camera_04 = false;
                camera_05 = false;
                camera_06 = false;
                break;

            case (Qt::Key_4):   //camera posionada na parte de tras
                camera->setTarget(Vector3df(dim.X/2, dim.Y/2, dim.Z/2));
                camera->setPosition(Vector3df(dim.X/2, dim.Y/2, dim.Z+50*delta));

                camera_01 = false;
                camera_02 = false;
                camera_03 = false;
                camera_04 = true;
                camera_05 = false;
                camera_06 = false;
                break;

            case (Qt::Key_5):   //camera posionada no topo
                camera->setTarget(Vector3df(dim.X/2, dim.Y/2, dim.Z/2));
                camera->setPosition(Vector3df(dim.X/2, dim.Y+50*delta, dim.Z/2));

                camera_01 = false;
                camera_02 = false;
                camera_03 = false;
                camera_04 = false;
                camera_05 = true;
                camera_06 = false;
                break;

            case (Qt::Key_6):   //camera posionada na base
                camera->setTarget(Vector3df(dim.X/2, dim.Y/2, dim.Z/2));
                camera->setPosition(Vector3df(dim.X/2, -50*delta, dim.Z/2));

                camera_01 = false;
                camera_02 = false;
                camera_03 = false;
                camera_04 = false;
                camera_05 = false;
                camera_06 = true;
                break;

            default:
                break;
        }
        drawIrrlichtScene();
   }
   event->ignore();
}
void Cena::mousePressEvent( QMouseEvent* event )
{
    if (smgr) {
        selection();

        mouseXi = device->getCursorControl()->getPosition().X;
        mouseYi = device->getCursorControl()->getPosition().Y;

        if(selectedSceneNode){
            xi = selectedSceneNode->getPosition().X;
            yi = selectedSceneNode->getPosition().Y;
            zi = selectedSceneNode->getPosition().Z;
        }
        sendMouseEventToIrrlicht(event, true);
        drawIrrlichtScene();
    }
    event->ignore();
}
void Cena::mouseReleaseEvent( QMouseEvent* event )
{
    if (smgr) {
        sendMouseEventToIrrlicht(event, false);
        duplicateNode_mouse_key = false;
        drawIrrlichtScene();
    }
    event->ignore();
}
void Cena::mouseMoveEvent(QMouseEvent *event)
{
    if(smgr)
    {
        if(MoveSceneNode!=0 && key_m_on && gizmo_X!=0 && gizmo_Y!=0 && gizmo_Z!=0 )
        {
            dx = device->getCursorControl()->getPosition().X - mouseXi;
            dy = device->getCursorControl()->getPosition().Y - mouseYi;

            if(key_x_on)
            {
                if(camera_01){
                    MoveSceneNode->setPosition(Vector3df( xi + delta*dx,
                                                          MoveSceneNode->getPosition().Y,
                                                          MoveSceneNode->getPosition().Z ));
                    emit send_position_change();
                }
                else if(camera_04){
                    MoveSceneNode->setPosition(Vector3df( xi + delta*(-dx),
                                                          MoveSceneNode->getPosition().Y,
                                                          MoveSceneNode->getPosition().Z ));
                    emit send_position_change();
                }
                else if(camera_05){
                    MoveSceneNode->setPosition(Vector3df( xi + delta*(-dy),
                                                          MoveSceneNode->getPosition().Y,
                                                          MoveSceneNode->getPosition().Z ));
                    emit send_position_change();
                }

                else if(camera_06){
                    MoveSceneNode->setPosition(Vector3df( xi + delta*(-dy),
                                                          MoveSceneNode->getPosition().Y,
                                                          MoveSceneNode->getPosition().Z ));
                    emit send_position_change();
                }

                gizmo_X->setPosition(MoveSceneNode->getPosition());
                gizmo_X->setVisible(true);

                gizmo_Y->setPosition(MoveSceneNode->getPosition());
                gizmo_Y->setVisible(true);

                gizmo_Z->setPosition(MoveSceneNode->getPosition());
                gizmo_Z->setVisible(true);
                drawIrrlichtScene();
            }

            else if(key_y_on)
            {
                if(camera_05||camera_06){
                    dy = 0;
                }
                MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X, yi - delta*dy, MoveSceneNode->getPosition().Z ));
                emit send_position_change();

                gizmo_X->setPosition(MoveSceneNode->getPosition());
                gizmo_X->setVisible(true);

                gizmo_Y->setPosition(MoveSceneNode->getPosition());
                gizmo_Y->setVisible(true);

                gizmo_Z->setPosition(MoveSceneNode->getPosition());
                gizmo_Z->setVisible(true);
                drawIrrlichtScene();
            }

            else if(key_z_on)
            {
                if(camera_05){
                    MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X,
                                                          MoveSceneNode->getPosition().Y,
                                                          zi + delta*(-dx)));
                    emit send_position_change();
                }
                else if(camera_06){
                    MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X,
                                                          MoveSceneNode->getPosition().Y,
                                                          zi + delta*(dx)));
                    emit send_position_change();
                }
                else if(camera_02){
                    MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X,
                                                          MoveSceneNode->getPosition().Y,
                                                          zi + delta*(dx)));
                    emit send_position_change();
                }

                else if(camera_03){
                    MoveSceneNode->setPosition(Vector3df( MoveSceneNode->getPosition().X,
                                                          MoveSceneNode->getPosition().Y,
                                                          zi + delta*(-dx)));
                    emit send_position_change();
                }

                gizmo_X->setPosition(MoveSceneNode->getPosition());
                gizmo_X->setVisible(true);

                gizmo_Y->setPosition(MoveSceneNode->getPosition());
                gizmo_Y->setVisible(true);

                gizmo_Z->setPosition(MoveSceneNode->getPosition());
                gizmo_Z->setVisible(true);
                drawIrrlichtScene();
            }
        }
    }
    event->ignore();
}
void Cena::sendMouseEventToIrrlicht( QMouseEvent* event,bool pressedDown)
{
    if (smgr)
    {
        irr::SEvent irrEvent;
        irrEvent.EventType = irr::EET_MOUSE_INPUT_EVENT;

        switch (event->button()){
        case Qt::LeftButton:
            irrEvent.MouseInput.Event = pressedDown ?
                    irr::EMIE_LMOUSE_PRESSED_DOWN : irr::EMIE_LMOUSE_LEFT_UP;
            break;
        case Qt::MidButton:
            irrEvent.MouseInput.Event = pressedDown ?
                    irr::EMIE_MMOUSE_PRESSED_DOWN : irr::EMIE_MMOUSE_LEFT_UP;
            break;
        case Qt::RightButton:
            irrEvent.MouseInput.Event = pressedDown ?
                   irr::EMIE_RMOUSE_PRESSED_DOWN : irr::EMIE_RMOUSE_LEFT_UP;
            break;
        default:
            return;
        }
        irrEvent.MouseInput.X = event->x() - (video_driver->getScreenSize().Width)/2;
        irrEvent.MouseInput.Y = -event->y() + (video_driver->getScreenSize().Height)/2;
        irrEvent.MouseInput.Wheel = 0.0f;

        if(pressedDown) mouse_press_position.set(irrEvent.MouseInput.X,irrEvent.MouseInput.Y,0);
        else if(!pressedDown) mouse_release_position.set(irrEvent.MouseInput.X,irrEvent.MouseInput.Y,0);

        device->postEventFromUser(irrEvent);
    }
    event->ignore();
}
//-------------------------------FIM-EVENTOS-DE-MOUSE-E-TECLADO------------------------------------//

//-----------------------------------MODIFICADORES-DE-OBEJTOS--------------------------------------//
void Cena::insertHaste(int id, IrrNode *node, nodeParam* param){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaHaste(smgr, param, nodeName);
        myMap[id] = *param;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete node;
    }
}
void Cena::insertHasteChanged(IrrNode* node, nodeParam* param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        node->criaHaste(smgr, param, nodeName);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::insertCubo(int id, IrrNode* node, nodeParam* param)
{
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaCubo(smgr, param, nodeName);

        irr::scene::ISceneNode *aux = node->getNode();

        nodeParam *cube_parameters = new nodeParam;
        cube_parameters->dimension.set(param->dimension);
        cube_parameters->position.set(param->position);
        cube_parameters->parametros = param->parametros;
        cube_parameters->box = aux->getBoundingBox();
        cube_parameters->type = Cube;
        cube_parameters->propriedade = param->propriedade;

        qDebug()<<"Create prop valor "<<param->propriedade;
        myMap[id] = *cube_parameters;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete cube_parameters;
        delete node;
    }
}
void Cena::insertCuboChanged(IrrNode *node, nodeParam* param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        node->criaCubo(smgr, param, nodeName);
        qDebug()<<"Change prop valor "<<param->propriedade;
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::insertEsfera(int id, IrrNode* node, nodeParam* param)
{
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaEsfera(smgr, param, nodeName);

        irr::scene::ISceneNode *aux = node->getNode();

        nodeParam *esfera_parameters = new nodeParam;
        esfera_parameters->dimension.set(param->dimension);
        esfera_parameters->position.set(param->position);
        esfera_parameters->parametros.set(param->parametros);
        esfera_parameters->type = Esphere;
        esfera_parameters->box = aux->getBoundingBox();

        myMap[id] = *esfera_parameters;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete esfera_parameters;
        delete node;
    }
}
void Cena::insertEsferaChanged(IrrNode *node, nodeParam *param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        node->criaEsfera(smgr, param, nodeName);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::insertCilindro(int id, IrrNode *node, nodeParam* param)
{
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaCilindro(smgr, param, nodeName);

        irr::scene::ISceneNode *aux = node->getNode();

        nodeParam *cilindro_parameters = new nodeParam;
        cilindro_parameters->dimension.set(param->dimension);
        cilindro_parameters->position.set(param->position);
        cilindro_parameters->parametros.set(param->parametros);
        cilindro_parameters->box = aux->getBoundingBox();
        cilindro_parameters->type = Cilindro;

        myMap[id] = *cilindro_parameters;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete cilindro_parameters;
        delete node;
    }
}
void Cena::insertCilindroChanged(IrrNode *node, nodeParam *param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        qDebug()<<"change cilindro, id "<< nodeName;
        node->criaCilindro(smgr, param, nodeName);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::insertCone(int id, IrrNode* node, nodeParam* param)
{
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaCone(smgr, param, nodeName);

        irr::scene::ISceneNode *aux = node->getNode();

        nodeParam *cone_parameters = new nodeParam;
        cone_parameters->dimension.set(param->dimension);
        cone_parameters->position.set(param->position);
        cone_parameters->parametros.set(param->parametros);
        cone_parameters->box = aux->getBoundingBox();
        cone_parameters->type = Cone;

        myMap[id] = *cone_parameters;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete cone_parameters;
        delete node;
    }
}
void Cena::insertConeChanged(IrrNode *node, nodeParam *param, int id){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);
        node->criaCone(smgr, param, nodeName);
        drawIrrlichtScene();
        delete node;
    }
}

void Cena::insertAntenna(int id, IrrNode *node, const Vector3df &position){
    if(smgr)
    {
        irr::c8 nodeName[50];
        sprintf(nodeName, "%d", id);

        node->criaAntenna(smgr, position, nodeName);

        nodeParam *antenna = new nodeParam;
        antenna->position.set(position);
        antenna->type = Antenna;

        myMap[id] = *antenna;
        nodeId[nodeName] = id;

        drawIrrlichtScene();
        delete antenna;
        delete node;
    }
}

void Cena::duplicateSceneNode()
{
    if(smgr){
        if(selectedSceneNode){
            irr::scene::IMeshSceneNode* node = (irr::scene::IMeshSceneNode*)selectedSceneNode->clone();

            node->setPosition(Vector3df(selectedSceneNode->getPosition().X + 10*delta,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
            node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
            selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);

            seletor = smgr->createOctreeTriangleSelector(node->getMesh(), node, 32);
            node->setTriangleSelector(seletor);
            seletor->drop();

            selectedSceneNode = (irr::scene::ISceneNode*)node;
         }
    }
}
void Cena::removeSceneNode()
{
    if(smgr && selectedSceneNode)
    {
        const irr::c8* test = selectedSceneNode->getName();
        int id = getIdFromNode(test);
        it = myMap.find(id);
        myMap.erase(it);

        selectedSceneNode->remove();
        selectedSceneNode = 0;
        gizmo_X->setVisible(false);
        gizmo_Y->setVisible(false);
        gizmo_Z->setVisible(false);

    }
}
void Cena::removeChangedSceneNode(){
    if(smgr){
        if(smgr && selectedSceneNode)
        {
            selectedSceneNode->remove();
            selectedSceneNode = 0;
            gizmo_X->setVisible(false);
            gizmo_Y->setVisible(false);
            gizmo_Z->setVisible(false);
        }
    }
}
void Cena::aproximaObjetoSelecionado(){
    if(smgr && selectedSceneNode){
        if(camera_01){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X,
                                          selectedSceneNode->getPosition().Y,
                                          selectedSceneNode->getPosition().Z - 15*delta));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }
        else if(camera_04){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X,
                                          selectedSceneNode->getPosition().Y,
                                          selectedSceneNode->getPosition().Z + 15*delta));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }

        if(camera_06){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X,
                                          selectedSceneNode->getPosition().Y - 15*delta,
                                          selectedSceneNode->getPosition().Z ));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }
        else if(camera_05){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X,
                                          selectedSceneNode->getPosition().Y + 15*delta,
                                          selectedSceneNode->getPosition().Z));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }

        if(camera_03){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X - 15*delta,
                                          selectedSceneNode->getPosition().Y,
                                          selectedSceneNode->getPosition().Z));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }
        else if(camera_02){
            camera->setPosition(Vector3df(selectedSceneNode->getPosition().X + 15*delta,
                                          selectedSceneNode->getPosition().Y,
                                          selectedSceneNode->getPosition().Z));

            camera->setTarget(Vector3df(selectedSceneNode->getPosition().X,
                                        selectedSceneNode->getPosition().Y,
                                        selectedSceneNode->getPosition().Z));
        }
    }
}
//--------------------------------FIM-MODIFICADORES-DE-OBEJTOS--------------------------------------//

//-----------------------------------------SELECAO-E-PINTURA----------------------------------------//
void Cena::selection()
{
    if(smgr)
    {
        irr::core::vector3df intersection;
        irr::core::triangle3df tri;
        irr::core::line3df ray = smgr->getSceneCollisionManager()->getRayFromScreenCoordinates(
                                                        device->getCursorControl()->getPosition(),
                                                        smgr->getActiveCamera());
        if (selectedSceneNode){
           selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
           selectedSceneNode = 0;
        }

        selectedSceneNode = collMan->getSceneNodeAndCollisionPointFromRay(ray, intersection, tri, S);

         if (selectedSceneNode){
             MoveSceneNode = selectedSceneNode;
             selectedSceneNode->setMaterialFlag(irr::video::EMF_WIREFRAME, true);

             IrrNode* node = new IrrNode();
             nodeDimensions *dimension = new nodeDimensions;

             const irr::c8* test = selectedSceneNode->getName();
             int id = getIdFromNode(test);

             dimension->dimension = myMap[id].dimension;
             dimension->dimension2 = myMap[id].dimension2;
             dimension->raio_haste = myMap[id].raio_haste;
             dimension->parametros = myMap[id].parametros;
             dimension->position = myMap[id].position;
             dimension->propriedade = myMap[id].propriedade;

             irr::core::aabbox3df box = selectedSceneNode->getBoundingBox();

             gizmo_X->remove();
             gizmo_X = 0;

             gizmo_Y->remove();
             gizmo_Y = 0;

             gizmo_Z->remove();
             gizmo_Z = 0;

             node->criaGizmo(smgr, &gizmo_X, &gizmo_Y, &gizmo_Z, box);
             qDebug()<<"Selection prop valor "<<dimension->propriedade;

             emit send_selection_call(dimension);
             delete node;
             delete dimension;
         }
         else
         {
             selectedSceneNode = 0;
             MoveSceneNode = 0;

             gizmo_X->setVisible(false);
             gizmo_Y->setVisible(false);
             gizmo_Z->setVisible(false);

             key_x_on = false;
             key_y_on = false;
             key_z_on = false;
         }
    }
}
void Cena::drawIrrlichtScene()
{
    if(smgr)
    {
        video_driver->beginScene( true, true, irr::video::SColor( 255, 128, 128, 128 ));
        smgr->drawAll();
        env->drawAll();
        printRegiaoAnalise(box);

        video_driver->endScene();
    }
}
//---------------------------------------FIM-SELECAO-E-PINTURA--------------------------------------//
