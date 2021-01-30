#include "flyObject.h"

flyObject::flyObject()
{

}


myPlant::myPlant(QString imgPath):m_pParent(NULL)
    ,m_ifmousePress(false)
    ,m_backgroundPath(imgPath)
  ,m_bul(NULL)
{

    this->show();
    this->setFixedSize(60,60);
    this->setStyleSheet("border-image: url(:/image/gra_planeImg1.png);");
 // createBullet();
}

void myPlant::createBullet()
{
    qDebug()<<"createBullet";
    bulletFactory*fac = new bulletFactory();

    if(!m_bul)
    {
        m_bul = fac->createBullet(NORMAL);
    }

    m_bul->setBulletParent(m_pParent);

    m_bul->show();

    m_bul->dealwithBulletImgAndHurt(NORMAL);
}

void myPlant::dealwithFly()
{

}

void myPlant::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_ifmousePress = true;
        m_point  = event->globalPos()-frameGeometry().topLeft();
                event->accept();
    }
}

void myPlant::setLabelParent(QWidget *parent)
{
   m_pParent = parent;
   this->setParent(m_pParent);
}

void myPlant::moveBulletPos(int x, int y)
{
     this->move(x,y);
     m_bul->move(x+this->width()/2-m_bul->width()/2,y-m_bul->height()*3/4);
     m_bulleStartPosx = m_bul->x();
     m_bulletStartPoxy = m_bul->y();
}

void myPlant::sendBullet()
{
    qDebug()<<"sendBullet";
    int x = m_bul->x();
    int y = m_bul->y();
    y-=1;
    m_bul->move(x,y);

    if(y<0)
    {
        m_bul->move(m_bulleStartPosx,m_bulletStartPoxy);
    }
}

void  myPlant::mouseMoveEvent(QMouseEvent*event)
{
    if(!m_pParent)
    {
        return;
    }
    if(event->buttons() & Qt::LeftButton)
       {
           qDebug() << event->globalPos()- m_point;
           m_nMovePointX = (event->globalPos()- m_point).x();
           m_nMovePointY = (event->globalPos()- m_point).y();
           if(m_nMovePointX < 0 || m_nMovePointY < 0 || m_nMovePointY > m_pParent->rect().bottom() - this->rect().width() || m_nMovePointX > m_pParent->rect().right() - this->rect().width())
           {
               //防止移出顶部和底部
               if(m_nMovePointY > m_pParent->rect().bottom() - this->rect().width() || m_nMovePointY < 0)
               {
                   move((event->globalPos() - m_point).x(), this->geometry().y());
               }
               //防止移出左侧和右侧
               if(m_nMovePointX > m_pParent->rect().right() - this->rect().width() || m_nMovePointX < 0)
               {
                   move(this->geometry().x(),(event->globalPos() - m_point).y());
               }
               //防止移出左上角
               if(m_nMovePointX < 0 && m_nMovePointY < 0)
               {
                   move(0,0);
               }
               //防止移出右小角
               if(m_nMovePointY > m_pParent->rect().bottom() - this->rect().width() && m_nMovePointX > m_pParent->rect().right() - this->rect().width())
               {
                   move(m_pParent->rect().right() - this->rect().width(), m_pParent->rect().bottom() - this->rect().height());
               }
               //防止移出右上角
               if(m_nMovePointY < 0 && m_nMovePointX > m_pParent->rect().right() - this->rect().width())
               {
                   move(m_pParent->rect().right() - this->rect().width(),0);
               }
               //防止移出左上角
               if(m_nMovePointX < 0 && m_nMovePointY > m_pParent->rect().bottom() - this->rect().height())
               {
                   move(0,m_pParent->rect().bottom() - this->rect().height());
               }

           }
           else
           {
              //move(event->globalPos() - m_point);
              QPoint mov = event->globalPos() - m_point;
              int x = mov.x();
              int y = mov.y();
              moveBulletPos(x,y);
           }
       }
}
