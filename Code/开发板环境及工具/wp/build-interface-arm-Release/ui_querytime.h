/********************************************************************************
** Form generated from reading UI file 'querytime.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYTIME_H
#define UI_QUERYTIME_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Querytime
{
public:
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_query;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_back;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateTimeEdit *stime;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QDateTimeEdit *etime;

    void setupUi(QWidget *Querytime)
    {
        if (Querytime->objectName().isEmpty())
            Querytime->setObjectName(QStringLiteral("Querytime"));
        Querytime->resize(800, 480);
        Querytime->setMinimumSize(QSize(800, 480));
        Querytime->setMaximumSize(QSize(800, 480));
        Querytime->setStyleSheet(QLatin1String("#Querytime\n"
"{\n"
"	background-image: url(:/new/pic/timg.jpg);\n"
"}"));
        tableWidget = new QTableWidget(Querytime);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 60, 741, 321));
        tableWidget->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"font: 13pt \"Ubuntu\";\n"
"color: rgb(138, 226, 52);"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setDefaultSectionSize(172);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);
        layoutWidget = new QWidget(Querytime);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 390, 371, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_query = new QPushButton(layoutWidget);
        btn_query->setObjectName(QStringLiteral("btn_query"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_query->sizePolicy().hasHeightForWidth());
        btn_query->setSizePolicy(sizePolicy);
        btn_query->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgb(39, 251, 255);"));

        horizontalLayout_2->addWidget(btn_query);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_back = new QPushButton(layoutWidget);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        sizePolicy.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy);
        btn_back->setStyleSheet(QLatin1String("background-color: rgb(14,23,52);\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgb(245, 121, 0);"));

        horizontalLayout_2->addWidget(btn_back);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 2);
        layoutWidget1 = new QWidget(Querytime);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 10, 741, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color: rgb(255, 248, 0);\n"
"font: 18pt \"Ubuntu\";"));

        horizontalLayout->addWidget(label);

        stime = new QDateTimeEdit(layoutWidget1);
        stime->setObjectName(QStringLiteral("stime"));
        sizePolicy.setHeightForWidth(stime->sizePolicy().hasHeightForWidth());
        stime->setSizePolicy(sizePolicy);
        stime->setStyleSheet(QLatin1String("background-color: rgb(32, 74, 135);\n"
"color: rgb(39, 251, 255);\n"
"font: 14pt \"Ubuntu\";"));
        stime->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        stime->setDateTime(QDateTime(QDate(2000, 1, 16), QTime(0, 0, 0)));
        stime->setCalendarPopup(false);
        stime->setCurrentSectionIndex(0);
        stime->setTimeSpec(Qt::LocalTime);

        horizontalLayout->addWidget(stime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 248, 0);\n"
"font: 18pt \"Ubuntu\";"));

        horizontalLayout->addWidget(label_2);

        etime = new QDateTimeEdit(layoutWidget1);
        etime->setObjectName(QStringLiteral("etime"));
        sizePolicy.setHeightForWidth(etime->sizePolicy().hasHeightForWidth());
        etime->setSizePolicy(sizePolicy);
        etime->setStyleSheet(QLatin1String("background-color: rgb(32, 74, 135);\n"
"color: rgb(39, 251, 255);\n"
"font: 14pt \"Ubuntu\";"));
        etime->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        etime->setCalendarPopup(false);

        horizontalLayout->addWidget(etime);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 2);

        retranslateUi(Querytime);

        QMetaObject::connectSlotsByName(Querytime);
    } // setupUi

    void retranslateUi(QWidget *Querytime)
    {
        Querytime->setWindowTitle(QApplication::translate("Querytime", "Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Querytime", "Time", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Querytime", "Temperature", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Querytime", "Humidity", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Querytime", "Ammonia", Q_NULLPTR));
        btn_query->setText(QApplication::translate("Querytime", "Query", Q_NULLPTR));
        btn_back->setText(QApplication::translate("Querytime", "Back", Q_NULLPTR));
        label->setText(QApplication::translate("Querytime", "Start time:", Q_NULLPTR));
        stime->setDisplayFormat(QApplication::translate("Querytime", "yyyy.MM.dd  AP h:mm", Q_NULLPTR));
        label_2->setText(QApplication::translate("Querytime", "End time:", Q_NULLPTR));
        etime->setDisplayFormat(QApplication::translate("Querytime", "yyyy.MM.dd AP h:mm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Querytime: public Ui_Querytime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYTIME_H
