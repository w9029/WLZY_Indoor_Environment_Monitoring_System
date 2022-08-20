#include "menuenv.h"
#include "ui_menuenv.h"

Menuenv::Menuenv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menuenv)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_DeleteOnClose,0);
    setWindowTitle("Menu");
}

Menuenv::~Menuenv()
{
    delete ui;
}



void Menuenv::on_btn_realtime_clicked()
{
    this->close();
    Env *ev = new Env;
    connect(ev,SIGNAL(sesignal()),this,SLOT(reshow()));
    qDebug() << "The user to see the real time environmental monitoring";
    ev->show();
}

void Menuenv::on_btn_history_clicked()
{
    this->close();
    connect(&hy,SIGNAL(sesignal()),this,SLOT(reshow()));
    qDebug() << "The user to see the environmental history";
    hy.show();
}

void Menuenv::on_btn_back_clicked()
{
    emit sesignal();
    this->close();
}

void Menuenv::reshow()
{
    this->show();
}
