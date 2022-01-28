#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPushButton* btnStart = new QPushButton("start", this);
    QPushButton* btnStop= new QPushButton("stop", this);

    ui->buttonBox->addButton(btnStart, QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnStop, QDialogButtonBox::ButtonRole::ActionRole);

    connect(btnStart, &QPushButton::clicked, this , &Dialog::start);
    connect(btnStop, &QPushButton::clicked, this , &Dialog::stop);

    m_timer.setInterval(100);
    connect(&m_timer, &QTimer::timeout, this, &Dialog::timeout);

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    accept();
}

void Dialog::timeout()
{
    qDebug() << QTime::currentTime().toString();

    m_stopped = QTime::currentTime();

    qint64 time = m_started.msecsTo(m_stopped);
    qint64 hour= time / 1000 / 60 /60;
    qint64 min = (time /1000 / 60) - hour * 60;
    qint64 sec = time / 1000 - min * 60;
    qint64 msec = time - (sec + ((min + (hour * 60)) * 60 ) ) * 1000;

    const QString diff = QString("%1:%2:%3:%4")
            .arg(hour,2,10,QChar('0'))
            .arg(min,2,10,QChar('0'))
            .arg(sec,2,10,QChar('0'))
            .arg(msec,2,10,QChar('0'));

    ui->label->setText(diff);
}

void Dialog::start()
{
    m_started = QTime::currentTime();
    m_stopped = QTime::currentTime();
     qDebug() << "Starting";
    m_timer.start();
}

void Dialog::stop()
{
    m_timer.stop();
     qDebug() <<" Stopped";
}

