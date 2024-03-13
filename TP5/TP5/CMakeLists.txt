cmake_minimum_required(VERSION 3.22)
project(TP5)

set(CMAKE_CXX_STANDARD 17)

set(FICHIERS Forme.h
        Forme2D.cpp
        Forme2D.h
        Forme3D.cpp
        Forme3D.h
        Cube.cpp
        Cube.h
        Carre.cpp
        Carre.h
        Cercle.cpp
        Cercle.h
        Point.cpp
        Point.h
        Point3D.cpp
        Point3D.h
        Forme.cpp
        )

add_executable(TP5 main.cpp
        ${FICHIERS})
add_executable(pobelem2 problem2/main.cpp
        ${FICHIERS}
        problem2/Objet.cpp
        problem2/Objet.h
        problem2/ListeObjet.cpp
        problem2/ListeObjet.h)

