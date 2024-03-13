//
// Created by USER on 19/11/2023.
//

#ifndef TP5_LISTEOBJET_H
#define TP5_LISTEOBJET_H

#include "Objet.h"
#include <vector>
#define N 100


class ListeObjet {

private:
    Objet* M_LObjet[N];
    int M_Nbelem;
public:
    ListeObjet();
    ~ListeObjet();
    void AddObject(Objet* O);
    void AfficherObjet(int i);
};


#endif //TP5_LISTEOBJET_H
