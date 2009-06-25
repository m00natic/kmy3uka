#ifndef MY3UKA_H
#define MY3UKA_H

#include <QtGui/QDialog>
#include <QFileInfo>
#include <QMap>

namespace Ui
{
    class my3ukaClass;
}

class my3uka : public QDialog
{
    Q_OBJECT

public:
    my3uka(QWidget *parent = 0);
    ~my3uka();

private:
    Ui::my3ukaClass *ui;

private slots:
    void on_btnGenerateAll_clicked();
    void on_btnGenerate_clicked();
    void on_btnBrowseFolder_clicked();
    void on_btnBrowseFile_clicked();

private:
    QMap<QString, QMap<QString, int> > artistTree;
    QStringList extsList;
    QStringList foldersList;
    void readSettings(QString);
    bool traverseDir(QString);
    void traverseArtists(QFileInfo);
    int traverseAlbum(QFileInfo);
    void writeTree(QString);
    int getArtistCount(QMap<QString, int>);
    void doSettings();
};

#endif // MY3UKA_H
