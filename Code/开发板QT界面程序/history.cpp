#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_DeleteOnClose,0);
    setWindowTitle("History Record");
}

History::~History()
{
    delete ui;
}

void History::on_btn_back_clicked()
{
    ui->qtw->clearContents();
    emit sesignal();
    this->close();
}

void History::dbopen()
{

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE","record");
        db.setDatabaseName("/workspace/AirDataBase/AirData.db");
    }
    if (!db.open())
    {
        qDebug() << "can not open db history" << endl;
        return;
    }
    else
    {
        qDebug() << "can open db history";
    }
}

void History::dbclose()
{
    QString connection;
    connection=db.connectionName();
    db.close();
    //qDebug() << connection;
    QSqlDatabase::removeDatabase(connection);
}

void History::search(int count,int need)
{
    ui->qtw->clearContents();
    QSqlQuery query(db);
    //int count = 900;
    QDateTime now_time = QDateTime::currentDateTime();
    int nowtime = now_time.toTime_t();
    //int nowtime = 1546704267;
    //int historytime = nowtime - 6*3600;//最远历史数据
    int historytime = nowtime - need*3600;//最远历史数据
    int historynext = historytime + count - historytime%count;//最远历史时间的下一个整点
    int nownext = nowtime + count - nowtime%count - 1;//当前时间的下一个整点
    int tmp,i;
    int t1,t2;
    int row = 23;
    for(tmp=historynext; tmp<nownext; tmp=tmp+count)
    {
           query.clear();
           t1 = tmp;
           t2 = tmp + count -1;
           QString t3 = QString::number(t1);
           QString t4 = QString::number(t2);
           QString sql= "SELECT * FROM Data WHERE time BETWEEN ";
           sql.append(t3);
           sql.append(" and ");
           sql.append(t4);
           sql.append(" LIMIT 1 ");
           //qDebug() << sql;
           query.prepare(sql);
           if(!query.exec())
           {
               qDebug() << "error:" <<query.lastError();
           }
           if(query.first())
           {
                //qDebug() << "query";
                QDateTime mytime = QDateTime::fromTime_t(query.value(0).toInt());
                QLocale locale = QLocale::English;//指定英文显示
                QString strFormat = "yyyy.MM.dd ddd,hh:mm:ss ap";//指定显示时间的格式
                QString strDateTime = locale.toString(mytime, strFormat);
                ui->qtw->setItem(row,0,new QTableWidgetItem(strDateTime));
                //qDebug() << strDateTime;
                for(i = 1; i < 4; i++)
                {
                    QTableWidgetItem *myitem = new QTableWidgetItem(QString::number(query.value(i).toFloat(),'f',1));
                    myitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                    ui->qtw->setItem(row,i,myitem);
                }
           }
           row--;
    }
    query.clear();
}
void History::on_btn_si_clicked()
{
    qDebug() << "Data on the user's query for 6 hours";
    dbopen();
    search(900,6);
    dbclose();
}

void History::on_btn_tw_clicked()
{
    qDebug() << "Data on the user's query for 12 hours";
    dbopen();
    search(1800,12);
    dbclose();
}

void History::on_btn_tt_clicked()
{
    qDebug() << "Data on the user's query for 24 hours";
    dbopen();
    search(3600,24);
    dbclose();
}

void History::on_btn_qte_clicked()
{
    this->close();
    connect(&qte,SIGNAL(qtsend()),this,SLOT(reshow()));
    qte.show();
    qDebug() << "User uses the selection of query on time!";
}

void History::reshow()
{
    this->show();
}
