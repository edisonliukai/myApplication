#pragma once
#include <QObject>
#include<QToolButton>
#include<QTimer>
#include<QDebug>
const int ALL_CHECK_POINT_NUM =16;
class coinBtn:public QToolButton
{
   public:
    coinBtn(QWidget*parent = nullptr);
    coinBtn(QString imgPath,bool flag);
public:
    void   coinFlagChanged();    //  硬币状态改变
    void  mousePressEvent(QMouseEvent*event);
    void  setX(int x);
    void  setY(int y);
  public:
    QTimer*m_timer1;                         //  正到反
    QTimer*m_timer2;                        //    反倒正
    bool    m_ifAmotion = false;       //  动画在
    bool    m_ifWin = false;                //  是否胜利
    bool    m_flag ;                         //     正面为0反面为1
    int       max = 8;
    int    min =1;
    int     m_x = 0;                               //  银币横坐标
    int     m_y = 0;                              //    银币纵坐标

};
