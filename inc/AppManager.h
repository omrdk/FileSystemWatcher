#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QFileSystemWatcher>

#include "FileManager.h"
#include "PathListModel.h"
#include "EventTableModel.h"

class AppManager : public QObject
{
    Q_OBJECT

  private:
    PathList    _list;
    EventTable _table;

    QFileSystemWatcher watcher;

    QMap<QString, QStringList> entryHistory;

    void fileSystemEventTriggered(const QString &path);

    void directorySystemEventTriggered(const QString &path);

    void sendEventToTable(const QStringList &oldEntries, const QStringList &newEntries, QString path);

  public:
    explicit AppManager(QObject *parent = nullptr);

    inline PathList *getPathList() {
      return &_list;
    }
    inline EventTable *getEventTable() {
      return &_table;
    }

    Q_INVOKABLE QString getFileOrDirectoryPath() const;

    Q_INVOKABLE void addPathToFileWatcher(const QString &path);

    Q_INVOKABLE void startFileWatcher();

    Q_INVOKABLE void stopFileWatcher();

  signals:

};

#endif // APPMANAGER_H
