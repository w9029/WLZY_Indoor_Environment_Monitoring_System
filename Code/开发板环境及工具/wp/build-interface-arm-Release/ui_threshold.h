/********************************************************************************
** Form generated from reading UI file 'threshold.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLD_H
#define UI_THRESHOLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Threshold
{
public:
    QLabel *label_10;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QDoubleSpinBox *tmin;
    QLabel *label_2;
    QDoubleSpinBox *tmax;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QDoubleSpinBox *hmin;
    QLabel *label_6;
    QDoubleSpinBox *hmax;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_7;
    QDoubleSpinBox *amin;
    QLabel *label_8;
    QDoubleSpinBox *amax;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_sub;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_back;

    void setupUi(QWidget *Threshold)
    {
        if (Threshold->objectName().isEmpty())
            Threshold->setObjectName(QStringLiteral("Threshold"));
        Threshold->resize(800, 480);
        Threshold->setMinimumSize(QSize(800, 480));
        Threshold->setMaximumSize(QSize(800, 480));
        Threshold->setStyleSheet(QLatin1String("#Threshold\n"
"{\n"
"	background-image: url(:/new/pic/timg.jpg);\n"
"}"));
        label_10 = new QLabel(Threshold);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(100, 30, 621, 61));
        label_10->setStyleSheet(QLatin1String("color: rgb(252, 175, 62);\n"
"font: 18pt \"Ubuntu\";"));
        widget = new QWidget(Threshold);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 110, 711, 231));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color: rgb(39, 251, 255);\n"
"font: 18pt \"Ubuntu\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setStyleSheet(QLatin1String("font: 18pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout->addWidget(label_3);

        tmin = new QDoubleSpinBox(widget);
        tmin->setObjectName(QStringLiteral("tmin"));
        sizePolicy.setHeightForWidth(tmin->sizePolicy().hasHeightForWidth());
        tmin->setSizePolicy(sizePolicy);
        tmin->setStyleSheet(QLatin1String("color: rgb(255, 248, 0);\n"
"font: 16pt \"Ubuntu\";\n"
"background-color: rgb(32, 74, 135);"));
        tmin->setDecimals(1);

        horizontalLayout->addWidget(tmin);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font: 18pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout->addWidget(label_2);

        tmax = new QDoubleSpinBox(widget);
        tmax->setObjectName(QStringLiteral("tmax"));
        sizePolicy.setHeightForWidth(tmax->sizePolicy().hasHeightForWidth());
        tmax->setSizePolicy(sizePolicy);
        tmax->setStyleSheet(QLatin1String("color: rgb(255, 248, 0);\n"
"background-color: rgb(32, 74, 135);\n"
"font: 16pt \"Ubuntu\";"));
        tmax->setDecimals(1);

        horizontalLayout->addWidget(tmax);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("font: 18pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setStyleSheet(QLatin1String("font: 18pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout_2->addWidget(label_5);

        hmin = new QDoubleSpinBox(widget);
        hmin->setObjectName(QStringLiteral("hmin"));
        sizePolicy.setHeightForWidth(hmin->sizePolicy().hasHeightForWidth());
        hmin->setSizePolicy(sizePolicy);
        hmin->setStyleSheet(QLatin1String("background-color: rgb(32, 74, 135);\n"
"font: 16pt \"Ubuntu\";\n"
"color: rgb(255, 248, 0);"));
        hmin->setDecimals(1);

        horizontalLayout_2->addWidget(hmin);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("font: 18pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout_2->addWidget(label_6);

        hmax = new QDoubleSpinBox(widget);
        hmax->setObjectName(QStringLiteral("hmax"));
        sizePolicy.setHeightForWidth(hmax->sizePolicy().hasHeightForWidth());
        hmax->setSizePolicy(sizePolicy);
        hmax->setStyleSheet(QLatin1String("color: rgb(255, 248, 0);\n"
"background-color: rgb(32, 74, 135);\n"
"font: 16pt \"Ubuntu\";"));
        hmax->setDecimals(1);

        horizontalLayout_2->addWidget(hmax);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);
        horizontalLayout_2->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QLatin1String("font: 18pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout_3->addWidget(label_9);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setStyleSheet(QLatin1String("font: 18pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout_3->addWidget(label_7);

        amin = new QDoubleSpinBox(widget);
        amin->setObjectName(QStringLiteral("amin"));
        sizePolicy.setHeightForWidth(amin->sizePolicy().hasHeightForWidth());
        amin->setSizePolicy(sizePolicy);
        amin->setStyleSheet(QLatin1String("color: rgb(255, 248, 0);\n"
"font: 16pt \"Ubuntu\";\n"
"background-color: rgb(32, 74, 135);"));
        amin->setDecimals(1);

        horizontalLayout_3->addWidget(amin);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("font: 18pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout_3->addWidget(label_8);

        amax = new QDoubleSpinBox(widget);
        amax->setObjectName(QStringLiteral("amax"));
        sizePolicy.setHeightForWidth(amax->sizePolicy().hasHeightForWidth());
        amax->setSizePolicy(sizePolicy);
        amax->setStyleSheet(QLatin1String("color: rgb(255, 248, 0);\n"
"background-color: rgb(32, 74, 135);\n"
"font: 16pt \"Ubuntu\";"));
        amax->setDecimals(1);

        horizontalLayout_3->addWidget(amax);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 1);
        horizontalLayout_3->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        widget1 = new QWidget(Threshold);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(200, 360, 411, 81));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        btn_sub = new QPushButton(widget1);
        btn_sub->setObjectName(QStringLiteral("btn_sub"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_sub->sizePolicy().hasHeightForWidth());
        btn_sub->setSizePolicy(sizePolicy1);
        btn_sub->setStyleSheet(QLatin1String("color: rgb(39, 251, 255);\n"
"background-color: rgb(14,23,52);"));

        horizontalLayout_4->addWidget(btn_sub);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btn_back = new QPushButton(widget1);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        sizePolicy1.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy1);
        btn_back->setStyleSheet(QLatin1String("color: rgb(39, 251, 255);\n"
"background-color: rgb(14,23,52);"));

        horizontalLayout_4->addWidget(btn_back);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 3);

        retranslateUi(Threshold);

        QMetaObject::connectSlotsByName(Threshold);
    } // setupUi

    void retranslateUi(QWidget *Threshold)
    {
        Threshold->setWindowTitle(QApplication::translate("Threshold", "Form", Q_NULLPTR));
        label_10->setText(QApplication::translate("Threshold", "Please enter a range, beyond this range will be alert !", Q_NULLPTR));
        label->setText(QApplication::translate("Threshold", "Temperature:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Threshold", "Min:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Threshold", "Max:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Threshold", "Humidity:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Threshold", "Min:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Threshold", "Max:", Q_NULLPTR));
        label_9->setText(QApplication::translate("Threshold", "Ammonia:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Threshold", "Min:", Q_NULLPTR));
        label_8->setText(QApplication::translate("Threshold", "Max:", Q_NULLPTR));
        btn_sub->setText(QApplication::translate("Threshold", "Submit", Q_NULLPTR));
        btn_back->setText(QApplication::translate("Threshold", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Threshold: public Ui_Threshold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLD_H
