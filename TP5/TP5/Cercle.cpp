#include "Cercle.h"
#include <iostream>
#include <cmath>

Cercle::Cercle(float x,float y,int TC): Forme2D(x,y,TC)
{

}

void Cercle::Afficher(){
    std::cout << "Les information du cercle: Surface : "<< Surface() << " cm2 Avec Taille Rayon :" << m_TailleCote << std::endl;

}
int Cercle::Surface(){

    return (int)(3.14*pow(m_TailleCote,2));
}

Cercle::~Cercle()
{
    std::cout << "Calling Detractor Cercle" << std::endl;
}
