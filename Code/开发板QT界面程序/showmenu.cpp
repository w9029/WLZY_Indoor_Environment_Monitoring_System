#include "showmenu.h"
#include "ui_showmenu.h"

Showmenu::Showmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Showmenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_DeleteOnClose,0);
    setWindowTitle("Menu");
}

Showmenu::~Showmenu()
{
    delete ui;
}

void Showmenu::on_btn_back_clicked()
{
    emit sendsignal();
    this->close();
}

void Showmenu::on_btn_environ_clicked()
{
    this->close();
    connect(&mv,SIGNAL(sesignal()),this,SLOT(reshow()));
    qDebug() << "Users use the environmental monitoring.";
    mv.show();
}

void Showmenu::reshow()
{
    this->show();
}

void Showmenu::on_btn_monitor_clicked()
{
    this->close();
    connect(&sm,SIGNAL(sesignal()),this,SLOT(reshow()));
    qDebug() << "Users use the video monitoring.";
    sm.show();

}
