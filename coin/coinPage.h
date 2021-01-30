#pragma once

#include <QObject>
#include <QWidget>
#include<QTimer>
#include"coinPublic.h"
#include<QGridLayout>
#include<QMap>
#include<QVector>
#include<QLabel>
class coinPage : public QWidget
{
    Q_OBJECT
public:
    explicit  coinPage(QWidget *parent = nullptr);
                    coinPage(QWidget *parent = nullptr,int index = 0);
    void       initData();
    void       setCheckPointData();
    void      judeifWin();
signals:
  void          SigBackToGameChoicePage();
  void          SigCoinAroundChangedStatus(int pos);
  void          SigPlayMusic(QString);
public slots:
 private:
       int   m_currentCheckPoint;   // 当前关卡
       QGridLayout   *m_layout;
       QLabel              *m_label;
       coinBtn*m_btnGroup[ALL_CHECK_POINT_NUM];
      QMap<int,QVector<QVector<int>>>m_data;
};
