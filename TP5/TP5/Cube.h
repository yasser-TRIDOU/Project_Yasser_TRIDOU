//
// Created by USER on 13/11/2023.
//

#ifndef TP5_CUBE_H
#define TP5_CUBE_H
#include "Forme3D.h"

class Cube : public Forme3D{

    int m_Taillecote;
public:
    Cube(float x,float y,float z,int TC);
    void Afficher() override;
    int Surface() override;
    int Volume() override;
    ~Cube();
};


#endif //TP5_CUBE_H
