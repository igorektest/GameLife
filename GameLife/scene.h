#ifndef SCENE_H
#define SCENE_H

#include"object.h"
#include"configuration.h"
//
#include <QGLWidget>
#include <GL/glu.h>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QString>

class Scene : public QGLWidget{
    Q_OBJECT

protected:
    void initializeGL();
    void resizeGL(GLint width, GLint height);
    void paintGL();
    void mouseMoveEvent(QMouseEvent* mve);
    void mousePressEvent(QMouseEvent* mpe);

public:
    Scene(QGLWidget *parent = 0);
    void viewUp();
    void viewDown();
    void viewLeft();
    void viewRight();
    void defaultView();
    void startGame(){start = true;}
    void stopGame(){start = false;}
    void nextStep(){mainConfig.nextConfig();}
    void prevStep(){mainConfig.prevConfig();}
    uint howNULL(){return mainConfig.getSize(G_C_CONFIG_RIGHT);}
    void mapPlus();
    void mapMinus();
    void increaseSize();
    void reduceSize();
    void clearMap();
    void setTrueAddMode();
    void setFalseAddMode();
    void setColorMap(GLfloat red, GLfloat green, GLfloat blue);
    void setColorObject(GLfloat red, GLfloat green, GLfloat blue);
    int xPos;
    int yPos;
    ~Scene();

private:
    Configuration mainConfig;
    GLint wWidth;
    GLint wHeight;
    GLfloat xView;
    GLfloat yView;
    GLfloat redColorMap;
    GLfloat greenColorMap;
    GLfloat blueColorMap;
    GLfloat redColorObject;
    GLfloat greenColorObject;
    GLfloat blueColorObject;
    bool start;
    bool addMode;
    bool setMode;
    int newXPos;
    int newYPos;
    GLfloat sizeObject;
    void drawMap();
    void drawConfig(Configuration config, QString option);
};

#endif // SCENE_H
