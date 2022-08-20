/********************************************************************************
** Form generated from reading UI file 'stream.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREAM_H
#define UI_STREAM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stream
{
public:
    QLabel *lab_camera;
    QLabel *lab_pic;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_start;
    QPushButton *btn_shot;
    QPushButton *Streamclose;
    QPushButton *btn_quit;

    void setupUi(QWidget *Stream)
    {
        if (Stream->objectName().isEmpty())
            Stream->setObjectName(QStringLiteral("Stream"));
        Stream->resize(800, 480);
        Stream->setMinimumSize(QSize(800, 480));
        Stream->setMaximumSize(QSize(800, 480));
        Stream->setStyleSheet(QLatin1String("#Stream\n"
"{\n"
"	border-image: url(:/new/pic/timg.jpg);\n"
"}"));
        Stream->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        lab_camera = new QLabel(Stream);
        lab_camera->setObjectName(QStringLiteral("lab_camera"));
        lab_camera->setGeometry(QRect(0, 0, 640, 480));
        lab_pic = new QLabel(Stream);
        lab_pic->setObjectName(QStringLiteral("lab_pic"));
        lab_pic->setGeometry(QRect(640, 30, 160, 120));
        label = new QLabel(Stream);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(670, 180, 120, 40));
        label->setStyleSheet(QLatin1String("color: rgb(245, 121, 0);\n"
"font: 13pt \"Ubuntu\";"));
        layoutWidget = new QWidget(Stream);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(660, 260, 121, 191));
        layoutWidget->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"font: 12pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_start = new QPushButton(layoutWidget);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_start->sizePolicy().hasHeightForWidth());
        btn_start->setSizePolicy(sizePolicy);
        btn_start->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"font: 12pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        verticalLayout->addWidget(btn_start);

        btn_shot = new QPushButton(layoutWidget);
        btn_shot->setObjectName(QStringLiteral("btn_shot"));
        sizePolicy.setHeightForWidth(btn_shot->sizePolicy().hasHeightForWidth());
        btn_shot->setSizePolicy(sizePolicy);
        btn_shot->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"font: 12pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        verticalLayout->addWidget(btn_shot);

        Streamclose = new QPushButton(layoutWidget);
        Streamclose->setObjectName(QStringLiteral("Streamclose"));
        sizePolicy.setHeightForWidth(Streamclose->sizePolicy().hasHeightForWidth());
        Streamclose->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Streamclose);

        btn_quit = new QPushButton(layoutWidget);
        btn_quit->setObjectName(QStringLiteral("btn_quit"));
        sizePolicy.setHeightForWidth(btn_quit->sizePolicy().hasHeightForWidth());
        btn_quit->setSizePolicy(sizePolicy);
        btn_quit->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"font: 12pt \"Ubuntu\";\n"
"color: rgb(245, 121, 0);"));

        verticalLayout->addWidget(btn_quit);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);

        retranslateUi(Stream);

        QMetaObject::connectSlotsByName(Stream);
    } // setupUi

    void retranslateUi(QWidget *Stream)
    {
        Stream->setWindowTitle(QApplication::translate("Stream", "Form", Q_NULLPTR));
        lab_camera->setText(QString());
        lab_pic->setText(QString());
        label->setText(QString());
        btn_start->setText(QApplication::translate("Stream", "Start", Q_NULLPTR));
        btn_shot->setText(QApplication::translate("Stream", "ScreenShot", Q_NULLPTR));
        Streamclose->setText(QApplication::translate("Stream", "Stream close", Q_NULLPTR));
        btn_quit->setText(QApplication::translate("Stream", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Stream: public Ui_Stream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAM_H
