#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton("Edit", this);
    ui->buttonBox->addButton(button, QDialogButtonBox::ButtonRole::ActionRole);
    connect(button, &QPushButton::clicked, this, &Dialog::on_edit);

    m_music.setArtist("Coldplay");
    m_music.setAlbum("don't panic");
    m_music.setRelease(QDate(2001,3,19));
    m_music.setNotes("panic");

    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::on_edit()
{
    Editor* dlg = new Editor(this);
    dlg->setMusic(m_music);
    dlg->exec();

    m_music = dlg->music();
    load();
    delete dlg;
}

void Dialog::load()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setReadOnly(true);

    QString data;
    data.append("Artist: " + m_music.artist() +"\r\n");
    data.append("Album: " + m_music.album() +"\r\n");
    data.append("Release: " + m_music.release().toString() +"\r\n");
    data.append("Notes: " + m_music.notes() +"\r\n");

    ui->plainTextEdit->setPlainText(data);
}

