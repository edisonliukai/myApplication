#ifndef MYMESSAGEBOX_H
#define MYMESSAGEBOX_H

#include <QDialog>

namespace Ui {
class myMessageBox;
}

class myMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit myMessageBox(QWidget *parent = 0);
    ~myMessageBox();

private slots:
    void on_toolButton_clicked();

private:
    Ui::myMessageBox *ui;
};

#endif // MYMESSAGEBOX_H
