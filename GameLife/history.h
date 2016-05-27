#ifndef HISTORY_H
#define HISTORY_H

#include<QVector>
#include"object.h"

class History
{
public:
    QVector<Object> configLIFE;
    QVector<Object> configNULL;
    History(){}
};

#endif // HISTORY_H
