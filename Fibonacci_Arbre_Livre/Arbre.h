//
// Created by USER on 04/12/2023.
//

#ifndef PROGGEN_ARBRE_H
#define PROGGEN_ARBRE_H

#include <iostream>
#include <stack>
#include <queue>
#include <vector>


template<typename T>
struct cl {
    T data;
    int occ = 1;
    std::vector<int> Ligne;
    struct cl *fg;
    struct cl *fd;
};

template<typename T>
struct cl2 {
    cl<T> *data;
    cl2 *suiv;
};


template<typename T>
struct file {
    cl2<T> *tete;
    cl2<T> *fin;
public:
    file() {
        tete = nullptr;
        fin = nullptr;
    }

    void enfiler(cl2<T> *cellule) {
        if (!cellule)return;
        if (!tete) {
            tete = cellule;
            fin = cellule;
        } else {
            fin->suiv = cellule;
            fin = cellule;
        }
    }

    int est_vide() {
        return tete == nullptr;
    }

    cl2<T> *defiler() {
        cl2<T> *p;
        if (tete == fin) {
            p = tete;
            tete = nullptr;
            fin = nullptr;
            return p;
        } else {
            p = tete;
            tete = tete->suiv;
            return p;
        }
    }
};


template<typename T>
class Arbre {
private:
    cl<T> *Ar;

    cl<T> *InsererP(cl<T> *A, T _val, int line) {
        int PG, PD;
        if (!A) {
            cl<T> *Tmp = new struct cl<T>;
            Tmp->Ligne.push_back(line);
            Tmp->data = _val;
            Tmp->fg = nullptr;
            Tmp->fd = nullptr;
            return Tmp;
        } else {
            if (A->data > _val) {
                A->fg = InsererP(A->fg, _val, line);

            } else {
                A->fd = InsererP(A->fd, _val, line);
            }
        }
        PG = ProfondeurNoudPrivate(A->fg);
        PD = ProfondeurNoudPrivate(A->fd);
        int diff = PD - PG;
        if ((diff < -1) || (diff > 1)) {
            cl<T> *p, *q, *q1, *p1;
            if (PD < PG) {// Y in Left
                if (SearchPrivate(A->fg->fd, _val)) { // LR
                    //Left Rotion -> Right Rotation
                    //Etape 1
                    p = A->fg;
                    A->fg = A->fg->fd;
                    p1 = A->fg->fg;
                    A->fg->fg = p;
                    p->fd = p1;
                    //Etape 2
                    q = A->fg;
                    q1 = A->fg->fd;
                    A->fg = nullptr;
                    q->fd = A;
                    A->fg = q1;
                    return q;
                } else { // LL
                    p = A->fg;
                    A->fg = nullptr;
                    q = p->fd;
                    p->fd = A;
                    A->fg = q;
                    return p;
                }
            } else {// Y in Right
                if (SearchPrivate(A->fd->fg, _val)) { //RL
                    p = A->fd;
                    A->fd = A->fd->fg;
                    p1 = A->fd->fd;
                    A->fd->fd = p;
                    p->fg = p1;
                    //Etape 2
                    q = A->fd;
                    q1 = A->fd->fg;
                    A->fd = nullptr;
                    q->fg = A;
                    A->fd = q1;
                    return q;
                } else { //RR
                    p = A->fd;
                    A->fd = nullptr;
                    q = p->fg;
                    p->fg = A;
                    A->fd = q;
                    return p;
                }
            }
        }
        return A;
    }

    void Print(cl<T> *A) const {
        if (A) {
            Print(A->fg);
            std::cout << "Valeur est :" << A->data << std::endl;
            Print(A->fd);
        }
    }

    void displayHorizontal(cl<T> *A, int level) const {

        if (A) {
            displayHorizontal(A->fd, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "\t";
            std::cout << A->data << std::endl;
            this->displayHorizontal(A->fg, level + 1);
        }
    }

    int SearchPrivate(cl<T> *A, T data) {
        if (A) {
            if (A->data == data)
                return 1;
            else {
                if (data > A->data)
                    return SearchPrivate(A->fd, data);
                else return SearchPrivate(A->fg, data);
            }
        }
        return 0;
    }

    int ProfondeurNoudPrivate(cl<T> *A) {
        if (!A)return 0;
        else {
            int PrG = ProfondeurNoudPrivate(A->fg);
            int PrD = ProfondeurNoudPrivate(A->fd);
            return (PrG > PrD ? PrG : PrD) + 1;
        }
    }

    bool prDFSrecursif(cl<T> *Ar, T val) {
        if (Ar) {
            if (Ar->data == val)return true;
            bool g = prDFSrecursif(Ar->fg, val);
            bool d = prDFSrecursif(Ar->fd, val);
            return g || d;
        }
        return false;
    }

public:
    Arbre() {
        Ar = nullptr;
    }

    void Inser(T _val, int ligne) {
        Ar = InsererP(Ar, _val, ligne);
    }

    cl<T> *BFSrechercheFromScratch(T val) {
        if (!Ar)return nullptr;
        file<T> *f = new file<T>();
        cl2<T> *tmp = new cl2<T>();
        tmp->data = Ar;
        tmp->suiv = nullptr;
        f->enfiler(tmp);
        while (!f->est_vide()) {
            cl2<T> *tt = f->defiler();
            if (tt->data->data == val)
                return tt->data;
            if (tt->data->fg) {
                cl2<T> *tt1 = new cl2<T>;
                tt1->data = tt->data->fg;
                tt1->suiv = nullptr;
                f->enfiler(tt1);
            }
            if (tt->data->fd) {
                cl2<T> *tt1 = new cl2<T>;
                tt1->data = tt->data->fd;
                tt1->suiv = nullptr;
                f->enfiler(tt1);
            }
        }
        return nullptr;
    }

    cl<T> *BFSrechercheSTL(T val) {
        if (!Ar)return nullptr;
        std::queue<cl<T> *> fl;
        fl.push(Ar);
        while (!fl.empty()) {
            cl<T> *tt = fl.front();
            fl.pop();
            if (tt->data == val)
                return tt;
            if (tt->fg)
                fl.push(tt->fg);
            if (tt->fd)
                fl.push(tt->fd);
        }
        return nullptr;
    }


    bool DFSrechercheRec(T val) {
        if (!Ar)return false;
        if (prDFSrecursif(Ar, val))
            return true;
        else return false;
    }

    cl<T> *DFSrechercheSTL(T val) {

        if (!Ar)return nullptr;
        std::stack<cl<T> *> sta;
        sta.push(Ar);
        while (!sta.empty()) {
            cl<T> *no = sta.top();
            sta.pop();
            if (no->data == val)return no;
            if (no->fd)
                sta.push(no->fd);
            if (no->fg)
                sta.push(no->fg);
        }
        return nullptr;
    }


    void AfficherLineaire() const {
        if (!Ar) {
            std::cout << "Arbre vide " << std::endl;
            return;
        } else {
            Print(Ar);
        }
    }

    void AffichageGraphique() const {
        if (!Ar)
            std::cout << "Arbre Vide" << std::endl;
        else
            displayHorizontal(Ar, 0);
    }

    void Search(T _val) {
        if (SearchPrivate(Ar, _val))
            std::cout << "La valeur Existe" << std::endl;
        else
            std::cout << "La valeur n'existe pas" << std::endl;
    }


};


#endif //PROGGEN_ARBRE_H
