//
// Created by USER on 13/11/2023.
//

#ifndef TP5_FORME3D_H
#define TP5_FORME3D_H

#include "Forme.h"
#include "Point3D.h"



class Forme3D : public Forme{

protected:
    Point3D m_Centre;
public:
    virtual int Volume()=0;
    Forme3D(float x,float y,float z);
    Point3D& GetCentre();
    virtual ~Forme3D();

};


#endif //TP5_FORME3D_H
