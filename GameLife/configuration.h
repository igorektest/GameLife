#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include"object.h"
#include"rules.h"
#include"history.h"
#include<QVector>
#include<QString>
#include<cmath>

class Configuration
{
    typedef unsigned int uint;

public:
    Configuration();
    Object getObject(uint num, QString searchType); //+
    void addObject(Object); //+
    void delObject(Object obj); //+
    void nextConfig(); //+
    void prevConfig(); //-
    void setSizeMap(float size); //+
    float getSizeMap(); //+
    uint getGeneration(); //+
    void deleteHistory(); //-
    uint getSize(QString searchType); //+
    void deleteConfig(); //+
    bool setRules(Rules); //-
    Rules getRules(); //-

private:
    QVector<Object> configLIFE;                // +
    QVector<Object> configNULL;                // +
    QVector<History> history;     // -
    float sizeMap;                             // +
    uint generation;                           // -

private:
    void createMap(Object obj); //+
    Object getObject(Object obj, QString str, QString searchType = G_C_CONFIG_LEFT_TO_RIGHT); //+
    void setObject(Object obj, QString str, int property); //+
    void delObject(int x, int y, QString searchType);//+
    int howNeighbors(Object obj); //+
    QVector<Object> getCurrentConfig(QString searhType); //+
};

#endif // CONFIGURATION_H
