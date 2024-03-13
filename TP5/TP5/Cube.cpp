//
// Created by USER on 13/11/2023.
//

#include "Cube.h"
#include <iostream>
#include "Forme3D.h"

Cube::Cube(float x,float y,float z,int TC): Forme3D(x,y,z) {
    m_Taillecote=TC;
}


void Cube::Afficher()
{
    std::cout << "Le cube avec Taille cote :" << m_Taillecote
    << " Surface : "<< Surface() << " cm2 Volume : " << Volume() << "cm3"<< std::endl;
}

int Cube::Surface()
{
    return m_Taillecote*m_Taillecote*6;
}

int Cube::Volume()
{
    return m_Taillecote*3;
}

Cube::~Cube()
{
    std::cout << "Calling Detractor Cube" << std::endl;

}
