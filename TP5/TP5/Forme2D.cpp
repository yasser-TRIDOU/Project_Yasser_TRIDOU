//
// Created by USER on 13/11/2023.
//

#include "Forme2D.h"
#include "Point.h"
#include <iostream>



Forme2D::Forme2D(float x,float y,int TC):Centre(x,y)
{
    m_TailleCote=TC;
}

Point& Forme2D::GetCentre()
{
    return Centre;
}

Forme2D::~Forme2D()
{
    std::cout << "Calling Detractor Forme2D" << std::endl;

}