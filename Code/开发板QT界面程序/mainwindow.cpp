#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QString nowname;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Mainmenu");
    nowname = "NULL";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_login_clicked()
{
    this->close();
    connect(&ln,SIGNAL(sendsignal()),this,SLOT(reshow()));
    qDebug() << "The user login.";
    this->ln.show();
}

void MainWindow::on_btn_offline_clicked()
{
    this->close();
    connect(&ou,SIGNAL(sesend()),this,SLOT(reshow()));
    qDebug() << "Users use the offline mode";
    this->ou.show();
}

void MainWindow::on_btn_exit_clicked()
{
    this->close();
}
void MainWindow::reshow()
{
    this->show();
}
