#include "object.h"

Object::Object(){
    property = G_C_PR_NONE;
    generation = 0;
}

Object::Object(QPoint point, uint property, uint generation){
    this->point = point;
    this->property = property;
    this->generation = generation;
}

Object::Object(uint x, uint y, uint property, uint generation){
    point.setX(x);
    point.setY(y);
    this->property = property;
    this->generation = generation;
}
