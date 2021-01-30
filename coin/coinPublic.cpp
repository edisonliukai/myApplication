#include "coinPublic.h"
#include<QPixmap>
coinBtn::coinBtn(QWidget *parent):QToolButton(parent)
  ,m_timer1(NULL)
  ,m_timer2(NULL)
{

}

void coinBtn::mousePressEvent(QMouseEvent *event)
{
    if(m_ifAmotion)
    {
        return;
    }
    return QToolButton::mousePressEvent(event);
}

void coinBtn::setX(int x)
{
      m_x = x;
}

void coinBtn::setY(int y)
{
    m_y = y;
}
void coinBtn::coinFlagChanged()
{
    if(m_ifWin)
    {
        return;
    }
    m_ifAmotion = true;
    if(m_flag == 0)
    {
        m_flag  = 1;
        m_timer1->start(30);
    }
    else
    {
        m_flag = 0;
        m_timer2->start(30);
    }
}
coinBtn::coinBtn(QString imgPath,bool flag):m_flag(flag)
{

    QPixmap pix;
    pix.load(imgPath);
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
    this->setStyleSheet("QToolButton{border:0px;}");
    this->setFixedSize(pix.width(), pix.height());
    //this->setStyleSheet("border-image: url(:/image/Coin0001.png);");
    m_timer1 = new QTimer(this);
    connect(m_timer1,&QTimer::timeout,[=](){
        QString path;
        path = QString(":/image/Coin000%1.png").arg(this->min++);

        if (this->min > this->max)
        {
            this->min = 1;
            m_timer1->stop();
            this->m_ifAmotion = false;
            m_flag = 1;
        }

        QPixmap pixMap;
        bool ret = pixMap.load(path);
        if (!ret)
        {
            qDebug() <<"timer1 加载图片失败";
            return;
        }

        this->setIcon(pixMap);
        this->setIconSize(QSize(pixMap.width(), pixMap.height()));
        this->setStyleSheet("QToolButton{border:0px;}");
        this->setFixedSize(pixMap.width(), pixMap.height());
    });

    m_timer2 = new QTimer(this);
    connect(m_timer2,&QTimer::timeout,[=](){
        QString path;
        path = QString(":/image/Coin000%1.png").arg(this->max--);

        if (this->min > this->max)
        {
            this->max = 8;
            m_timer2->stop();
            this->m_ifAmotion = false;
            m_flag = 0;
        }

        QPixmap pixMap;
        bool ret = pixMap.load(path);
        if (!ret)
        {
            qDebug() <<"timer1 加载图片失败";
            return;
        }

        this->setIcon(pixMap);
        this->setIconSize(QSize(pixMap.width(), pixMap.height()));
        this->setStyleSheet("QToolButton{border:0px;}");
        this->setFixedSize(pixMap.width(), pixMap.height());
    });
}
