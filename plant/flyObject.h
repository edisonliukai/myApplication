#pragma once

#include <QObject>
#include<QLabel>
#include<QWidget>
#include<QPixmap>
#include<QMouseEvent>
#include<QPoint>
#include<QDebug>
#include"bullet.h"
class flyObject:public QLabel
{
public:
    flyObject();
    virtual void dealwithFly() = 0;
};

//  飞机自己
class  myPlant:public  flyObject
{
   public:
    myPlant(QString imgPath);
    void createBullet();
    void dealwithFly();
    void mousePressEvent(QMouseEvent*event);
    void mouseMoveEvent(QMouseEvent*event);
    void setLabelParent(QWidget     *parent);
    void  moveBulletPos(int x,int y);   //   移动位置
    void  sendBullet();//  发射子弹
   private:
    QWidget     *m_pParent;
    bullet*m_bul ;
     bool          m_ifmousePress;
     QPoint    m_point;
     QString  m_backgroundPath;
    int  m_nMovePointX = 0;
    int  m_nMovePointY = 0;
    int  m_bulleStartPosx;
    int  m_bulletStartPoxy;
};

