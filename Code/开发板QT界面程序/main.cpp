#include "mainwindow.h"
#include <QApplication>
#include "frminput.h"
#include "ui_frminput.h"
#include "login.h"
#include "ui_login.h"
#include <QCoreApplication>
#include <QFile>
#include <QDateTime>
#include <QThread>
#include <QDebug>
QString nowname = "NULL";

void MessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QString strMsg("");
    switch(type)
    {
    case QtDebugMsg:
        strMsg = QString("Debug:");
        break;
    case QtWarningMsg:
        strMsg = QString("Warning:");
        break;
    case QtCriticalMsg:
        strMsg = QString("Critical:");
        break;
    case QtFatalMsg:
        strMsg = QString("Fatal:");
        break;
    }

    // 设置输出信息格式
    QLocale locale = QLocale::English;//指定英文显示
    QString strDateTime = locale.toString(QDateTime::currentDateTime(),"yyyy-MM-dd hh:mm:ss ddd");
    QString strMessage = strMsg + QString("File:%1  Line:%2  Function:%3  Message:%4  DateTime:%5").arg(context.file).arg(context.line).arg(context.function).arg(localMsg.constData()).arg(strDateTime);

    // 加锁
    static QMutex mutex;
    mutex.lock();
    // 循环写日志
    QFile file1("/workspace/qtlog.txt");
    QFile file2("/workspace/qtlog1.txt");
    file1.open(QIODevice::WriteOnly | QIODevice::Append);
    if(file1.size() >= 20000000 )
    {
       file1.close();
       file2.remove();
       QFile::copy("/workspace/qtlog.txt","/workspace/qtlog1.txt");
       file1.remove();

       QFile file3("/workspace/qtlog.txt");
       file3.open(QIODevice::WriteOnly | QIODevice::Append);
       QTextStream stream(&file3);
       stream << strMessage << endl;
    }
    else
    {
        QTextStream stream(&file1);
        stream << strMessage << endl;
    }
    // 解锁
    mutex.unlock();
}

int main(int argc, char *argv[])
{
    //安装日志系统
    qInstallMessageHandler(MessageOutput);
    QApplication a(argc, argv);
    qApp->setFont(QFont("Microsoft YaHei", 10));
     //qApp->setFont(QFont("WenQuanYi Micro Hei", 15));
     //在main函数中就加载输入法面板,保证整个应用程序可以使用输入法
    //以下方法打开中文输入法
     //frmInput::Instance()->Init("control", "black", 10, 10);
    //以下方法打开数字键盘
    //frmNum::Instance()->Init("lightgray",10);//lightgray--浅灰色
    frmInput::Instance()->Init("control", "lightgray", 10, 10);
    MainWindow w;
    w.show();
    return a.exec();
}
