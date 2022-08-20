/********************************************************************************
** Form generated from reading UI file 'showmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWMENU_H
#define UI_SHOWMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Showmenu
{
public:
    QPushButton *btn_back;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_monitor;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_environ;

    void setupUi(QWidget *Showmenu)
    {
        if (Showmenu->objectName().isEmpty())
            Showmenu->setObjectName(QStringLiteral("Showmenu"));
        Showmenu->resize(800, 480);
        Showmenu->setMinimumSize(QSize(800, 480));
        Showmenu->setMaximumSize(QSize(800, 480));
        Showmenu->setStyleSheet(QLatin1String("#Showmenu\n"
"{\n"
"	border-image: url(:/new/pic/timg.jpg);\n"
"}"));
        btn_back = new QPushButton(Showmenu);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        btn_back->setGeometry(QRect(590, 240, 171, 71));
        btn_back->setStyleSheet(QLatin1String("background-color: rgb(14, 23, 52);\n"
"font: 12pt \"Ubuntu\";\n"
"color: rgb(245, 121, 0);"));
        label = new QLabel(Showmenu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 30, 631, 101));
        label->setStyleSheet(QLatin1String("color: rgb(115, 210, 22);\n"
"font: 16pt \"Ubuntu\";"));
        layoutWidget = new QWidget(Showmenu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 150, 341, 241));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_monitor = new QPushButton(layoutWidget);
        btn_monitor->setObjectName(QStringLiteral("btn_monitor"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_monitor->sizePolicy().hasHeightForWidth());
        btn_monitor->setSizePolicy(sizePolicy);
        btn_monitor->setStyleSheet(QLatin1String("background-color: rgb(14, 23, 52);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(245, 121, 0);"));

        verticalLayout->addWidget(btn_monitor);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_environ = new QPushButton(layoutWidget);
        btn_environ->setObjectName(QStringLiteral("btn_environ"));
        sizePolicy.setHeightForWidth(btn_environ->sizePolicy().hasHeightForWidth());
        btn_environ->setSizePolicy(sizePolicy);
        btn_environ->setStyleSheet(QLatin1String("background-color: rgb(14, 23, 52);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(245, 121, 0);"));

        verticalLayout->addWidget(btn_environ);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 3);

        retranslateUi(Showmenu);

        QMetaObject::connectSlotsByName(Showmenu);
    } // setupUi

    void retranslateUi(QWidget *Showmenu)
    {
        Showmenu->setWindowTitle(QApplication::translate("Showmenu", "Form", Q_NULLPTR));
        btn_back->setText(QApplication::translate("Showmenu", "Back to main menu", Q_NULLPTR));
        label->setText(QApplication::translate("Showmenu", "Welcome to use this system!\n"
"Please click on the button to continue do what you want to do.", Q_NULLPTR));
        btn_monitor->setText(QApplication::translate("Showmenu", " Real-time monitoring", Q_NULLPTR));
        btn_environ->setText(QApplication::translate("Showmenu", "Environmental information", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Showmenu: public Ui_Showmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWMENU_H
