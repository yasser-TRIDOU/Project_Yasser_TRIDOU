//
// Created by USER on 13/11/2023.
//

#ifndef TP5_POINT_H
#define TP5_POINT_H


class Point {

public:
    float m_x;
    float m_y;

    Point()
    {
        m_x=0;
        m_y=0;
    }

    Point(float x,float y)
    {
        m_x=x;
        m_y=y;
    }

    ~Point();
};


#endif //TP5_POINT_H
