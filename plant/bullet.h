#pragma once

#include<QDebug>
#include <QObject>
#include <QWidget>
#include<QLabel>
enum  BULLET_TYPE    //  子弹类型，不同子弹的图片和伤害各不同哦
{
    NORMAL = 0,        //   普通子弹
    MEDDILE_HURT, //  中等伤害
    HIGHT_HURT       //   高伤害
};
class bullet : public QLabel  // 子弹父类抽象类
{
    Q_OBJECT
public:
    explicit bullet(QWidget*parent = nullptr);
public:
     virtual void bulletCauseHurt() = 0;  // 子弹造成伤害
     virtual void dealwithBulletMove() = 0; //  处理子弹移动
     virtual void  dealwithBulletImgAndHurt(BULLET_TYPE type);
   virtual  void  setBulletParent(QWidget*w);

      QString   m_backgroundImg; //  子弹样式图片
      BULLET_TYPE  m_currentType;  // 当前子弹类型
     double     m_x;                                    //  子弹横坐标
     double     m_y;                                    //   子弹纵坐标
      int  m_damage;                                //  子弹当前伤害
signals:

public slots:

};

class  bulletFromMyPlant:public bullet  // 主角飞机发出的子弹类
{
public:
    bulletFromMyPlant(BULLET_TYPE type);

    void bulletCauseHurt();
    void dealwithBulletMove();

     //void  dealwithBulletImgAndHurt(BULLET_TYPE type);
    //void setBulletParent(QWidget*w);
};

class   bulletFactory                                   //  子弹工厂负责创建子弹
{
   public:
    bulletFactory();
bullet*createBullet(BULLET_TYPE type) ;
};
