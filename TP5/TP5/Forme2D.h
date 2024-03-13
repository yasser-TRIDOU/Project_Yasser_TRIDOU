//
// Created by USER on 13/11/2023.
//

#ifndef TP5_FORME2D_H
#define TP5_FORME2D_H
#include "Forme.h"
#include "Point.h"


class Forme2D :public Forme{

protected:
    int m_TailleCote;
    Point Centre;
public:
    Forme2D(float x,float y,int TC);
    Point& GetCentre();
    virtual ~Forme2D();
};


#endif //TP5_FORME2D_H
