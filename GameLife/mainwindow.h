#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QWidget>
#include<QBoxLayout>
#include"scene.h"
#include<QPushButton>
#include<QKeyEvent>
#include<QTextEdit>
#include<QSpinBox>
#include<QTimer>
#include<QLabel>

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startGame();
    void stopGame();
    void nextStep();
    void prevStep();
    void mapPlus();
    void mapMinus();
    void increaseSize();
    void reduceSize();
    void clearMap();
    void view();
    void setTrueAddMode();
    void setFalseAddMode();
    void setColorMap(float, float, float);
    void setColorObject(float, float, float);
    void updateProperties();

protected:
    void keyPressEvent(QKeyEvent* pe);

private:
    Scene* scene;
    int nulls;
    bool addMode;
    QPushButton* pbtn1;
    QPushButton* pbtn2;
    QPushButton* pbtn3;
    QPushButton* pbtn4;
    QPushButton* pbtn6;
    QPushButton* pbtn7;
    QPushButton* pbtn8;
    QPushButton* pbtn9;
    QPushButton* pbtn10;
    QPushButton* pbtn11;
    QPushButton* pbtn12;
    QSpinBox* spinBox1;
    QSpinBox* spinBox2;
    QSpinBox* spinBox3;
    QSpinBox* spinBox4;
    QSpinBox* spinBox5;
    QSpinBox* spinBox6;
};

#endif // MAINWINDOW_H
