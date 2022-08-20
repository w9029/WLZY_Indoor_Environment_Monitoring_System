/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_login;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_offline;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btn_exit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        MainWindow->setStyleSheet(QLatin1String("\n"
"background-image: url(:/new/pic/timg.jpg);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 0, 691, 101));
        label->setStyleSheet(QLatin1String("color: rgb(245, 121, 0);\n"
"font: 20pt \"Ubuntu\";"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 771, 81));
        label_2->setStyleSheet(QLatin1String("color: rgb(138, 226, 52);\n"
"font: 11pt \"Ubuntu\";\n"
""));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 190, 461, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_login = new QPushButton(layoutWidget);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_login->sizePolicy().hasHeightForWidth());
        btn_login->setSizePolicy(sizePolicy);
        btn_login->setStyleSheet(QLatin1String("color: rgb(245, 121, 0);\n"
"font: 15pt \"Ubuntu\";"));

        verticalLayout->addWidget(btn_login);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_offline = new QPushButton(layoutWidget);
        btn_offline->setObjectName(QStringLiteral("btn_offline"));
        sizePolicy.setHeightForWidth(btn_offline->sizePolicy().hasHeightForWidth());
        btn_offline->setSizePolicy(sizePolicy);
        btn_offline->setStyleSheet(QLatin1String("color: rgb(245, 121, 0);\n"
"font: 15pt \"Ubuntu\";"));

        verticalLayout->addWidget(btn_offline);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btn_exit = new QPushButton(layoutWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        sizePolicy.setHeightForWidth(btn_exit->sizePolicy().hasHeightForWidth());
        btn_exit->setSizePolicy(sizePolicy);
        btn_exit->setStyleSheet(QLatin1String("color: rgb(245, 121, 0);\n"
"font: 15pt \"Ubuntu\";"));

        verticalLayout->addWidget(btn_exit);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Welcome to use the environmental monitoring system!", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Note: login button can be connected to the Internet to see more news, and synchronization with the web page;\n"
"Off-line button to view the real-time data; \n"
"Click the exit button to exit the program.\n"
"If you want to register, please go to website.\n"
"", Q_NULLPTR));
        btn_login->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        btn_offline->setText(QApplication::translate("MainWindow", "Offline", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
