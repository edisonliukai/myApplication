#include "bullet.h"

bullet::bullet(QWidget *parent) : QLabel(parent)
{

}
void bullet::setBulletParent(QWidget *w)
{
    qDebug()<<"setParent";
    this->setParent(w);
}

void bullet::dealwithBulletImgAndHurt(BULLET_TYPE type)
{
    if(m_currentType == NORMAL)
    {
        m_damage = 1;
        m_backgroundImg = "";
    }
    else if(m_currentType == MEDDILE_HURT)
    {
        m_damage = 2;
        m_backgroundImg = "";
    }
    else if(m_currentType == HIGHT_HURT)
    {
        m_damage = 3;
        m_backgroundImg = "";
    }
}
//********************************//
bulletFromMyPlant::bulletFromMyPlant(BULLET_TYPE type)
{

    this->m_currentType = type;
    this->resize(40,40);
    this->show();
  //  this->setStyleSheet("background-color:red");
     this->setStyleSheet("border-image: url(:/image/bomb1.png);");
}


void bulletFromMyPlant::bulletCauseHurt()
{

}

void  bulletFromMyPlant::dealwithBulletMove()
{

}


//*******************************//
bulletFactory::bulletFactory()
{

}

bullet*bulletFactory::createBullet(BULLET_TYPE type)
{
    return  new  bulletFromMyPlant(type);
}
