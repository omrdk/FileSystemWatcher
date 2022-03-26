#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>

#include "FileManager.h"
#include "PathListModel.h"
#include "EventTableModel.h"



class AppManager : public QObject
{
    Q_OBJECT

  private:
    PathList    _list;
    EventTable _table;

  public:
    explicit AppManager(QObject *parent = nullptr);

    inline PathList *getPathList() {
      return &_list;
    }
    inline EventTable *getEventTable() {
      return &_table;
    }

    Q_INVOKABLE QString getFileOrDirectoryPath() const;


  signals:

};

#endif // APPMANAGER_H
