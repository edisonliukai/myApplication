#include "coinPage.h"
#include<algorithm>
#include<QMessageBox>
coinPage::coinPage(QWidget *parent) : QWidget(parent)
{

}

coinPage::coinPage(QWidget *parent, int index):QWidget(parent),m_currentCheckPoint(index)
,m_layout(new QGridLayout(this))
  ,m_label(new QLabel(this))
{
    m_label->setAlignment(Qt::AlignHCenter);
    initData();
    setCheckPointData();
    for(int i = 0;i<16;++i)
    {
        m_btnGroup[i]= NULL;
    }
    int tmp = 0;
    for(int i = 0;i<4;++i)
    {
        for(int j = 0;j<4;++j)
        {
            tmp = j+4*i;
            if(m_data[m_currentCheckPoint][j][i]== 0)
            {
                m_btnGroup[tmp]  = new coinBtn(":/image/Coin0001.png",0);

            }
            else if(m_data[m_currentCheckPoint][j][i] ==  1)
            {
                m_btnGroup[tmp]  = new coinBtn(":/image/Coin0008.png",1);
            }

            m_btnGroup[tmp] ->setX(i);
            m_btnGroup[tmp] ->setY(j);
            connect(m_btnGroup[tmp] ,&coinBtn::clicked,[=](){
            // emit SigPlayMusic(":/image/ConFlipSound.wav");
                m_btnGroup[tmp]->coinFlagChanged();
                for(int k= 0;k<16;++k)
                {

                        if((tmp+1)%4 == 0)
                        {
                            if( k == tmp -1||k==tmp-4||k==tmp+4)
                            {
                                m_btnGroup[k]->coinFlagChanged();
                            }
                        }
                        else  if(tmp%4==0)
                        {
                            if( k == tmp +1||k==tmp-4||k==tmp+4)
                            {
                                m_btnGroup[k]->coinFlagChanged();
                            }
                        }
                        else
                        {
                            if( k == tmp +1||k==tmp-1||k==tmp-4||k==tmp+4)
                            {
                                m_btnGroup[k]->coinFlagChanged();
                            }
                        }
                        qDebug()<<"m_flag ="<<m_btnGroup[k]->m_flag;
                    }
                judeifWin();
          });
            // btn->setMinimumSize(60,40);
            m_btnGroup[tmp]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
            m_layout->setColumnStretch(j,1);

            //
            m_layout->addWidget(m_btnGroup[tmp],i,j);
        }
        m_layout->setRowStretch(i,1);

    }
    m_layout->setContentsMargins(100,100,100,100);
    m_layout->setSpacing(10);
    this->setLayout(m_layout);
}

void coinPage::initData()
{
#if 0
    for(int i = 0;i<20;++i)
    {
         for(int j = 0;j<16;++j)
         {
             if(i%4 == 0)
             {
                 m_data[i][j] = 1;
             }
             else
             {
                 m_data[i][j] = 0;
             }

         }
    }
  #endif
QVector<QVector<int>>v;
int array1[4][4] ={ {0, 0, 0, 0},
                 {0, 0, 1, 0},
                 {0, 1, 1, 1},
                 {0, 0, 1, 0} };
for(int i = 0;i<4;++i)
{
    QVector<int>v1;
    for(int j = 0;j<4;++j)
    {
       v1.push_back(array1[i][j]);
    }
    v.push_back(v1);
}
m_data.insert(1,v);

int array2[4][4] = { {1, 0, 1, 1},
                     {0, 0, 1, 1},
                     {1, 1, 0, 0},
                     {1, 1, 0, 1}} ;

v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array2[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(2,v);



int array3[4][4] = {  {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array3[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(3,v);


int array4[4][4] = {   {0, 1, 1, 1},
                       {1, 0, 0, 1},
                       {1, 0, 1, 1},
                       {1, 1, 1, 1}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array4[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(4,v);


int array5[4][4] = {  {1, 0, 0, 1},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {1, 0, 0, 1}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array5[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(5,v);


int array6[4][4] = {   {1, 0, 0, 1},
                       {0, 1, 1, 0},
                       {0, 1, 1, 0},
                       {1, 0, 0, 1}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array6[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(6,v);


int array7[4][4] = {   {0, 1, 1, 1},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {1, 1, 1, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array7[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(7,v);

int array8[4][4] = {  {0, 1, 0, 1},
                      {1, 0, 0, 0},
                      {0, 0, 0, 1},
                      {1, 0, 1, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array8[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(8,v);

int array9[4][4] = {   {1, 0, 1, 0},
                       {1, 0, 1, 0},
                       {0, 0, 1, 0},
                       {1, 0, 0, 1}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array9[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(9,v);



int array10[4][4] = {  {1, 0, 1, 1},
                       {1, 1, 0, 0},
                       {0, 0, 1, 1},
                       {1, 1, 0, 1}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array10[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(10,v);


int array11[4][4] = {  {0, 1, 1, 0},
                       {1, 0, 0, 1},
                       {1, 0, 0, 1},
                       {0, 1, 1, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array11[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(11,v);

int array12[4][4] = {  {0, 1, 1, 0},
                       {0, 0, 0, 0},
                       {1, 1, 1, 1},
                       {0, 0, 0, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array12[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(12,v);


int array13[4][4] = {    {0, 1, 1, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 1, 1, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array13[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(13,v);

int array14[4][4] = {    {1, 0, 1, 1},
                         {0, 1, 0, 1},
                         {1, 0, 1, 0},
                         {1, 1, 0, 1}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array14[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(14,v);


int array15[4][4] = {   {0, 1, 0, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 0},
                        {0, 1, 0, 1}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array15[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(15,v);


int array16[4][4] = {   {0, 1, 1, 0},
                        {1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {0, 1, 1, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array16[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(16,v);

int array17[4][4] = {  {0, 1, 1, 1},
                       {0, 1, 0, 0},
                       {0, 0, 1, 0},
                       {1, 1, 1, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array17[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(17,v);


int array18[4][4] = { {0, 0, 0, 1},
                      {0, 0, 1, 0},
                      {0, 1, 0, 0},
                      {1, 0, 0, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array18[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(18,v);

int array19[4][4] = {   {0, 1, 0, 0},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 0}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array19[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(19,v);

int array20[4][4] = {  {1, 1, 1, 1},
                       {1, 1, 1, 1},
                       {1, 1, 1, 1},
                       {1, 1, 1, 1}} ;
v.clear();
for(int i = 0 ; i < 4;i++)
{
     QVector<int>v1;
     for(int j = 0 ; j < 4;j++)
     {
        v1.push_back(array20[i][j]);
     }
     v.push_back(v1);
}

m_data.insert(20,v);
}

void coinPage::setCheckPointData()
{
  //  std::random_shuffle(m_data.begin(),m_data.end());
    for(int i = 0;i<20;++i)
    {
        //qDebug()<<"i = "<<m_data[i];
    }
}


void  coinPage::judeifWin()
{
    for(int i = 0;i<16;++i)
    {
        if(m_btnGroup[i]->m_flag == 1)
        {
            return;
        }

       // QMessageBox::information(this,"tip","恭喜过关!");
    }
    if(m_label)
    {
        m_label->setText("恭喜过关!");
        m_label->move(this->width()/2-m_label->width()/2,0);
        m_label->show();
    }
}
