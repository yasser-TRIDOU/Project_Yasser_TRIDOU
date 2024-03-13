

#ifndef TP5_CERCLE_H
#define TP5_CERCLE_H

#include <iostream>
#include "vector"
#include "Forme2D.h"


class Cercle : public Forme2D{

public:
    Cercle(float x,float y,int TC);
    void Afficher() override;
    int Surface() override;
    ~Cercle();

};


#endif //TP5_CERCLE_H
