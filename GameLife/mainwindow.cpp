#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent){
    nulls = 0;
    addMode = false;
    QLabel* lbl1 = new QLabel("Map Colors");
    QLabel* lbl2 = new QLabel("Object Colors");
    spinBox1 = new QSpinBox;
    spinBox2 = new QSpinBox;
    spinBox3 = new QSpinBox;
    spinBox4 = new QSpinBox;
    spinBox5 = new QSpinBox;
    spinBox6 = new QSpinBox;
    spinBox1->setMaximum(10); spinBox1->setMinimum(0); spinBox1->setValue(0);
    spinBox2->setMaximum(10); spinBox2->setMinimum(0);spinBox2->setValue(3);
    spinBox3->setMaximum(10); spinBox3->setMinimum(0);spinBox3->setValue(10);
    spinBox4->setMaximum(10); spinBox4->setMinimum(0);spinBox4->setValue(0);
    spinBox5->setMaximum(10); spinBox5->setMinimum(0);spinBox5->setValue(8);
    spinBox6->setMaximum(10); spinBox6->setMinimum(0);spinBox6->setValue(8);

    scene = new Scene;

    QHBoxLayout* layout1 = new QHBoxLayout;
    QVBoxLayout* layout2 = new QVBoxLayout;
    QHBoxLayout* layout3 = new QHBoxLayout;
    QVBoxLayout* layout4 = new QVBoxLayout;
    QHBoxLayout* layout5 = new QHBoxLayout;
    QHBoxLayout* layout6 = new QHBoxLayout;

    pbtn1 = new QPushButton("Start"); pbtn1->setFixedSize(40,25);
    pbtn2 = new QPushButton("Prev");  pbtn2->setFixedSize(40,25);
    pbtn3 = new QPushButton("Next");  pbtn3->setFixedSize(40,25);
    pbtn4 = new QPushButton("Stop");  pbtn4->setFixedSize(40,25); pbtn4->setEnabled(false);
    pbtn6 = new QPushButton("Map+");pbtn6->setFixedSize(40,25);
    pbtn7 = new QPushButton("Map-");pbtn7->setFixedSize(40,25);
    pbtn8 = new QPushButton("+");    pbtn8->setFixedSize(40,25);
    pbtn9 = new QPushButton("-");    pbtn9->setFixedSize(40,25);
    pbtn11 = new QPushButton("Set");    pbtn11->setFixedSize(40,25);
    pbtn12 = new QPushButton("View");    pbtn12->setFixedSize(40,25); pbtn12->setEnabled(false);
    pbtn10 = new QPushButton("Clear");  pbtn10->setFixedSize(40,25);

    layout3->addWidget(pbtn1);
    layout3->addWidget(pbtn2);
    layout3->addWidget(pbtn3);
    layout3->addWidget(pbtn4);
    layout3->addWidget(pbtn6);
    layout3->addWidget(pbtn7);
    layout3->addWidget(pbtn9);
    layout3->addWidget(pbtn8);
    layout3->addWidget(pbtn11);
    layout3->addWidget(pbtn12);
    layout3->addWidget(pbtn10);
    layout3->addStretch();
    layout5->addWidget(lbl1);
    layout5->addWidget(spinBox1);
    layout5->addWidget(spinBox2);
    layout5->addWidget(spinBox3);
    layout6->addWidget(lbl2);
    layout6->addWidget(spinBox4);
    layout6->addWidget(spinBox5);
    layout6->addWidget(spinBox6);
    layout4->addLayout(layout5);
    layout4->addLayout(layout6);
    layout2->addWidget(scene);
    layout2->addLayout(layout3);
    layout1->addLayout(layout2);
    layout1->addLayout(layout4);

    setLayout(layout1);

    connect(pbtn1,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(pbtn3,SIGNAL(clicked()),this,SLOT(nextStep()));
    connect(pbtn4,SIGNAL(clicked()),this,SLOT(stopGame()));
    connect(pbtn6,SIGNAL(clicked()),this,SLOT(mapPlus()));
    connect(pbtn7,SIGNAL(clicked()),this,SLOT(mapMinus()));
    connect(pbtn8,SIGNAL(clicked()),this,SLOT(increaseSize()));
    connect(pbtn9,SIGNAL(clicked()),this,SLOT(reduceSize()));
    connect(pbtn10,SIGNAL(clicked()),this,SLOT(clearMap()));
    connect(pbtn11,SIGNAL(clicked()),this,SLOT(setTrueAddMode()));
    connect(pbtn12,SIGNAL(clicked()),this,SLOT(setFalseAddMode()));
    connect(pbtn2, SIGNAL(clicked()),this, SLOT(prevStep()));

    QTimer *timer = new QTimer(this);
    timer->setInterval(42);
    connect(timer, SIGNAL(timeout()), this, SLOT(view()));
    timer->start();
}

void MainWindow::keyPressEvent(QKeyEvent *pe){
    switch (pe->key()){
    case Qt::Key_Escape: close(); break;
    case Qt::Key_W: if(!addMode)scene->viewUp(); break;
    case Qt::Key_A: if(!addMode)scene->viewLeft(); break;
    case Qt::Key_S: if(!addMode)scene->viewDown(); break;
    case Qt::Key_D: if(!addMode)scene->viewRight(); break;
    case Qt::Key_C: if(!addMode)scene->defaultView(); break;
    }
}


void MainWindow::startGame(){
    pbtn2->setEnabled(false);
    pbtn3->setEnabled(false);
    pbtn4->setEnabled(true);
    pbtn1->setEnabled(false);
    pbtn11->setEnabled(false);
    pbtn10->setEnabled(false);
    pbtn6->setEnabled(false);
    pbtn7->setEnabled(false);
    scene->startGame();
}

void MainWindow::stopGame(){
    pbtn2->setEnabled(true);
    pbtn3->setEnabled(true);
    pbtn4->setEnabled(false);
    pbtn1->setEnabled(true);
    pbtn11->setEnabled(true);
    pbtn10->setEnabled(true);
    pbtn6->setEnabled(true);
    pbtn7->setEnabled(true);
    scene->stopGame();
}



void MainWindow::nextStep(){
    scene->nextStep();
}

void MainWindow::prevStep(){
    scene->prevStep();
}


void MainWindow::mapPlus(){
    scene->mapPlus();
}

void MainWindow::mapMinus(){
    scene->mapMinus();
}

void MainWindow::increaseSize(){
    scene->increaseSize();
}

void MainWindow::reduceSize(){
    scene->reduceSize();
}

void MainWindow::clearMap(){
    scene->clearMap();
}
void MainWindow::view()
{
    float rMap = (float)(spinBox1->value())/10;
    float gMap = (float)(spinBox2->value())/10;
    float bMap = (float)(spinBox3->value())/10;
    float rObj = (float)(spinBox4->value())/10;
    float gObj = (float)(spinBox5->value())/10;
    float bObj = (float)(spinBox6->value())/10;
    setColorMap(rMap,gMap,bMap);
    setColorObject(rObj,gObj,bObj);
}

void MainWindow::setTrueAddMode()
{
    addMode = true;
    pbtn1->setEnabled(false);
    pbtn2->setEnabled(false);
    pbtn3->setEnabled(false);
    pbtn4->setEnabled(false);
    pbtn6->setEnabled(false);
    pbtn7->setEnabled(false);
    pbtn8->setEnabled(false);
    pbtn9->setEnabled(false);
    pbtn11->setEnabled(false);
    pbtn12->setEnabled(true);
    scene->setTrueAddMode();
}

void MainWindow::setFalseAddMode()
{
    addMode = false;
    pbtn1->setEnabled(true);
    pbtn2->setEnabled(true);
    pbtn3->setEnabled(true);
    pbtn4->setEnabled(false);
    pbtn6->setEnabled(true);
    pbtn7->setEnabled(true);
    pbtn8->setEnabled(true);
    pbtn9->setEnabled(true);
    pbtn11->setEnabled(true);
    pbtn12->setEnabled(false);
    scene->setFalseAddMode();
}


void MainWindow::setColorMap(float red, float green, float blue)
{
    scene->setColorMap(red, green, blue);
}

void MainWindow::setColorObject(float red, float green, float blue)
{
    scene->setColorObject(red,green,blue);
}

void MainWindow::updateProperties()
{

}

MainWindow::~MainWindow(){

}
