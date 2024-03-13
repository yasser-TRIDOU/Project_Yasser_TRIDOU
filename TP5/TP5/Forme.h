#ifndef TP5_FORME_H
#define TP5_FORME_H

#include "problem2/ListeObjet.h"

class Forme:public Objet
{
public:
    virtual int Surface()=0;
    virtual ~Forme();
};


#endif //TP5_FORME_H
