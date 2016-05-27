#ifndef OBJECT_H
#define OBJECT_H

#include<QPoint>
#include"gameconst.h"

class Object{
    typedef unsigned int uint;

public:
    Object();
    Object(QPoint point, uint property = 0, uint generation = 0);
    Object(uint x, uint y, uint property = 0, uint generation = 0);

    //Getters
    QPoint getPoint(){return point;}
    uint getProperty(){return property;}
    uint getGeneration(){return generation;}

    //Setters
    void setPoint(QPoint point){this->point = point;}
    void setPoint(int x, int y){point.setX(x); point.setY(y);}
    void setGeneration(uint generation){this->generation = generation;}
    void setProperty(uint property){this->property = property;}

private:
    QPoint point;
    uint property;
    uint generation;

};

#endif // OBJECT_H
