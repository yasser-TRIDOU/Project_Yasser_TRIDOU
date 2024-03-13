//
// Created by USER on 19/11/2023.
//

#include "ListeObjet.h"


ListeObjet::ListeObjet() {
    M_Nbelem=0;
}

ListeObjet::~ListeObjet() {
    for(int i=0;i<M_Nbelem;i++)
        delete M_LObjet[i];
}


void ListeObjet::AddObject(Objet* OB) {
    if(!M_Nbelem) M_LObjet[0]=OB;
    else M_LObjet[M_Nbelem-1]=OB;
    M_Nbelem++;
}


void ListeObjet::AfficherObjet(int i) {
    M_LObjet[i]->Afficher();
}





