/************************************************************************************
 *类名:    myApplication  应用程序主页类                                                                                              *
 *功能:   显示其他程序                                                                                                                                  *
 *作者:   刘凯                                                                                                                                                   *
 *日期:   2020.12.12                                                                                                                                       *
 * ************************************************************************************/
#pragma once

#include <QWidget>
#include<QMessageBox>
#include<QGridLayout>
#include<QPushButton>
#include<QToolButton>
#include<QDebug>
#include<QTimerEvent>
#include<QVBoxLayout>
#include<QThread>
#include<QTimerEvent>
#include"coin/coinPage.h"
#include"soundplay.h"
#include"plant/flyObject.h"
#include"myMessageBox.h"
namespace Ui {
class myApplication;
}

class myApplication : public QWidget
{
    Q_OBJECT

public:
    explicit myApplication(QWidget *parent = 0);
    ~myApplication();
    void timerEvent(QTimerEvent *event);
public:
    void dealWithCoinGame(); //  处理金币游戏
    void   initBtnGroup();
    void  btnflush(int pos); // btn flush
signals:
    void  SigShowCheckPointPage();
    void   SigPlaySound(QString);
private slots:
    void on_ilanBtn_3_clicked();


  //  void  SlotChoiceBtnClicked();
    void on_backToMainPageBtn_clicked();

    void on_ilanBtn_clicked();


    void on_gameBtn_clicked();

    void on_audioBtn_clicked();

    void on_crackBtn_clicked();

    void on_messageBtn_clicked();

    void on_armBtn_clicked();

    void on_allBtn_clicked();

private:
    Ui::myApplication *ui;
    myMessageBox   *m_messageBox;
    soundPlay   *m_sound;
    coinPage*m_checkPoinPage;
    QVBoxLayout *m_layout;
     myPlant      *m_myfly;
     QToolButton  *m_btnGop[14];
     int  m_plantStartSendBullet;
     int  m_flashBtnBackground = -1;
    // QVector<QVector<int>>pointData;
};


