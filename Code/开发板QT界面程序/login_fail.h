#ifndef LOGIN_FAIL_H
#define LOGIN_FAIL_H

#include <QWidget>

namespace Ui {
class login_fail;
}

class login_fail : public QWidget
{
    Q_OBJECT

public:
    explicit login_fail(QWidget *parent = 0);
    ~login_fail();

private:
    Ui::login_fail *ui;
};

#endif // LOGIN_FAIL_H
