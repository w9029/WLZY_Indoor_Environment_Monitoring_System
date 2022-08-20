/********************************************************************************
** Form generated from reading UI file 'menuenv.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUENV_H
#define UI_MENUENV_H

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

class Ui_Menuenv
{
public:
    QPushButton *btn_back;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_realtime;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_history;

    void setupUi(QWidget *Menuenv)
    {
        if (Menuenv->objectName().isEmpty())
            Menuenv->setObjectName(QStringLiteral("Menuenv"));
        Menuenv->resize(800, 480);
        Menuenv->setMinimumSize(QSize(800, 480));
        Menuenv->setMaximumSize(QSize(800, 480));
        Menuenv->setStyleSheet(QLatin1String("#Menuenv\n"
"{\n"
"border-image: url(:/new/pic/timg.jpg);\n"
"}\n"
""));
        btn_back = new QPushButton(Menuenv);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        btn_back->setGeometry(QRect(640, 270, 121, 81));
        btn_back->setStyleSheet(QLatin1String("font: 12pt \"Ubuntu\";\n"
"background-color: rgb(14, 23, 52);\n"
"color: rgb(138, 226, 52);"));
        label = new QLabel(Menuenv);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 60, 661, 71));
        label->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(255, 248, 0);"));
        widget = new QWidget(Menuenv);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(150, 190, 441, 251));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btn_realtime = new QPushButton(widget);
        btn_realtime->setObjectName(QStringLiteral("btn_realtime"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_realtime->sizePolicy().hasHeightForWidth());
        btn_realtime->setSizePolicy(sizePolicy);
        btn_realtime->setStyleSheet(QLatin1String("color: rgb(252, 175, 62);\n"
"background-color: rgb(14, 23, 52);\n"
"font: 18pt \"Ubuntu\";\n"
""));

        verticalLayout->addWidget(btn_realtime);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_history = new QPushButton(widget);
        btn_history->setObjectName(QStringLiteral("btn_history"));
        sizePolicy.setHeightForWidth(btn_history->sizePolicy().hasHeightForWidth());
        btn_history->setSizePolicy(sizePolicy);
        btn_history->setStyleSheet(QLatin1String("color: rgb(252, 175, 62);\n"
"background-color: rgb(14, 23, 52);\n"
"font: 18pt \"Ubuntu\";"));

        verticalLayout->addWidget(btn_history);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(2, 3);

        retranslateUi(Menuenv);

        QMetaObject::connectSlotsByName(Menuenv);
    } // setupUi

    void retranslateUi(QWidget *Menuenv)
    {
        Menuenv->setWindowTitle(QApplication::translate("Menuenv", "Form", Q_NULLPTR));
        btn_back->setText(QApplication::translate("Menuenv", "Back", Q_NULLPTR));
        label->setText(QApplication::translate("Menuenv", "You can view real-time environmental quality or record in this page .\n"
" ", Q_NULLPTR));
        btn_realtime->setText(QApplication::translate("Menuenv", "Real-time", Q_NULLPTR));
        btn_history->setText(QApplication::translate("Menuenv", "History", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Menuenv: public Ui_Menuenv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUENV_H
