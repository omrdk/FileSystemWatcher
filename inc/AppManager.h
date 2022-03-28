#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QDateTime>
#include <QFileSystemWatcher>

#include "FileManager.h"
#include "PathListModel.h"
#include "EventTableModel.h"

#define CREATED  1
#define DELETED -1
#define CHANGED  0

class AppManager : public QObject
{
    Q_OBJECT

  private:
    PathList    _list;

    EventTable _table;

    QFileSystemWatcher watcher;

    QMap<QString, QStringList> _entryHistory;

    void directorySystemEventTriggered(const QString &path);

    void sendEventToTable(const QStringList &oldEntries, const QStringList &newEntries, const QString &path);

  public:
    explicit AppManager(QObject *parent = nullptr);

    Q_INVOKABLE void startFileWatcher();

    Q_INVOKABLE void stopFileWatcher();

    Q_INVOKABLE void addPathToFileWatcher(const QString &path);

    Q_INVOKABLE QString getFileOrDirectoryPath() const;

    Q_INVOKABLE void removePathFromMap(const int &index);

    Q_INVOKABLE void removePathFromListInterface(const int& index);

    Q_INVOKABLE void addPathToListInterface(const QString& path);

    Q_INVOKABLE void clearTableInterface();

    inline PathList *getPathList() {
      return &_list;
    }
    inline EventTable *getEventTable() {
      return &_table;
    }

};

#endif // APPMANAGER_H
