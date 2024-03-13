#include <iostream>
#include "../Carre.h"
#include "../Cercle.h"
#include "../Cube.h"
#include "ListeObjet.h"


int main()
{

    ListeObjet L;
    Carre* C=new Carre(10,10,12);
    L.AddObject(C);
    L.AfficherObjet(0);

    return 0;
}