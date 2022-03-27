#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QFileDialog>

#include <QEvent>
#include <QListView>
#include <QTreeView>
#include <QPushButton>

class FileManager : public QFileDialog{
  Q_OBJECT
  private:

    QListView *m_listView  = 0;
    QTreeView *m_treeView  = 0;
    QPushButton *m_btnOpen = 0;

    QStringList m_selectedFiles;

  public:

    FileManager();

    QStringList selectedFiles();

    bool eventFilter(QObject* watched, QEvent* event);

  public slots:

    void chooseClicked();

};



#endif // FILEMANAGER_H
