#include "querytime.h"
#include "ui_querytime.h"

Querytime::Querytime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Querytime)
{
    ui->setupUi(this);
    setWindowTitle("Query on time");
    setAttribute(Qt::WA_StyledBackground);
    QDateTime nowtime = QDateTime::currentDateTime();
    int valtime = nowtime.toTime_t();
    valtime = valtime - 999;//默认查1000条
    QDateTime vtime = QDateTime::fromTime_t(valtime);
    ui->stime->setDateTime(vtime);
    ui->etime->setDateTime(nowtime);
}

Querytime::~Querytime()
{
    delete ui;
}

void Querytime::dbopen()
{

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE","querytime");
        db.setDatabaseName("/workspace/AirDataBase/AirData.db");
    }
    if (!db.open())
    {
        qDebug() << "can not open db history" << endl;
        return;
    }
    else
    {
        qDebug() << "can open db his";
    }
}

void Querytime::dbclose()
{
    QString connection;
    connection=db.connectionName();
    db.close();
    //qDebug() << connection;
    QSqlDatabase::removeDatabase(connection);
}

void Querytime::on_btn_back_clicked()
{
    emit qtsend();
    ui->tableWidget->clearContents();
    this->close();
}

void Querytime::on_btn_query_clicked()
{
    dbopen();
    ui->tableWidget->clearContents();
    QDateTime starttime = ui->stime->dateTime();
    QDateTime endtime = ui->etime->dateTime();
    int st = starttime.toTime_t();
    int et = endtime.toTime_t();
    QSqlQuery query(db);
    QString t1 = QString::number(st);
    QString t2 = QString::number(et);
    QString sql = "SELECT * FROM Data WHERE time BETWEEN ";
    sql.append(t1);
    sql.append(" and ");
    sql.append(t2);
    query.prepare(sql);
    if(!query.exec())
    {
        qDebug() << "error:" <<query.lastError();
    }
    int initialPos = query.at();
    int pos = 0;
    if (query.last())
    {
        pos = query.at() + 1;
    }
    else
    {
        pos = 0;
    }
    query.seek(initialPos);
    ui->tableWidget->setRowCount(pos);
    pos = pos - 1;
    int i;
    while(query.next())
    {
        QDateTime mytime = QDateTime::fromTime_t(query.value(0).toInt());
        QLocale locale = QLocale::English;//指定英文显示
        QString strFormat = "yyyy.MM.dd ddd,hh:mm:ss ap";//指定显示时间的格式
        QString strDateTime = locale.toString(mytime, strFormat);
        ui->tableWidget->setItem(pos,0,new QTableWidgetItem(strDateTime));
        for(i = 1; i < 4; i++)
        {
            QTableWidgetItem *myitem = new QTableWidgetItem(QString::number(query.value(i).toFloat(),'f',1));
            myitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setItem(pos,i,myitem);
        }
        --pos;
    }
    dbclose();
}
