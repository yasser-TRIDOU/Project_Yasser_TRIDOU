//
// Created by USER on 13/11/2023.
//

#include "Carre.h"
#include <iostream>

Carre::Carre(float x,float y,int TC):Forme2D(x,y,TC)
{

}

void Carre::Afficher()
{
    std::cout << "Les information du carre: Surface :"<< Surface() << " cm2 Avec Taille cote :" << m_TailleCote << std::endl;
}

int Carre::Surface()
{
    return m_TailleCote*m_TailleCote;
}

Carre::~Carre()
{
    std::cout << "Calling Detractor Carre" << std::endl;
}