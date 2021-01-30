#include "myApplication.h"
#include "ui_myApplication.h"
int  g_currentCheckPoint = 0;
myApplication::myApplication(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myApplication)
  ,m_messageBox(new myMessageBox(this))
  ,m_sound(new  soundPlay)
   ,m_checkPoinPage(NULL)
  ,m_layout(new QVBoxLayout())
  ,m_myfly(NULL)
  ,m_plantStartSendBullet(0)
{
    ui->setupUi(this);
    this->setWindowTitle("私人定制-豪华版");
    m_flashBtnBackground = startTimer(1000);
    ui->stackedWidget->setCurrentWidget(ui->appTypePage);
    ui->detialstackedWidget->setCurrentWidget(ui->allAppPage);
   //this->setFixedSize(380,540);
  //  m_myfly->setLabelParent(ui->plantPage);
   // m_myfly->createBullet();

    //m_myfly->move(ui->plantPage->width()/2-m_myfly->width()/2,ui->plantPage->height()-m_myfly->height());
    //m_myfly->move(100,100);
    //m_myfly->moveBulletPos(100,200);
    m_plantStartSendBullet = startTimer(2);
    ui->backToMainPageBtn->hide();
    ui->titleLabel->setText("程序列表");
    connect(ui->coinBtn,&QToolButton::clicked,[=](){
        ui->currentItemLabel->setText("当前程序:  翻金币");
        ui->stackedWidget->setCurrentWidget(ui->coinPage);
        ui->titleLabel->setText("关卡选择");
      if(!ui->backToMainPageBtn->isVisible())
      {
          ui->backToMainPageBtn->show();
       }

    });

    dealWithCoinGame();
   connect(this,SIGNAL(SigPlaySound(QString)),m_sound,SLOT(SlotPlayPromptone(QString)));

   //emit   SigPlaySound(":/image/game.m4a");
}

myApplication::~myApplication()
{
    delete ui;

}

void myApplication::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_plantStartSendBullet)
    {
        //m_myfly->sendBullet();
    }
    else if(event->timerId() == m_flashBtnBackground)
    {
        //int pos = rand()%10;
        //qDebug()<<"pos = "<<pos;
      // btnflush( pos);
    }
}

void myApplication::dealWithCoinGame()
{
    QGridLayout*gridLayout = new QGridLayout(ui->coinPage);
    for(int i = 0;i<5;++i)
    {
        for(int j = 0;j<4;++j)
        {

            QString text = QString::number(j+i*4+1);
            QToolButton*btn = new  QToolButton();
            btn->setObjectName(text);
            btn->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
            btn->setText(text);
            btn->setMinimumSize(40,40);
            //btn->setStyleSheet("QToolButton{background-color:green;color:red;border-radius:30px;}QToolButton:pressed{background-color:rgb(92, 53, 102);color:white}");
            connect(btn,&QToolButton::clicked,[=](){
            // emit SigPlaySound(":/image/BackButtonSound.wav");
                ui->titleLabel->setText("关卡选择");
                if(!m_checkPoinPage)
                {
                    g_currentCheckPoint = 1;
                    QString t = "当前关卡:" +   text;
                    ui->titleLabel->setText(t);
                    m_checkPoinPage = new  coinPage(this,j+i*4+1);

                     connect(m_checkPoinPage,SIGNAL(SigPlayMusic(QString)),m_sound,SLOT(SlotPlayPromptone(QString)));
                      qDebug()<<"full";
                   // ->setParent(ui->checkPointPage);

                    m_layout->addWidget(m_checkPoinPage);
                    m_layout->setContentsMargins(0,0,0,0);
                    ui->checkPointPage->setLayout(m_layout);
                    ui->stackedWidget->setCurrentWidget(ui->checkPointPage);
                    connect(m_checkPoinPage,&coinPage::SigBackToGameChoicePage,[=](){
                        g_currentCheckPoint = 0;
                         delete m_checkPoinPage;
                        m_checkPoinPage = NULL;
                        ui->stackedWidget->setCurrentWidget(ui->coinPage);
                    });
                }


            });
            gridLayout->setColumnStretch(j,1);
            gridLayout->addWidget(btn,i,j);
        }
        gridLayout->setRowStretch(i,1);
    }
    gridLayout->setContentsMargins(40,40,40,40);

    ui->coinPage->setLayout(gridLayout);
}

void myApplication::initBtnGroup()
{


}
void myApplication::btnflush(int pos)
{
    QString  qss = "background-color: rgb(245, 121, 0);";
    if(pos == 1)
    {
        ui->appBtn1->setStyleSheet(qss);
    }
    else if(pos ==3)
    {
        ui->appBtn3->setStyleSheet(qss);
    }
}

void myApplication::on_ilanBtn_3_clicked()
{
  //QMessageBox::information(this,"about","开发者:刘凯\n日期:2020.12.12\n");
   m_messageBox->resize(ui->gameChoicePage->width()/2,100);
    m_messageBox->show();
}



void myApplication::on_backToMainPageBtn_clicked()
{
    if(g_currentCheckPoint == 0)
    {
        ui->stackedWidget->setCurrentWidget(ui->appTypePage);
        ui->titleLabel->setText("程序选择");
        ui->currentItemLabel->setText("");
         ui->backToMainPageBtn->hide();
    }
    else if(g_currentCheckPoint == 1)
    {
        ui->stackedWidget->setCurrentWidget(ui->coinPage);
        ui->titleLabel->setText("关卡选择");
        if(m_checkPoinPage)
        {
            emit  m_checkPoinPage->SigBackToGameChoicePage();
        }
    }

}

void myApplication::on_ilanBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->plantPage);
    ui->titleLabel->setText("打飞机");
    if(!ui->backToMainPageBtn->isVisible())
    {
        ui->backToMainPageBtn->show();
    }
}


void myApplication::on_gameBtn_clicked()
{
      ui->detialstackedWidget->setCurrentWidget(ui->gamePage);
}

void myApplication::on_audioBtn_clicked()
{
      ui->detialstackedWidget->setCurrentWidget(ui->audioPage);
}

void myApplication::on_crackBtn_clicked()
{
  ui->detialstackedWidget->setCurrentWidget(ui->crackPage);
}

void myApplication::on_messageBtn_clicked()
{
ui->detialstackedWidget->setCurrentWidget(ui->messagePage);
}

void myApplication::on_armBtn_clicked()
{
ui->detialstackedWidget->setCurrentWidget(ui->armPage);
}

void myApplication::on_allBtn_clicked()
{
    ui->detialstackedWidget->setCurrentWidget(ui->allAppPage);
}
