#include <QtGui/QDialog>
#include <QFileInfo>
#include <QMap>
#include <QFileDialog>
#include <QTextStream>
//#include <QMessageBox>

#include "my3uka.h"
#include "ui_my3uka.h"

my3uka::my3uka(QWidget *parent)
    : QDialog(parent), ui(new Ui::my3ukaClass)
{
    ui->setupUi(this);
    ui->progressBar->setVisible(false);

    doSettings();
}

my3uka::~my3uka()
{
    delete ui;
}

void my3uka::doSettings()
{
    //extsList<<"*.mp3"<<"*.ogg"<<"*.mp4"<<"*.wma"<<"*.wv"<<"*.wav";
    //extsList<<"*.wave"<<"*.mid"<<"*.midi"<<"*.m4a"<<"*.flac"<<"*.ape";

    readSettings("extensions.ini");
    readSettings("folders.ini");

    ui->txtFile->setText("./my3uka.txt");
}

void my3uka::on_btnBrowseFile_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,
                                   tr("Locate File"), ".");
    if(!file.isEmpty()) ui->txtFile->setText(file);
}

void my3uka::on_btnBrowseFolder_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this,
                                   tr("Locate Music Folder"), ".");
    if(!folder.isEmpty())
    {
        int index = ui->cmbFolder->findText(folder);
        if(index ==-1)
        {
            ui->cmbFolder->addItem(folder, folder);
            index = ui->cmbFolder->findText(folder);
        }

        ui->cmbFolder->setCurrentIndex(index);
    }
}

void my3uka::readSettings(QString settingFile)
{
    QFile file(settingFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
/*        QMessageBox::warning(this, tr("my3uka"),
                             tr("Can not read %1:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString())); */
        return;
    }

    QString setting;

    QTextStream in(&file);

    if(settingFile =="extensions.ini")
    {
        while(!in.atEnd())
        {
            setting = in.readLine();
            if(!setting.isEmpty() && !extsList.contains("*." + setting,Qt::CaseInsensitive))
                extsList<<"*." + setting;
        }
    }
    else
    {
        while(!in.atEnd())
        {
            setting = in.readLine();
            if(!setting.isEmpty() && !foldersList.contains(setting,Qt::CaseInsensitive))
            {
                foldersList.append(setting);
                ui->cmbFolder->addItem(setting, setting);
            }
        }
    }
}

void my3uka::on_btnGenerate_clicked()
{
    if(!ui->cmbFolder->currentText().isEmpty())
        traverseDir(ui->cmbFolder->currentText());
}

void my3uka::on_btnGenerateAll_clicked()
{
    if(foldersList.count() >0)
    {
        foreach(QString musicFolder, foldersList)
        {
            if(!musicFolder.isEmpty())
            {
                ui->cmbFolder->setCurrentIndex(ui->cmbFolder->findText(musicFolder));
                traverseDir(musicFolder);
            }
        }
        return;
    }

    for(int i=0; i<ui->cmbFolder->count(); ++i)
    {
        if(!ui->cmbFolder->itemText(i).isEmpty())
        {
            ui->cmbFolder->setCurrentIndex(ui->cmbFolder->findText(ui->cmbFolder->itemText(i)));
            traverseDir(ui->cmbFolder->itemText(i));
        }
    }
}

bool my3uka::traverseDir(QString musicFolder)
{
    artistTree.clear();

    //  populate artistTree
    QDir musicDir(musicFolder);
    if(!musicDir.exists())
    {
        //QMessageBox::warning(this,tr("my3uka"),tr("Invalid Folder: ") + musicFolder);
        foldersList.removeAll(musicFolder);
        ui->cmbFolder->removeItem(ui->cmbFolder->findText(musicFolder));
        ui->progressBar->setVisible(false);
        return false;
    }

    QFileInfoList fileList = musicDir.entryInfoList(QDir::AllDirs);

    ui->progressBar->reset();
    ui->progressBar->setRange(0, (fileList.count() - 2)*3 - 1);
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(true);

    foreach(QFileInfo fi, fileList)
    {
        if (fi.isDir() && fi.fileName()!= "." && fi.fileName() != "..")
        {
            traverseArtists(fi);
            ui->progressBar->setValue(ui->progressBar->value() + 2);
        }
    }

    writeTree(musicDir.dirName());

    artistTree.clear();

    if(!foldersList.contains(musicFolder,Qt::CaseInsensitive))
    {
        QFile file("./folders.ini");
        if (!file.open(QIODevice::Append | QIODevice::Text))
        {
/*            QMessageBox::warning(this, tr("my3uka"),
                             tr("Can not write %1:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString())); */
            return false;
        }

        QTextStream out(&file);
        out<<"\n"<<musicFolder;

        foldersList.append(musicFolder);
    }

    ui->progressBar->setVisible(false);
    return true;
}

void my3uka::traverseArtists(QFileInfo fi)
{
    QMap<QString, int> albums;
    QDir artistDir(fi.absoluteFilePath());

    QStringList noalbum = artistDir.entryList(extsList, QDir::Files);
    if(noalbum.count() >0)
        albums.insert("unspecified", noalbum.count());

    QFileInfoList albumList = artistDir.entryInfoList(QDir::AllDirs);
    foreach(QFileInfo album, albumList)
    {
        if (album.isDir() && album.fileName()!= "." && album.fileName() != "..")
            albums.insert(album.fileName(), traverseAlbum(album));
    }

    artistTree.insert(fi.fileName(), albums);
}

int my3uka::traverseAlbum(QFileInfo fi)
{
    int musicFiles = 0;

    QDir albumDir(fi.absoluteFilePath());

    musicFiles = albumDir.entryList(extsList, QDir::Files).count();

    QFileInfoList albumSubs = albumDir.entryInfoList(QDir::AllDirs);
    foreach(QFileInfo subdir, albumSubs)
    {
        if (subdir.isDir() && subdir.fileName()!= "." && subdir.fileName() != "..")
            musicFiles += traverseAlbum(subdir);
    }

    return musicFiles;
}

void my3uka::writeTree(QString rootName)
{
    QFile file(ui->txtFile->text());
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
/*        QMessageBox::warning(this, tr("my3uka"),
                             tr("Can not write %1:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString())); */
        return;
    }

    QTextStream out(&file);

    out<<"\n*****************************************************************\n";
    out<<"***  "<<rootName<<"  ***\n";
    out<<"*****************************************************************\n\n";

    foreach(QString artist, artistTree.keys())
        out<<"	-	"<<artist<<"\n";

    out<<"\n";
    out<<"*****************************************************************\n\n";

    foreach(QString artist, artistTree.keys())
    {
        //out<<artist<<" ["<<QVariant::fromValue(getArtistCount(artistTree.value(artist))).toString()<<"]\n";
        out<<artist<<" ["<<QString::number(getArtistCount(artistTree.value(artist)))<<"]\n";

        foreach(QString album, artistTree.value(artist).keys())
            if(album !="unspecified")
                out<<"			-	"<<album<<"	("<<QString::number(artistTree.value(artist).value(album))<<")\n";

        out<<"\n*****************************************************************\n\n";

        ui->progressBar->setValue(ui->progressBar->value() + 1);
    }

    out<<"*****************************************************************\n";
    out<<"***  That's all in "<<rootName<<"  ***\n";
    out<<"*****************************************************************\n\n";
    out<<"------------------------------------------------------------------------------------------\n";
}

int my3uka::getArtistCount(QMap<QString, int> albumTree)
{
    int returnCount = 0;

    foreach(int count, albumTree.values())
        returnCount += count;

    return returnCount;
}
