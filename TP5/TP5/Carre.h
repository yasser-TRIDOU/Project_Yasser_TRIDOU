//
// Created by USER on 13/11/2023.
//

#ifndef TP5_CARRE_H
#define TP5_CARRE_H

#include "Forme2D.h"

class Carre: public Forme2D{

public:
    Carre(float x,float y,int TC);
    void Afficher() override;
    int Surface() override;
    ~Carre();
};


#endif //TP5_CARRE_H
