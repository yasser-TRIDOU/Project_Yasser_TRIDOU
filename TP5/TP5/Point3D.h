//
// Created by USER on 13/11/2023.
//

#ifndef TP5_POINT3D_H
#define TP5_POINT3D_H


class Point3D
{

public:
    float m_x;
    float m_y;
    float m_z;

    Point3D()
    {
        m_x=0;
        m_y=0;
        m_z=0;
    }

    Point3D(float x,float y,float z)
    {
        m_x=x;
        m_y=y;
        m_z=z;
    }

    ~Point3D();
};


#endif //TP5_POINT3D_H
