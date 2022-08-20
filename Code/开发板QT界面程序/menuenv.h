#ifndef MENUENV_H
#define MENUENV_H

#include <QWidget>
#include "env.h"
#include "history.h"
#include "ui_env.h"
#include "ui_history.h"

namespace Ui {
class Menuenv;
}

class Menuenv : public QWidget
{
    Q_OBJECT

public:
    explicit Menuenv(QWidget *parent = 0);
    ~Menuenv();

private slots:

    void on_btn_realtime_clicked();

    void on_btn_history_clicked();

    void on_btn_back_clicked();

    void reshow();

signals:
    void sesignal();

private:
    Ui::Menuenv *ui;
    History hy;
};

#endif // MENUENV_H
