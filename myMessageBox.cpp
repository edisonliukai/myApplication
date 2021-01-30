#include "myMessageBox.h"
#include "ui_myMessageBox.h"

myMessageBox::myMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myMessageBox)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    //this->setStyleSheet("padding:10px 10px 10px 10px;");
}


myMessageBox::~myMessageBox()
{
    delete ui;
}

void myMessageBox::on_toolButton_clicked()
{
    this->hide();
}
