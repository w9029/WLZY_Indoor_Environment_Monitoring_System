#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "ui_login.h"
#include "offlinemenu.h"
#include "ui_offlinemenu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_login_clicked();

    void on_btn_offline_clicked();

    void on_btn_exit_clicked();

    void reshow();

private:
    Ui::MainWindow *ui;
    Login ln;
    Offlinemenu ou;
};

#endif // MAINWINDOW_H
