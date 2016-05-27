#include "scene.h"

Scene::Scene(QGLWidget *parent){
    setMinimumSize(500,500);
    sizeObject = 10;
    xView = 0.0;
    yView = 0.0;
    start = false;
    addMode = setMode = false;
    setMouseTracking(true);
    mainConfig.setSizeMap(36);

    //Начальная конфигурация HELLO!
    Object obj1(-9,2,G_C_PR_L_1); mainConfig.addObject(obj1);
    Object obj2(-9,1,G_C_PR_L_1); mainConfig.addObject(obj2);
    Object obj3(-9,0,G_C_PR_L_1); mainConfig.addObject(obj3);
    Object obj4(-9,-1,G_C_PR_L_1); mainConfig.addObject(obj4);
    Object obj5(-9,-2,G_C_PR_L_1); mainConfig.addObject(obj5);
    Object obj6(-8,0,G_C_PR_L_1); mainConfig.addObject(obj6);
    Object obj7(-7,2,G_C_PR_L_1); mainConfig.addObject(obj7);
    Object obj8(-7,1,G_C_PR_L_1); mainConfig.addObject(obj8);
    Object obj9(-7,0,G_C_PR_L_1); mainConfig.addObject(obj9);
    Object obj10(-7,-1,G_C_PR_L_1); mainConfig.addObject(obj10);
    Object obj11(-7,-2,G_C_PR_L_1); mainConfig.addObject(obj11);

    Object obj12(-5,2,G_C_PR_L_1); mainConfig.addObject(obj12);
    Object obj13(-5,1,G_C_PR_L_1); mainConfig.addObject(obj13);
    Object obj14(-5,0,G_C_PR_L_1); mainConfig.addObject(obj14);
    Object obj15(-5,-1,G_C_PR_L_1); mainConfig.addObject(obj15);
    Object obj16(-5,-2,G_C_PR_L_1); mainConfig.addObject(obj16);
    Object obj17(-4,2,G_C_PR_L_1); mainConfig.addObject(obj17);
    Object obj18(-4,0,G_C_PR_L_1); mainConfig.addObject(obj18);
    Object obj19(-4,-2,G_C_PR_L_1); mainConfig.addObject(obj19);
    Object obj20(-3,2,G_C_PR_L_1); mainConfig.addObject(obj20);
    Object obj21(-3,0,G_C_PR_L_1); mainConfig.addObject(obj21);
    Object obj22(-3,-2,G_C_PR_L_1); mainConfig.addObject(obj22);

    Object obj23(-1,2,G_C_PR_L_1); mainConfig.addObject(obj23);
    Object obj24(-1,1,G_C_PR_L_1); mainConfig.addObject(obj24);
    Object obj25(-1,0,G_C_PR_L_1); mainConfig.addObject(obj25);
    Object obj26(-1,-1,G_C_PR_L_1); mainConfig.addObject(obj26);
    Object obj27(-1,-2,G_C_PR_L_1); mainConfig.addObject(obj27);
    Object obj28(0,-2,G_C_PR_L_1); mainConfig.addObject(obj28);
    Object obj29(1,-2,G_C_PR_L_1); mainConfig.addObject(obj29);

    Object obj30(3,2,G_C_PR_L_1); mainConfig.addObject(obj30);
    Object obj31(3,1,G_C_PR_L_1); mainConfig.addObject(obj31);
    Object obj32(3,0,G_C_PR_L_1); mainConfig.addObject(obj32);
    Object obj33(3,-1,G_C_PR_L_1); mainConfig.addObject(obj33);
    Object obj34(3,-2,G_C_PR_L_1); mainConfig.addObject(obj34);
    Object obj35(4,-2,G_C_PR_L_1); mainConfig.addObject(obj35);
    Object obj36(5,-2,G_C_PR_L_1); mainConfig.addObject(obj36);

    Object obj37(7,2,G_C_PR_L_1); mainConfig.addObject(obj37);
    Object obj38(7,1,G_C_PR_L_1); mainConfig.addObject(obj38);
    Object obj39(7,0,G_C_PR_L_1); mainConfig.addObject(obj39);
    Object obj40(7,-1,G_C_PR_L_1); mainConfig.addObject(obj40);
    Object obj41(7,-2,G_C_PR_L_1); mainConfig.addObject(obj41);
    Object obj42(8,2,G_C_PR_L_1); mainConfig.addObject(obj42);
    Object obj43(8,-2,G_C_PR_L_1); mainConfig.addObject(obj43);
    Object obj44(9,2,G_C_PR_L_1); mainConfig.addObject(obj44);
    Object obj45(9,1,G_C_PR_L_1); mainConfig.addObject(obj45);
    Object obj46(9,0,G_C_PR_L_1); mainConfig.addObject(obj46);
    Object obj47(9,-1,G_C_PR_L_1); mainConfig.addObject(obj47);
    Object obj48(9,-2,G_C_PR_L_1); mainConfig.addObject(obj48);

    Object obj49(11,2,G_C_PR_L_1); mainConfig.addObject(obj49);
    Object obj50(11,1,G_C_PR_L_1); mainConfig.addObject(obj50);
    Object obj51(11,0,G_C_PR_L_1); mainConfig.addObject(obj51);

    Object obj52(11,-2,G_C_PR_L_1); mainConfig.addObject(obj52);

    QTimer *timer = new QTimer(this);
    timer->setInterval(42);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();

}

void Scene::initializeGL(){
    glClearColor(0.0f,0.0f,0.0f, 0.0f);
    glEnable(GL_TEXTURE_2D);
    glShadeModel( GL_SMOOTH );
    glClearDepth( 1.0f );
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}


void Scene::resizeGL(GLint width, GLint height){
    if( height == 0)
        height = 1;

    wWidth = width;
    wHeight = height;
    glViewport( 0, 0, width, height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-width/2,width/2,-height/2,height/2);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}


void Scene::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(xView,yView,0.0);
    glColor3f(redColorMap,greenColorMap,blueColorMap);




    //DrawMap
    drawMap();

    //Прорисовка поля
    //drawConfig(mainConfig,G_C_CONFIG_MAP);
    //Прорисовка живых клеток
    drawConfig(mainConfig,G_C_CONFIG_LIFE);
    drawConfig(mainConfig,G_C_CONFIG_MAP);

    if(start == true)
        mainConfig.nextConfig();
}


void Scene::viewUp(){
    yView-=50;
}
void Scene::viewDown(){
    yView+=50;
}
void Scene::viewRight(){
    xView-=50;
}
void Scene::viewLeft(){
    xView+=50;
}

void Scene::defaultView(){
    xView = yView = 0.0;
}

void Scene::drawMap(){
    float size = sqrt(mainConfig.getSizeMap());

    //DrawMap
    for(int i(0); i<=size*size; ++i) {
        glBegin(GL_LINES);
        glVertex2i(-size*size*(sizeObject/2)+i*sizeObject ,size*size*(sizeObject/2));
        glVertex2i(-size*size*(sizeObject/2)+i*sizeObject ,-size*size*(sizeObject/2));
        glEnd();

        glBegin(GL_LINES);
        glVertex2i(-size*size*(sizeObject/2) ,size*size*(sizeObject/2)-i*sizeObject);
        glVertex2i(size*size*(sizeObject/2),size*size*(sizeObject/2)-i*sizeObject);
        glEnd();
    }
}

void Scene::drawConfig(Configuration config, QString option){

    if(addMode==true)
    {
        if(xPos<((config.getSizeMap())/2)*sizeObject
                && xPos>((config.getSizeMap())/-2)*sizeObject
                && yPos>((config.getSizeMap())/-2)*sizeObject
                && yPos<((config.getSizeMap())/2)*sizeObject
                )
        {
            setMode = true;


            if(xPos > 0 && yPos>0)
            {
                newXPos =xPos - (xPos%10);
                newYPos =yPos + (10-(yPos%10));
            }
            if(xPos < 0 && yPos>0)
            {
                newXPos =xPos - (10+(xPos%10));
                newYPos =yPos + (10-(yPos%10));
            }
            if(xPos < 0 && yPos<0)
            {
                newXPos =xPos - (10 + xPos%10);
                newYPos =yPos - (yPos%10);
            }
            if(xPos > 0 && yPos<0)
            {
                newXPos =xPos - (xPos%10);
                newYPos =yPos - (yPos%10);
            }

            glColor3f(redColorObject,greenColorObject,blueColorObject);
            glBegin(GL_QUADS);
            glVertex2i(newXPos+xView,newYPos);
            glVertex2i(newXPos+sizeObject+xView,newYPos);
            glVertex2i(newXPos+sizeObject+xView,newYPos-sizeObject);
            glVertex2i(newXPos+xView,newYPos-sizeObject);
            glEnd();
        }
        else
            setMode = false;

    }


    if(option == G_C_CONFIG_LIFE){
        for(unsigned int i(0); i<config.getSize(G_C_CONFIG_LEFT); ++i){
            if(config.getObject(i,G_C_CONFIG_LEFT).getProperty() == G_C_PR_L_1){
                glColor3f(redColorObject, greenColorObject, blueColorObject);
                glBegin(GL_QUADS);
                glVertex2i((config.getObject(i,G_C_CONFIG_LEFT).getPoint().x()-1)*sizeObject,(config.getObject(i,G_C_CONFIG_LEFT).getPoint().y())*sizeObject);
                glVertex2i((config.getObject(i,G_C_CONFIG_LEFT).getPoint().x()  )*sizeObject,(config.getObject(i,G_C_CONFIG_LEFT).getPoint().y())*sizeObject);
                glVertex2i((config.getObject(i,G_C_CONFIG_LEFT).getPoint().x()  )*sizeObject,(config.getObject(i,G_C_CONFIG_LEFT).getPoint().y()-1)*sizeObject);
                glVertex2i((config.getObject(i,G_C_CONFIG_LEFT).getPoint().x()-1)*sizeObject,(config.getObject(i,G_C_CONFIG_LEFT).getPoint().y()-1)*sizeObject);
                glEnd();
            }
        }
    }
    else{
        if(option == G_C_CONFIG_MAP){
            for(int i(config.getSize(G_C_CONFIG_RIGHT)-1); i>=0; i--){
                if(config.getObject(i, G_C_CONFIG_RIGHT).getProperty() == G_C_PR_NULL){
                    glColor3f(redColorMap-0.3,greenColorMap-0.3,blueColorMap-0.3);
                    glBegin(GL_QUADS);
                    glVertex2i((config.getObject(i, G_C_CONFIG_RIGHT).getPoint().x()-1)*sizeObject,(config.getObject(i, G_C_CONFIG_RIGHT).getPoint().y())*sizeObject);
                    glVertex2i((config.getObject(i, G_C_CONFIG_RIGHT).getPoint().x()  )*sizeObject,(config.getObject(i, G_C_CONFIG_RIGHT).getPoint().y())*sizeObject);
                    glVertex2i((config.getObject(i, G_C_CONFIG_RIGHT).getPoint().x()  )*sizeObject,(config.getObject(i, G_C_CONFIG_RIGHT).getPoint().y()-1)*sizeObject);
                    glVertex2i((config.getObject(i, G_C_CONFIG_RIGHT).getPoint().x()-1)*sizeObject,(config.getObject(i, G_C_CONFIG_RIGHT).getPoint().y()-1)*sizeObject);
                    glEnd();
                }
            }
        }
    }
}

void Scene::mapPlus(){
    if(mainConfig.getSizeMap() < 256)
        mainConfig.setSizeMap(pow((sqrt(mainConfig.getSizeMap()) + 1),2));
}

void Scene::mapMinus(){
    if(mainConfig.getSizeMap() > 15)
        mainConfig.setSizeMap(pow((sqrt(mainConfig.getSizeMap()) - 1),2));
}


void Scene::increaseSize(){
    if(sizeObject<40)
        sizeObject++;

}

void Scene::reduceSize(){
    if(sizeObject>2)
        sizeObject--;
}

void Scene::clearMap()
{
    mainConfig.deleteConfig();
}

void Scene::mouseMoveEvent(QMouseEvent *mve)
{
    xPos = mve->x() - 250;
    yPos = -mve->y() + 250 ;
}

void Scene::mousePressEvent(QMouseEvent *mpe)
{
    if(setMode == true)
    {
        Object obj((newXPos/sizeObject)+1,(newYPos/sizeObject),G_C_PR_L_1);
        mainConfig.addObject(obj);
    }
}

void Scene::setTrueAddMode()
{
    sizeObject = 10;
    mainConfig.setSizeMap(36);
    defaultView();
    addMode = true;
}

void Scene::setFalseAddMode()
{
    addMode = false;
}

void Scene::setColorMap(GLfloat red, GLfloat green, GLfloat blue)
{
    this->redColorMap = red;
    this->greenColorMap = green;
    this->blueColorMap = blue;
}

void Scene::setColorObject(GLfloat red, GLfloat green, GLfloat blue)
{
    this->redColorObject = red;
    this->greenColorObject = green;
    this->blueColorObject = blue;
}


Scene::~Scene(){

}
