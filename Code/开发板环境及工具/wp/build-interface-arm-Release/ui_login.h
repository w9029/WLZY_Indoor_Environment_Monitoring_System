/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *username;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lab_status;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_login;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_cancel;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(800, 480);
        Login->setMinimumSize(QSize(800, 480));
        Login->setMaximumSize(QSize(800, 480));
        Login->setAutoFillBackground(false);
        Login->setStyleSheet(QLatin1String("#Login\n"
"{\n"
"	border-image: url(:/new/pic/timg.jpg);\n"
"}"));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 50, 451, 41));
        label_3->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(245, 121, 0);"));
        widget = new QWidget(Login);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(61, 121, 631, 301));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color:rgb(252, 233, 79);\n"
"font: 12pt \"Ubuntu\";"));

        horizontalLayout->addWidget(label);

        username = new QLineEdit(widget);
        username->setObjectName(QStringLiteral("username"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy);
        username->setMinimumSize(QSize(0, 40));
        username->setClearButtonEnabled(true);

        horizontalLayout->addWidget(username);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color: rgb(252, 233, 79);\n"
"font: 12pt \"Ubuntu\";"));

        horizontalLayout_2->addWidget(label_2);

        password = new QLineEdit(widget);
        password->setObjectName(QStringLiteral("password"));
        sizePolicy.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy);
        password->setMinimumSize(QSize(0, 40));
        password->setEchoMode(QLineEdit::Password);
        password->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(password);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        lab_status = new QLabel(widget);
        lab_status->setObjectName(QStringLiteral("lab_status"));
        lab_status->setStyleSheet(QLatin1String("font: 12pt \"Ubuntu\";\n"
"color: rgb(255, 248, 0);"));

        verticalLayout->addWidget(lab_status);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btn_login = new QPushButton(widget);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_login->sizePolicy().hasHeightForWidth());
        btn_login->setSizePolicy(sizePolicy1);
        btn_login->setStyleSheet(QLatin1String("background-color: rgb(14, 23, 52);\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout_3->addWidget(btn_login);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btn_cancel = new QPushButton(widget);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        sizePolicy1.setHeightForWidth(btn_cancel->sizePolicy().hasHeightForWidth());
        btn_cancel->setSizePolicy(sizePolicy1);
        btn_cancel->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout_3->addWidget(btn_cancel);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 3);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "Please input your username and password!", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "Username:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "Password:", Q_NULLPTR));
        lab_status->setText(QString());
        btn_login->setText(QApplication::translate("Login", "Login", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("Login", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
