#ifndef SHOWMENU_H
#define SHOWMENU_H

#include <QWidget>
#include "menuenv.h"
#include "ui_menuenv.h"
#include "stream.h"
#include "ui_stream.h"

namespace Ui {
class Showmenu;
}

class Showmenu : public QWidget
{
    Q_OBJECT

public:
    explicit Showmenu(QWidget *parent = 0);
    ~Showmenu();

private slots:
    void on_btn_back_clicked();

    void on_btn_monitor_clicked();

    void on_btn_environ_clicked();

    void reshow();

signals:
    void sendsignal();

private:
    Ui::Showmenu *ui;
    Menuenv mv;
    Stream sm;
};

#endif // SHOWMENU_H
