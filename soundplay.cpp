#include "soundplay.h"

soundPlay::soundPlay(QObject *parent) : QObject(parent)
  ,m_soundEffect(NULL)
  ,m_thread(new QThread())
{

  connect(m_thread,SIGNAL(finished()),m_thread,SLOT(deleteLater()));
  this->moveToThread(m_thread);
  m_thread->start();

}

soundPlay::~soundPlay()
{
    if(m_soundEffect->isPlaying())
    {
        m_soundEffect->stop();
        m_soundEffect->deleteLater();
    }
    if(m_thread)
    {
        delete m_thread;
        m_thread = NULL;
    }
}


void soundPlay::SlotPlayPromptone(QString str)
{

    if(!m_soundEffect)
    {
        m_soundEffect = new QSoundEffect;
    }
    m_soundEffect->setSource(QUrl::fromLocalFile(str));
    m_soundEffect->play();
}
