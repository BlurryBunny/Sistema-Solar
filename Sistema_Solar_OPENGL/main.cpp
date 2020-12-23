#include <stdio.h>
#include<bits/stdc++.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include <string>
#include <vector>

#include "include/Vertex.hpp"
#include "include/Edge.hpp"
#include "include/Face.hpp"
#include "include/Object.hpp"
#include "include/Transform.hpp"
#include "include/Planet.hpp"
//Planetas del sistema solar mas la luna de la tierra y el sol
#define N_Planets 10
using namespace std;
int main()
{
    cout<<"hola inicial"<<endl;
    arma::frowvec eye = {0.0, 1.0, 20.0};
    arma::frowvec camera = {0.0, 1.0, 20.0};
    arma::frowvec viewup = {0.0, 1.0, 0.0};
    
    GLFWwindow* window;
    
    /*
    std::vector<Object> obj_planets;

    for(unsigned int i=0; i<2; i++){
        obj_planets.add(Object("objetos/roca.obj"));
        obj_planets[obj_planets.size()-1].read_for_split();
    }
    */

    if( !glfwInit() )
    {
        fprintf( stderr, "Fallo al inicializar GLFW\n" );
        getchar();
        return -1;
    }

    window = glfwCreateWindow(1024, 768, "Sistema Solar", NULL, NULL);
    if( window == NULL ) {
        fprintf( stderr, "Fallo al abrir la ventana de GLFW.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

//  Proyecciones
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    float ar = width / height;

//  Proyección en paralelo
    glViewport(0, 0, width, height);
    glOrtho(-30, 30, -4.0, 4.0, -30.0, 30.0);
    //glRotatef(90,0,1,0);
    glRotatef(40,0,1,0);
    glRotatef(20,1,0,1);

//  Proyección en perspectiva
    //glFrustum(-5, 5, -5, 5, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //coleccion que almacena todos los planetas
    std::vector<Planet> planets;
    
    //nombres de todos los planetas
    std::vector<std::string> planet_names;
    planet_names.push_back("Sol");
    planet_names.push_back("Mercurio");
    planet_names.push_back("Venus");
    planet_names.push_back("Tierra");
    planet_names.push_back("Luna");
    planet_names.push_back("Marte");
    planet_names.push_back("Jupiter");
    planet_names.push_back("Saturno");
    planet_names.push_back("Urano");
    planet_names.push_back("Neptuno");
    /*
    std::vector<arma::frowvec> planet_colors;
    planet_colors.push_back(arma::frowvec({{1.0},{1.0},{0.0}}));
    planet_colors.push_back(arma::frowvec({{0.0},{0.0},{1.0}}));
    */


    //inicializacion de la lista de planetas
    //for(int i=0; i<N_Planets;i++){
    for(unsigned int i=0; i<planet_names.size();i++){

        Planet mp=Planet(planet_names[i],"objetos/roca.obj");
        mp.create_obj();
        //mp.set_color(planet_colors[i]);
    	planets.push_back(mp);
    }
    //Tr.R(0.0f, 1.0f, 0.0f, mer_angle) * Tr.T(position, 0.0, 0.0) * Tr.S(tam,tanm,tam) * transf_toMult;

    float tamTierra=2.0/5;
    /*-------------------------- Set colors // aceleration --------------------------*/
    /*0.5 sera el valor de comparacion para rotacion, representando un anio terrestre*/
    /*-------------------------- sol --------------------------*/
    planets[0].set_color_rgb(1.0,1.0,0.0);

     /*-------------------------- mercurio --------------------------*/
    planets[1].set_color_rgb(0.1,0.1,0.1); 
    planets[1].set_aceleration(2.0);
    planets[1].set_position(-2.5);
    planets[1].set_tam(tamTierra*0.4);

     /*-------------------------- venus --------------------------*/
    planets[2].set_color_rgb(0.1,0.1,0.0); 
    planets[2].set_aceleration(0.8);
    planets[2].set_position(-3.5);
    planets[2].set_tam(tamTierra*0.95);

    /*-------------------------- tierra --------------------------*/
    planets[3].set_color_rgb(0.0,0.5,0.5); 
    planets[3].set_aceleration(0.5);
    planets[3].set_position(-5);
    planets[3].set_tam(tamTierra);

     /*-------------------------- Luna --------------------------*/
    planets[4].set_color_rgb(0.5,0.1,0.1); 
    planets[4].set_aceleration(2.5);
    planets[4].set_position(-5.5);
    planets[4].set_tam(tamTierra*0.16);

     /*-------------------------- Marte --------------------------*/
    planets[5].set_color_rgb(1.0,0.0,0.0); 
    planets[5].set_aceleration(0.3333);
    planets[5].set_position(-7.0);
    planets[5].set_tam(tamTierra*0.55);

     /*-------------------------- Jupiter --------------------------*/
    planets[6].set_color_rgb(1.0,0.5,0.0); 
    planets[6].set_aceleration(0.05);
    planets[6].set_position(-9.0);
    planets[6].set_tam(tamTierra*11.2);

     /*-------------------------- Saturno --------------------------*/
    planets[7].set_color_rgb(0.1,0.0,0.0); 
    planets[7].set_aceleration(0.01666);
    planets[7].set_position(-11.5);
    planets[7].set_tam(4.75);

     /*-------------------------- Urano --------------------------*/
    planets[8].set_color_rgb(0.0,0.5,1.0); 
    planets[8].set_aceleration(0.006);
    planets[8].set_position(-15);
    planets[8].set_tam(tamTierra*9.5);

    /*-------------------------- Neptuno --------------------------*/
    planets[9].set_color_rgb(0.0,0.1,0.1); 
    planets[9].set_aceleration(0.003);
    planets[9].set_position(-19);
    planets[9].set_tam(tamTierra*3.8);

    //Transformacion del sol
    Transform Tr = Transform();
    arma::fmat transf_sol;
    transf_sol=Tr.S(0.6, 0.6, 0.6);

    do {
        glClear( GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT );

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //visibilidad
        /*gluLookAt(eye[0], eye[1], eye[2], 
                camera[0], camera[1], camera[2], 
                viewup[0], viewup[1], viewup[2])*/;

        //movimiento, rotacion y dibujado de cada planeta 
        for(unsigned int i=0; i<planets.size();i++){

            if(planets[i].get_planetName()!="Luna"){
                planets[i].move_and_paint(transf_sol);
            }else{
                planets[i].move_and_paint(planets[3].get_transf());
            }
        }
    
        glfwSwapBuffers(window);
        glfwPollEvents();

    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    glfwTerminate();

    return 0;
}
