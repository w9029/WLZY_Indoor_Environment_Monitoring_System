#include "login_fail.h"
#include "ui_login_fail.h"

login_fail::login_fail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_fail)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
}

login_fail::~login_fail()
{
    delete ui;
}
