
#include "Forme3D.h"
#include "Point3D.h"
#include <iostream>

Forme3D::Forme3D(float x,float y,float z):m_Centre(x,y,z)
{

}

Point3D& Forme3D::GetCentre()
{
    return m_Centre;
}


Forme3D::~Forme3D()
{
    std::cout << "Calling Detractor Forme3D" << std::endl;
}













