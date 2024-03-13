#include "class_data.h"


Matrice& operator+=(Matrice& Myinstance,const Matrice& M)
{

    if(Myinstance.m_Ordre1==M.m_Ordre1 && Myinstance.m_Ordre2==M.m_Ordre2)
    {
        for(int i=0;i<Myinstance.m_Ordre1;i++)
            for(int j=0;j<Myinstance.m_Ordre2;j++)
                Myinstance.Tab[i][j]+=M.Tab[i][j];
    }
    return Myinstance;

}
Matrice operator+(const Matrice& Myinstance,const Matrice& M)
{

    if(Myinstance.m_Ordre1==M.m_Ordre1 && Myinstance.m_Ordre2==M.m_Ordre2)
    {
        Matrice Tmp(Myinstance.m_Ordre1,Myinstance.m_Ordre2);
        for(int i=0;i<Myinstance.m_Ordre1;i++)
            for(int j=0;j<Myinstance.m_Ordre2;j++)
                Tmp.Tab[i][j]=M.Tab[i][j]+Myinstance.Tab[i][j];
        return Tmp;
    }
    return Myinstance;
}

Matrice operator*(const Matrice& Myinstance,const Matrice& M)
{
    if(Myinstance.m_Ordre1==M.m_Ordre1 && Myinstance.m_Ordre2==M.m_Ordre2)
    {
        Matrice M5(3,3);
        for(int i=0;i<Myinstance.m_Ordre1;i++)
        {
            for(int j=0;j<Myinstance.m_Ordre2;j++)
            {
                int m=0,k=0;
                int sm=0;
                while (m<Myinstance.m_Ordre1 && k<M.m_Ordre2)
                    sm+=Myinstance.Tab[i][m++]*M.Tab[k++][j];
                M5.Tab[i][j]=sm;
            }
        }
        return M5;
    }
    return Myinstance;

}
