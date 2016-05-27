#include "configuration.h"

Configuration::Configuration(){    
    generation = 0;
    sizeMap = 100;
}

void Configuration::addObject(Object obj){
    bool err = 0;
    if (obj.getProperty() == G_C_PR_NONE || G_C_PR_NULL)
        err = 1;
    else{
        for(int i(0);i<configNULL.size();i++){
            if(configNULL[i].getPoint().x() == obj.getPoint().x()
                    && configNULL[i].getPoint().y() == obj.getPoint().y())
                configNULL.remove(i);
        }
    }
    if(0 == err){
        if(obj.getProperty() == G_C_PR_L_1){
            configLIFE.push_front(obj);
            //Создаем карту на которой находится конфигурация
            createMap(obj);
        }
    }
}

void Configuration::delObject(Object obj){
    if(obj.getProperty() != G_C_PR_NULL && obj.getProperty() != G_C_PR_NONE){
        delObject(obj.getPoint().x(),obj.getPoint().y(),G_C_CONFIG_LEFT); //Закоментируй и проверь оптимизацию)))

        //Найти все живие клетки в радиусе  1 клетки

        QVector<Object> createdMap; //объекты для которых следует обновить карту
        QVector<Object> createdMap2; //объекты у которых нет соседей
        Object _obj;

        _obj = getObject(obj,G_C_UP_LEFT,G_C_CONFIG_LEFT_TO_RIGHT);
        if(_obj.getProperty() == G_C_PR_L_1) {createdMap.push_back(_obj);}
        if(_obj.getProperty() != G_C_PR_L_1) { createdMap2.push_back(_obj);}

        _obj = getObject(obj,G_C_UP,G_C_CONFIG_LEFT_TO_RIGHT);
        if(_obj.getProperty() == G_C_PR_L_1) {createdMap.push_back(_obj);}
        if(_obj.getProperty() != G_C_PR_L_1) { createdMap2.push_back(_obj);}

        _obj = getObject(obj,G_C_UP_RIGHT,G_C_CONFIG_LEFT_TO_RIGHT);
        if(_obj.getProperty() == G_C_PR_L_1) {createdMap.push_back(_obj);}
        if(_obj.getProperty() != G_C_PR_L_1) { createdMap2.push_back(_obj);}

        _obj = getObject(obj,G_C_RIGHT,G_C_CONFIG_LEFT_TO_RIGHT);
        if(_obj.getProperty() == G_C_PR_L_1) {createdMap.push_back(_obj);}
        if(_obj.getProperty() != G_C_PR_L_1) { createdMap2.push_back(_obj);}

        _obj = getObject(obj,G_C_DOWN_RIGHT,G_C_CONFIG_LEFT_TO_RIGHT);
        if(_obj.getProperty() == G_C_PR_L_1) {createdMap.push_back(_obj);}
        if(_obj.getProperty() != G_C_PR_L_1) { createdMap2.push_back(_obj);}

        _obj = getObject(obj,G_C_DOWN,G_C_CONFIG_LEFT_TO_RIGHT);
        if(_obj.getProperty() == G_C_PR_L_1) {createdMap.push_back(_obj);}
        if(_obj.getProperty() != G_C_PR_L_1) { createdMap2.push_back(_obj);}

        _obj = getObject(obj,G_C_DOWN_LEFT,G_C_CONFIG_LEFT_TO_RIGHT);
        if(_obj.getProperty() == G_C_PR_L_1) {createdMap.push_back(_obj);}
        if(_obj.getProperty() != G_C_PR_L_1) { createdMap2.push_back(_obj);}

        _obj = getObject(obj,G_C_LEFT,G_C_CONFIG_LEFT_TO_RIGHT);
        if(_obj.getProperty() == G_C_PR_L_1) {createdMap.push_back(_obj);}
        if(_obj.getProperty() != G_C_PR_L_1) { createdMap2.push_back(_obj);}

        //Обновить клетки, которым необходимо применить отрисовку карты
        for(int i(0);i<createdMap.size();++i)
            createMap(createdMap[i]);

        //Удалить все клетки у которых нет соседей
        for(int i(0); i<createdMap2.size();++i){
            if(getObject(createdMap2[i],G_C_UP_LEFT).getProperty() != G_C_PR_L_1
                    && getObject(createdMap2[i],G_C_UP).getProperty() != G_C_PR_L_1
                    && getObject(createdMap2[i],G_C_UP_RIGHT).getProperty() != G_C_PR_L_1
                    && getObject(createdMap2[i],G_C_RIGHT).getProperty() != G_C_PR_L_1
                    && getObject(createdMap2[i],G_C_DOWN_RIGHT).getProperty() != G_C_PR_L_1
                    && getObject(createdMap2[i],G_C_DOWN).getProperty() != G_C_PR_L_1
                    && getObject(createdMap2[i],G_C_DOWN_LEFT).getProperty() != G_C_PR_L_1
                    && getObject(createdMap2[i],G_C_LEFT).getProperty() != G_C_PR_L_1)
                delObject(createdMap2[i].getPoint().x(),createdMap2[i].getPoint().y(),G_C_CONFIG_RIGHT);
        }
    }
}

void Configuration::delObject(int x, int y, QString searchType){
    if(searchType == G_C_CONFIG_LEFT_TO_RIGHT){
        for(int i(0); i<configLIFE.size(); ++i){
            if(configLIFE[i].getPoint().x() == x && configLIFE[i].getPoint().y() == y)
                configLIFE.remove(i);
        }

        for(int i(0); i<configNULL.size(); ++i){
            if(configNULL[i].getPoint().x() == x && configNULL[i].getPoint().y() == y)
                configNULL.remove(i);
        }
    }
    else{
        if(searchType == G_C_CONFIG_LEFT){
            for(int i(0); i<configLIFE.size(); ++i){
                if(configLIFE[i].getPoint().x() == x && configLIFE[i].getPoint().y() == y)
                    configLIFE.remove(i);
            }
        }
        else{
            if(searchType == G_C_CONFIG_RIGHT){
                for(int i(0); i<configNULL.size(); i++){
                    if(configNULL[i].getProperty() != G_C_PR_NULL) break;
                    if(configNULL[i].getPoint().x() == x && configNULL[i].getPoint().y() == y)
                        configNULL.remove(i);
                }
            }
        }
    }
}

void Configuration::createMap(Object obj){
    if(getObject(obj,G_C_UP_LEFT).getProperty() == G_C_PR_NONE) setObject(obj,G_C_UP_LEFT,G_C_PR_NULL);
    if(getObject(obj,G_C_UP).getProperty() == G_C_PR_NONE) setObject(obj,G_C_UP,G_C_PR_NULL);
    if(getObject(obj,G_C_UP_RIGHT).getProperty() == G_C_PR_NONE) setObject(obj,G_C_UP_RIGHT,G_C_PR_NULL);
    if(getObject(obj,G_C_RIGHT).getProperty() == G_C_PR_NONE) setObject(obj,G_C_RIGHT,G_C_PR_NULL);
    if(getObject(obj,G_C_DOWN_RIGHT).getProperty() == G_C_PR_NONE) setObject(obj,G_C_DOWN_RIGHT,G_C_PR_NULL);
    if(getObject(obj,G_C_DOWN).getProperty() == G_C_PR_NONE) setObject(obj,G_C_DOWN,G_C_PR_NULL);
    if(getObject(obj,G_C_DOWN_LEFT).getProperty() == G_C_PR_NONE) setObject(obj,G_C_DOWN_LEFT,G_C_PR_NULL);
    if(getObject(obj,G_C_LEFT).getProperty() == G_C_PR_NONE) setObject(obj,G_C_LEFT,G_C_PR_NULL);
}

void Configuration::setObject(Object obj, QString str, int property){
    int x = obj.getPoint().x();
    int y = obj.getPoint().y();

    if(str == G_C_UP_LEFT)   { x--; y++;} else
        if(str == G_C_UP)        {      y++;} else
            if(str == G_C_UP_RIGHT)  { x++; y++;} else
                if(str == G_C_RIGHT)     { x++;     } else
                    if(str == G_C_DOWN_RIGHT){ x++; y--;} else
                        if(str == G_C_DOWN)      {      y--;} else
                            if(str == G_C_DOWN_LEFT) { x--; y--;} else
                                if(str == G_C_LEFT)      { x--;     }

    if(property == G_C_PR_L_1){
        Object newObj(x,y,property);
        configLIFE.push_back(newObj);
    }

    if(property == G_C_PR_NULL){
        Object newObj(x,y,property);
        configNULL.push_back(newObj);
    }

}

Object Configuration::getObject(Object obj, QString str, QString searchType){
    Object returnedObj;

    int x = obj.getPoint().x();
    int y = obj.getPoint().y();

    if(str == G_C_UP_LEFT)   { x--; y++;} else
        if(str == G_C_UP)        {      y++;} else
            if(str == G_C_UP_RIGHT)  { x++; y++;} else
                if(str == G_C_RIGHT)     { x++;     } else
                    if(str == G_C_DOWN_RIGHT){ x++; y--;} else
                        if(str == G_C_DOWN)      {      y--;} else
                            if(str == G_C_DOWN_LEFT) { x--; y--;} else
                                if(str == G_C_LEFT)      { x--;     }

    if(searchType == G_C_CONFIG_LEFT_TO_RIGHT){
        for(int i(0);i<configLIFE.size();++i){
            if(configLIFE[i].getPoint().x() == x && configLIFE[i].getPoint().y() == y){
                returnedObj.setGeneration(configLIFE[i].getGeneration());
                returnedObj.setPoint(configLIFE[i].getPoint());
                returnedObj.setProperty(configLIFE[i].getProperty());
                break;
            }
        }

        for(int i(0);i<configNULL.size();++i){
            if(configNULL[i].getPoint().x() == x && configNULL[i].getPoint().y() == y){
                returnedObj.setGeneration(configNULL[i].getGeneration());
                returnedObj.setPoint(configNULL[i].getPoint());
                returnedObj.setProperty(configNULL[i].getProperty());
                break;
            }
        }
    }
    else{
        if(searchType == G_C_CONFIG_LEFT){
            for(int i(0);i<configLIFE.size();++i){
                if(configLIFE[i].getPoint().x() == x && configLIFE[i].getPoint().y() == y){
                    returnedObj.setGeneration(configLIFE[i].getGeneration());
                    returnedObj.setPoint(configLIFE[i].getPoint());
                    returnedObj.setProperty(configLIFE[i].getProperty());
                    break;
                }
            }
        }
        else{
            if(searchType == G_C_CONFIG_RIGHT){
                for(int i(0); i<configNULL.size(); i++){
                    if(configNULL[i].getPoint().x() == x && configNULL[i].getPoint().y() == y){
                        returnedObj.setGeneration(configNULL[i].getGeneration());
                        returnedObj.setPoint(configNULL[i].getPoint());
                        returnedObj.setProperty(configNULL[i].getProperty());
                        break;
                    }
                }
            }
        }
    }
    return returnedObj;
}

Object Configuration::getObject(uint num, QString searchType){
    if(searchType == G_C_CONFIG_LEFT)
        return configLIFE[num];
    else if(searchType == G_C_CONFIG_RIGHT)
        return configNULL[num];
}

unsigned int Configuration::getSize(QString searchType){
    if(searchType == G_C_CONFIG_LEFT)
        return configLIFE.size();
    else
        return configNULL.size();
}


void Configuration::nextConfig(){
    History thisConfig;    thisConfig.configLIFE = this->configLIFE;
    thisConfig.configNULL = this->configNULL;
    history.push_back(thisConfig);
    QVector<Object> deletedObj;
    QVector<Object> newObj;
    Object obj;

    //Условие на рождение новой жизни
    for(int i(0); i<configNULL.size(); i++){
        if(howNeighbors(configNULL[i]) == 3){
            obj.setPoint(configNULL[i].getPoint());
            obj.setProperty(G_C_PR_L_1);
            newObj.push_back(obj);
        }
    }

    //Условие на смерть
    for(int i(0);i<configLIFE.size();i++){
        if(howNeighbors(configLIFE[i]) < 2 || howNeighbors(configLIFE[i]) > 3){
            deletedObj.push_back(configLIFE[i]);
        }
    }

    //Добавляем новые объекты
    for(int i(0); i<newObj.size();i++){
        addObject(newObj[i]);
    }

    //Удаляем объекты
    for(int i(0); i<deletedObj.size();i++){
        delObject(deletedObj[i]);
    }

    //Если один из объектов ушел за пределы карты
    for(int i(0); i<configLIFE.size();i++) {
        if(configLIFE[i].getPoint().x()>(sizeMap/2)
                || configLIFE[i].getPoint().x()<=-(sizeMap/2)
                || configLIFE[i].getPoint().y()>(sizeMap/2)
                || configLIFE[i].getPoint().y()<=-(sizeMap/2)){
            delObject(configLIFE[i]);
        }
    }
    generation++;
}

void Configuration::prevConfig()
{

    if(history.size())
    {
    History history1 = history[history.size()-1];
    configLIFE = history1.configLIFE;
    configNULL = history1.configNULL;
    history.remove(history.size()-1);
    }
}

int Configuration::howNeighbors(Object obj){
    int num = 0;

    //Узнаем количество соседей
    if(getObject(obj,G_C_UP_LEFT,G_C_CONFIG_LEFT_TO_RIGHT).getProperty() == G_C_PR_L_1){ num++;}
    if(getObject(obj,G_C_UP,G_C_CONFIG_LEFT_TO_RIGHT).getProperty() == G_C_PR_L_1){ num++;}
    if(getObject(obj,G_C_UP_RIGHT,G_C_CONFIG_LEFT_TO_RIGHT).getProperty() == G_C_PR_L_1){ num++;}
    if(getObject(obj,G_C_RIGHT,G_C_CONFIG_LEFT_TO_RIGHT).getProperty() == G_C_PR_L_1){ num++;}
    if(getObject(obj,G_C_DOWN_RIGHT,G_C_CONFIG_LEFT_TO_RIGHT).getProperty() == G_C_PR_L_1){ num++;}
    if(getObject(obj,G_C_DOWN,G_C_CONFIG_LEFT_TO_RIGHT).getProperty() == G_C_PR_L_1){ num++;}
    if(getObject(obj,G_C_DOWN_LEFT,G_C_CONFIG_LEFT_TO_RIGHT).getProperty() == G_C_PR_L_1){ num++;}
    if(getObject(obj,G_C_LEFT,G_C_CONFIG_LEFT_TO_RIGHT).getProperty() == G_C_PR_L_1){ num++;}

    return num;
}

void Configuration::deleteConfig(){
    configLIFE.clear();
    configNULL.clear();
    //    for(int i(0); configLIFE.size();i++){
    //        if(configLIFE[i].getProperty() == G_C_PR_NULL) break;
    //        delObject(configLIFE[i]);
    //    }
}

QVector<Object> Configuration::getCurrentConfig(QString searhType){
    if(searhType == G_C_CONFIG_LEFT)
        return configLIFE;
    else if(searhType == G_C_CONFIG_RIGHT)
        return configNULL;
}

void Configuration::setSizeMap(float size){
    this->sizeMap = size;
}

float Configuration::getSizeMap(){
    return sizeMap;
}

uint Configuration::getGeneration()
{
    return generation;
}
