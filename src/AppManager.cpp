#include "AppManager.h"

AppManager::AppManager(QObject *parent)
  : QObject{parent}
{
}

// It is an interface to access list and remove given index
void AppManager::removePathFromListInterface(const int &index)
{
  _list.removePathFromList(index);
}

// Interface to access list and add given path
void AppManager::addPathToListInterface(const QString &path)
{
  _list.addPathToList(path);
}

// Interface to access table and clear all contents
void AppManager::clearTableInterface()
{
  _table.clearTable();
}

// get absolute path string
QString AppManager::getFileOrDirectoryPath() const
{
  return QFileDialog::getExistingDirectory(nullptr, tr("Choose Directory"), QDir::homePath(), \
                                           QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks | QFileDialog::DontUseNativeDialog);
}

// start watcher
void AppManager::startFileWatcher()
{
  connect(&_watcher, &QFileSystemWatcher::directoryChanged, this, &AppManager::directorySystemEventTriggered);

  qDebug() << "File system watcher started!";
}

// stop watcher
void AppManager::stopFileWatcher()
{
  disconnect(&_watcher, &QFileSystemWatcher::directoryChanged, this, &AppManager::directorySystemEventTriggered);

  qDebug() << "File system watcher stopped!";
}

// remove given path from entry history and watcher
void AppManager::removePathFromMap(const int &index)
{
  QString path = _list.getPathAt(index);

  _watcher.removePath(path);

  _entryHistory.remove(path);
}

// add path to watcher
void AppManager::addPathToFileWatcher(const QString &path)
{
  if(!_watcher.directories().contains(path))
  {
    _watcher.addPath(path);

    qDebug() << path << " added to file system watcher!";

    QDir dir(path);

    QStringList entryList = dir.entryList();

    _entryHistory.insert({{ path, entryList }});
  }
}

void AppManager::directorySystemEventTriggered(const QString &path)
{
  QDir dir(path);

  QStringList newEntries = dir.entryList();

  QStringList oldEntries = _entryHistory[path];

  sendEventToTable(oldEntries, newEntries, path);
}

// access tableview and add an event
void AppManager::sendEventToTable(const QStringList& oldEntries, const QStringList& newEntries, const QString &path)
{
  QVector<QString> eventStruct;

  QString eventType;
  QString absPath;
  QString isFolder;
  QString timeStamp;

  int r = newEntries.size() - oldEntries.size();

  // what is the operation
  switch(r)
  {
    case DELETED:
    {
      eventType = "Removed";
      for(int i=0; i<oldEntries.size(); i++)
      {
        if(!newEntries.contains(oldEntries[i]))
        {
          absPath = path + QDir::separator() + oldEntries[i];
        }
      }
    } break;

    case CREATED: {
      eventType = "Created";
      for(int i=0; i<newEntries.size(); i++)
      {
        if(!oldEntries.contains(newEntries[i]))
        {
          absPath = path + QDir::separator() + newEntries[i];
        }
      }
    } break;

    case CHANGED: {
      eventType = "Edited";
      for(int i=0; i<oldEntries.size(); i++)
      {
        if(!oldEntries.contains(newEntries[i]))
        {
          absPath = path + QDir::separator() + newEntries[i];
        }
      }
    } break;
  }

  // isfolder?
  QFileInfo info(absPath);

  if(info.isDir())
  {
    isFolder = "Yes";
  }
  else
  {
    isFolder = "No";
  }

  // timestamp
  QDateTime dateTime = QDateTime::currentDateTime();

  timeStamp = dateTime.toString("dd/MM/yyyy HH:mm");

  qDebug() << eventType << absPath << isFolder << timeStamp;

  // update entry history
  _entryHistory[path] = newEntries;

  eventStruct.append(eventType);
  eventStruct.append(absPath);
  eventStruct.append(isFolder);
  eventStruct.append(timeStamp);

  // insert table
  _table.addRowToTable(eventStruct);
}
