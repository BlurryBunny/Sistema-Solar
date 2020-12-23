/*-----------Planet Class---------------*/
#include <vector>
#include <fstream>
#include<bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <armadillo>
#include <stdlib.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Face.hpp"
#include "Object.hpp"
#include "Transform.hpp"
#include "Planet.hpp"

using namespace std;

Planet::Planet(){
    planet_name="none";
    file_name="objetos/roca.obj";
    angle=0.0f;
    
}

Planet::Planet(std::string name_p, std::string name_f){
	planet_name= name_p;
    file_name= name_f;
    angle=0.0f;

    //si todos van a ocupar el mismo renderizado se puede usar la misma lectura para todos los planetas.
}

void Planet :: create_obj(){
    cout<<file_name<<endl;
    cout<<"estamos creando objeto"<<endl;
    myPlanet = Object(file_name);
    myPlanet.read_for_split();
}

void Planet :: rotate_translade(){

    if(planet_name!="Sol"){
        //incremento al angulo con el rota el planeta respecto al sol
        angle = (angle < 360.0f) ? angle+aceleration : 0.0f;
    }
}

void Planet::move_and_paint(arma::fmat transf_toMult){

    //Actualiza el angulo.
    rotate_translade();

    Transform Tr = Transform();
    std::vector<int> index_vertices = myPlanet.get_Allfaces_index_vertex();
    std::vector<Vertex> planet_vertices= myPlanet.get_vertexList();
    std::vector<Vertex> new_vertexs;

    //Si no es sol entonces es un planeta.
    if(planet_name!="Sol"){
        if(planet_name!="Luna"){
            transf=Tr.R(0.0f, 1.0f, 0.0f, angle) * Tr.T(position, 0.0, 0.0) * Tr.S(tam,tam,tam) * transf_toMult ;
        }else{
            transf= transf_toMult* Tr.R(0.0f, 1.0f, 0.0f, angle) * Tr.T(position, 0.0, 0.0) * Tr.S(tam,tam,tam);
        }
    }else{
        transf=Tr.S(2.0, 2.0, 2.0);
    }

    //se ponen los vertices en la nueva 
        for ( unsigned int i=0; i<index_vertices.size(); i++ ) {
            arma::fcolvec v = planet_vertices[index_vertices[i]].get_value_toTransform();
            arma::fcolvec vp = transf * v;
            Vertex rv = Vertex();
            rv.set_value(arma::trans(vp));
            new_vertexs.push_back(rv);
        }
        
        glColor3f(r,g,b);
        glBegin(GL_TRIANGLES);
        for ( unsigned int i=0; i<new_vertexs.size(); i++ ) {
            arma::frowvec vert = new_vertexs[i].get_value_3dView();
            glVertex3f(vert[0], vert[1], vert[2]);
        }
        glEnd();
        // Fin dibujado de la Tierra
}

void Planet:: set_value_transform(arma::fmat transf){
    this->transf=transf;
}

float Planet:: get_value_angle(){
    return angle;
}

void Planet::set_color(arma::frowvec new_color){
    color={new_color[0],new_color[1],new_color[2]};
}

void Planet::set_color_rgb(float r, float g, float b){
    this->r=r;
    this->g=g;
    this->b=b;
}

void Planet::set_aceleration(float aceleration){
    this->aceleration=aceleration;
}

void Planet:: set_position(float position){
    this->position=position;
}

void Planet:: set_tam(float tam){
    this->tam=tam;
}

std::string Planet:: get_planetName(){
    return planet_name;
}

arma::fmat Planet:: get_transf(){
    return (transf);
}

