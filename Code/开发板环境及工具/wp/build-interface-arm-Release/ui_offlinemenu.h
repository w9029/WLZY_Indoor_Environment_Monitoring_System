/********************************************************************************
** Form generated from reading UI file 'offlinemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFFLINEMENU_H
#define UI_OFFLINEMENU_H

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

class Ui_Offlinemenu
{
public:
    QLabel *label;
    QPushButton *btn_back;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_camera;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_environ;

    void setupUi(QWidget *Offlinemenu)
    {
        if (Offlinemenu->objectName().isEmpty())
            Offlinemenu->setObjectName(QStringLiteral("Offlinemenu"));
        Offlinemenu->resize(800, 480);
        Offlinemenu->setMinimumSize(QSize(800, 480));
        Offlinemenu->setMaximumSize(QSize(800, 480));
        Offlinemenu->setStyleSheet(QLatin1String("#Offlinemenu\n"
"{\n"
"	background-image: url(:/new/pic/timg.jpg);\n"
"}"));
        label = new QLabel(Offlinemenu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 351, 71));
        label->setStyleSheet(QLatin1String("color: rgb(245, 121, 0);\n"
"font: 20pt \"Ubuntu\";"));
        btn_back = new QPushButton(Offlinemenu);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        btn_back->setGeometry(QRect(660, 400, 121, 61));
        btn_back->setStyleSheet(QLatin1String("background-color: rgb(14, 23, 52);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));
        layoutWidget = new QWidget(Offlinemenu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 130, 331, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_camera = new QPushButton(layoutWidget);
        btn_camera->setObjectName(QStringLiteral("btn_camera"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_camera->sizePolicy().hasHeightForWidth());
        btn_camera->setSizePolicy(sizePolicy);
        btn_camera->setStyleSheet(QLatin1String("background-color: rgb(14, 23, 52);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        verticalLayout->addWidget(btn_camera);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_environ = new QPushButton(layoutWidget);
        btn_environ->setObjectName(QStringLiteral("btn_environ"));
        sizePolicy.setHeightForWidth(btn_environ->sizePolicy().hasHeightForWidth());
        btn_environ->setSizePolicy(sizePolicy);
        btn_environ->setStyleSheet(QLatin1String("background-color: rgb(14, 23, 52);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        verticalLayout->addWidget(btn_environ);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 3);

        retranslateUi(Offlinemenu);

        QMetaObject::connectSlotsByName(Offlinemenu);
    } // setupUi

    void retranslateUi(QWidget *Offlinemenu)
    {
        Offlinemenu->setWindowTitle(QApplication::translate("Offlinemenu", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Offlinemenu", "Now you are offline!\n"
"What do you want to do?", Q_NULLPTR));
        btn_back->setText(QApplication::translate("Offlinemenu", "Back", Q_NULLPTR));
        btn_camera->setText(QApplication::translate("Offlinemenu", "Real-time monitior", Q_NULLPTR));
        btn_environ->setText(QApplication::translate("Offlinemenu", "Environment information", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Offlinemenu: public Ui_Offlinemenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFFLINEMENU_H
