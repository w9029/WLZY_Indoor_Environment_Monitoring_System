#include "offlinemenu.h"
#include "ui_offlinemenu.h"

Offlinemenu::Offlinemenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Offlinemenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_DeleteOnClose,0);
    setWindowTitle("Off-line model");
}

Offlinemenu::~Offlinemenu()
{
    delete ui;
}

void Offlinemenu::on_btn_camera_clicked()
{
    this->close();
    connect(&sm,SIGNAL(sesignal()),this,SLOT(reshow()));
    qDebug() << "Users use the video monitoring.";
    sm.show();
}

void Offlinemenu::on_btn_environ_clicked()
{
    this->close();
    connect(&mv,SIGNAL(sesignal()),this,SLOT(reshow()));
    qDebug() << "Users use the environmental monitoring.";
    this->mv.show();
}

void Offlinemenu::on_btn_back_clicked()
{
    emit sesend();
    this->close();
}

void Offlinemenu::reshow()
{
    this->show();
}
