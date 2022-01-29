#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
}

Editor::~Editor()
{
    delete ui;
}

void Editor::on_buttonBox_accepted()
{
    m_music.setAlbum(ui->txtAlbum->text());
    m_music.setArtist(ui->txtArtist->text());
    m_music.setNotes(ui->txtNotes->text());
    m_music.setRelease(ui->dateRelease->date());

    accept();
}


void Editor::on_buttonBox_rejected()
{
    reject();
}

const Music &Editor::music() const
{
    return m_music;
}

void Editor::setMusic(const Music &newMusic)
{
    m_music = newMusic;

    ui->txtArtist->setText(m_music.artist());
    ui->txtAlbum->setText(m_music.album());
    ui->txtNotes->setText(m_music.notes());
    ui->dateRelease->setDate(m_music.release());
}

