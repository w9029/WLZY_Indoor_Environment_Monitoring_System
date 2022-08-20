/********************************************************************************
** Form generated from reading UI file 'env.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENV_H
#define UI_ENV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Env
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *lcd_temp;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLCDNumber *lcd_hum;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLCDNumber *lcd_amm;
    QLabel *label_6;
    QLCDNumber *lcd_time;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_th;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_back;

    void setupUi(QWidget *Env)
    {
        if (Env->objectName().isEmpty())
            Env->setObjectName(QStringLiteral("Env"));
        Env->resize(800, 480);
        Env->setMinimumSize(QSize(800, 480));
        Env->setMaximumSize(QSize(800, 480));
        Env->setStyleSheet(QLatin1String("#Env\n"
"{\n"
"	background-image: url(:/new/pic/timg.jpg);\n"
"}"));
        layoutWidget = new QWidget(Env);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 150, 501, 291));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color: rgb(245, 121, 0);\n"
"font: 24pt \"Ubuntu\";"));

        horizontalLayout->addWidget(label);

        lcd_temp = new QLCDNumber(layoutWidget);
        lcd_temp->setObjectName(QStringLiteral("lcd_temp"));
        lcd_temp->setStyleSheet(QStringLiteral("color: rgb(255, 248, 0);"));
        lcd_temp->setDigitCount(4);

        horizontalLayout->addWidget(lcd_temp);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font: 25pt \"Ubuntu\";\n"
"color: rgb(245, 121, 0);"));

        horizontalLayout->addWidget(label_2);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("color: rgb(245, 121, 0);\n"
"font: 24pt \"Ubuntu\";"));

        horizontalLayout_2->addWidget(label_3);

        lcd_hum = new QLCDNumber(layoutWidget);
        lcd_hum->setObjectName(QStringLiteral("lcd_hum"));
        lcd_hum->setStyleSheet(QStringLiteral("color: rgb(255, 248, 0);"));
        lcd_hum->setDigitCount(4);

        horizontalLayout_2->addWidget(lcd_hum);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("color: rgb(245, 121, 0);\n"
"font: 25pt \"Ubuntu\";"));

        horizontalLayout_2->addWidget(label_4);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 3);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("font: 24pt \"Ubuntu\";\n"
"color: rgb(245, 121, 0);"));

        horizontalLayout_3->addWidget(label_5);

        lcd_amm = new QLCDNumber(layoutWidget);
        lcd_amm->setObjectName(QStringLiteral("lcd_amm"));
        lcd_amm->setStyleSheet(QStringLiteral("color: rgb(255, 248, 0);"));
        lcd_amm->setDigitCount(4);

        horizontalLayout_3->addWidget(lcd_amm);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("font: 25pt \"Ubuntu\";\n"
"color: rgb(245, 121, 0);"));

        horizontalLayout_3->addWidget(label_6);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        lcd_time = new QLCDNumber(Env);
        lcd_time->setObjectName(QStringLiteral("lcd_time"));
        lcd_time->setGeometry(QRect(10, 30, 781, 61));
        lcd_time->setStyleSheet(QStringLiteral("color: rgb(39, 251, 255);"));
        lcd_time->setDigitCount(26);
        widget = new QWidget(Env);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(630, 170, 161, 201));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_th = new QPushButton(widget);
        btn_th->setObjectName(QStringLiteral("btn_th"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_th->sizePolicy().hasHeightForWidth());
        btn_th->setSizePolicy(sizePolicy);
        btn_th->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"color: rgb(245, 121, 0);"));

        verticalLayout_2->addWidget(btn_th);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        btn_back = new QPushButton(widget);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        sizePolicy.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy);
        btn_back->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"color: rgb(245, 121, 0);"));

        verticalLayout_2->addWidget(btn_back);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(2, 3);

        retranslateUi(Env);

        QMetaObject::connectSlotsByName(Env);
    } // setupUi

    void retranslateUi(QWidget *Env)
    {
        Env->setWindowTitle(QApplication::translate("Env", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Env", "Temperature:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Env", "\342\204\203", Q_NULLPTR));
        label_3->setText(QApplication::translate("Env", "Humidity:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Env", "%rh", Q_NULLPTR));
        label_5->setText(QApplication::translate("Env", "Ammonia:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Env", "ppm", Q_NULLPTR));
        btn_th->setText(QApplication::translate("Env", "Set threshold", Q_NULLPTR));
        btn_back->setText(QApplication::translate("Env", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Env: public Ui_Env {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENV_H
