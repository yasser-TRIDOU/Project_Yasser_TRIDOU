#include <iostream>
#ifndef TP1_CLASS_DATA_H
#define TP1_CLASS_DATA_H



class Point {
private:
    float m_x;
    float m_y;


public:

    Point()
    {
        m_x=0;
        m_y=0;
    }

    void Saisie(float x,float y);

    void Afficher() const ;


    void Translater(float x,float y);

    void echelle(float echele1,float echele2);

    float Distance(const Point& point) const;




};

class Triangle {
public:

    Point m_p1;
    Point m_p2;
    Point m_p3;
    void Saisie(const Point& p1,const Point& p2,const Point& p3);
    void afficher() const;
    void translater(float x,float y);
    void Echelle(float echelle1,float echelle2);
    float cote1() const;
    float cote2() const;
    float cote3() const;
    bool isocele() const;
    bool equilateral() const;
    float Perimetre() const;

};


class Pile
{
public:
    int *Tab;
    int Nbelem;
    Pile()//constructor par defaut
    {
        Tab= nullptr;
        Nbelem=0;
    }

//on l'appelle exemple Pile p=q ; cad on a appeller Pile() apres on va appeler
//Pile(const Pile& pile)
    Pile(const Pile& pile)
    {
        if(this != &pile)
        {
            Tab=new int[pile.Nbelem];
            Nbelem=pile.Nbelem;
            for(int i=0;i<pile.Nbelem;i++)
                Tab[i]=pile.Tab[i];
        }
    }

    Pile& operator =(const Pile& pile)
    {
        if(this != &pile)
        {
            delete [] Tab;
            Tab= nullptr;
            Tab=new int[pile.Nbelem];
            Nbelem=pile.Nbelem;
            for(int i=0;i<pile.Nbelem;i++)
                Tab[i]=pile.Tab[i];
        }
        return *this;
    }
    friend Pile& operator<< (Pile& pile ,int val);
    friend Pile& operator>> (Pile& p1,int& val);
    void Empiler(int val);
    void Depiler();
    void Afficher();

};

class Matrice
{

public:
    int** Tab;
    int m_Ordre1;
    int m_Ordre2;


    Matrice()
    {
        Tab= nullptr;
        m_Ordre1=0;
        m_Ordre2=0;
    }

    Matrice(int nord1,int nord2)
    {
        m_Ordre1=nord1;
        m_Ordre2=nord2;
        Tab=new int* [nord1];
        for(int i=0;i<nord1;i++)
            Tab[i]=new int [nord2];

        for(int i=0;i<nord1;i++)
            for(int j=0;j<nord2;j++)
                Tab[i][j]=0;
    }
    //on a pas besoin de vider mémoire
    Matrice(const Matrice& M)//constructeur de copie
    {
        int** MatTmp=new int* [M.m_Ordre1];
        for(int i=0;i<M.m_Ordre1;i++)
            MatTmp[i]=new int [M.m_Ordre2];

        for(int i=0;i<M.m_Ordre1;i++)
            for(int j=0;j<M.m_Ordre2;j++)
                MatTmp[i][j]=M.Tab[i][j];

        m_Ordre1=M.m_Ordre1;
        m_Ordre2=M.m_Ordre2;
        Tab=MatTmp;
    }

    //on aura besoin de vider l'ancien memoire
     Matrice& operator=(const Matrice&M)
    {
        if(this!=&M)
        {
            for(int i=0;i<m_Ordre1;i++)
                delete [] Tab[i];
            delete [] Tab;

            m_Ordre1=M.m_Ordre1;
            m_Ordre2=M.m_Ordre2;

            Tab=new int* [M.m_Ordre1];
            for(int i=0;i<M.m_Ordre1;i++)
                Tab[i]=new int [m_Ordre2];

            for(int i=0;i<m_Ordre1;i++)
                for(int j=0;i<M.m_Ordre2;j++)
                    Tab[i][j]=M.Tab[i][j];
        }
        return *this;
    }

    ~Matrice()
    {
        for(int i=0;i<m_Ordre1;i++)
            delete [] Tab[i];
        delete [] Tab;
    }

    friend Matrice& operator+=(Matrice& Myinstance,const Matrice& M);
    friend Matrice operator*(const Matrice& Myinstance,const Matrice& M);


    Matrice& operator-=(const Matrice& M)
    {

        if(m_Ordre1==M.m_Ordre1 && m_Ordre2==M.m_Ordre2)
        {
            for(int i=0;i<m_Ordre1;i++)
                for(int j=0;j<m_Ordre2;j++)
                    Tab[i][j]-=M.Tab[i][j];
        }
        return *this;
    }

    Matrice& operator*=(const Matrice& M)
    {

        Matrice M5(M.m_Ordre1,M.m_Ordre2);

        if(m_Ordre1==M.m_Ordre1 && m_Ordre2==M.m_Ordre2)
        {
            for(int i=0;i<m_Ordre1;i++)
            {
                for(int j=0;j<m_Ordre2;j++)
                {
                    int m=0,k=0;
                    int sm=0;
                    while (m<m_Ordre1 && k<M.m_Ordre2)
                        sm+=Tab[i][m++]*M.Tab[k++][j];
                    M5.Tab[i][j]=sm;
                }
            }
            for(int i=0;i<m_Ordre1;i++)
                for(int j=0;j<m_Ordre2;j++)
                    Tab[i][j]=M5.Tab[i][j];
        }
        return M;
    }


    void Set(int x,int y,int val) const
    {
        Tab[x][y]=val;
    }

    void Afficher() const
    {
        for(int i=0;i<m_Ordre1;i++)
        {
            for(int j=0;j<m_Ordre2;j++)
            {
                std::cout << Tab[i][j]<<" ";
            }
            std::cout << "\n";
        }
    }




};




#endif //TP1_CLASS_DATA_H
