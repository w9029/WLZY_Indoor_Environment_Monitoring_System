#ifndef OFFLINEMENU_H
#define OFFLINEMENU_H

#include <QWidget>
#include "menuenv.h"
#include "ui_menuenv.h"
#include "stream.h"
#include "ui_stream.h"


namespace Ui {
class Offlinemenu;
}

class Offlinemenu : public QWidget
{
    Q_OBJECT

public:
    explicit Offlinemenu(QWidget *parent = 0);
    ~Offlinemenu();

signals:
    void sesend();

private slots:
    void on_btn_camera_clicked();

    void on_btn_environ_clicked();

    void on_btn_back_clicked();

    void reshow();

private:
    Ui::Offlinemenu *ui;
    Menuenv mv;
    Stream sm;
};

#endif // OFFLINEMENU_H
