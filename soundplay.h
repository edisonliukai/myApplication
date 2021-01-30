/**********************************************************************************
 *类名:    soundPlay                                                                                                                                   *
 *功能:   播放整个工程中的背景音乐                                                                                                    *
 *作者:   刘凯                                                                                                                                               *
 *日期:   2020.12.12                                                                                                                                  *
 * *********************************************************************************/
#pragma once

#include <QObject>
#include<QSoundEffect>
#include<QThread>
#include<QUrl>
#include<QDebug>
#include<QThread>
class soundPlay : public QObject
{
    Q_OBJECT
public:
    explicit soundPlay(QObject *parent = nullptr);
       ~soundPlay();
signals:

public slots:
    void SlotPlayPromptone(QString str);
private:
    QSoundEffect *m_soundEffect;
    QThread            *m_thread;
};


