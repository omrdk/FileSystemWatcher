#include "AppManager.h"

#include <QDateTime>

AppManager::AppManager(QObject *parent)
  : QObject{parent}
{

}

QString AppManager::getFileOrDirectoryPath() const
{
  //FileManager f;

  //QStringList paths;

  //if(f.exec())
  //{
  //  paths << f.selectedFiles();

  //  return paths[0];
  //}
  //return "";
  return QFileDialog::getExistingDirectory(nullptr, tr("Choose Directory"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}

void AppManager::startFileWatcher()
{
  connect(&watcher, &QFileSystemWatcher::directoryChanged, this, &AppManager::directorySystemEventTriggered);
  //connect(&watcher, &QFileSystemWatcher::fileChanged, this, &AppManager::fileSystemEventTriggered);

  qDebug() << "File watcher started!";
}

void AppManager::stopFileWatcher()
{
  disconnect(&watcher, &QFileSystemWatcher::directoryChanged, this, &AppManager::directorySystemEventTriggered);
  //disconnect(&watcher, &QFileSystemWatcher::fileChanged, this, &AppManager::fileSystemEventTriggered);

  qDebug() << "File watcher stopped!";
}

void AppManager::addPathToFileWatcher(const QString &path)
{
  watcher.addPath(path);

  qDebug() << path << " added to file watcher!";

  // add path content to history in order to track changes later

  QDir dir(path);

  QStringList entryList = dir.entryList();

  entryHistory.insert({{ path, entryList }});

  qDebug() << path << "\n" << entryHistory[path] << "\n" << entryHistory[path].size();

  qDebug() << entryHistory.size();

}

void AppManager::fileSystemEventTriggered(const QString &path)
{
  qDebug() << "File system event: " << path;
}

void AppManager::directorySystemEventTriggered(const QString &path)
{
  qDebug() << "Directory system event: " << path;

  QDir dir(path);

  QStringList newEntries = dir.entryList();

  QStringList oldEntries = entryHistory[path];

  sendEventToTable(oldEntries, newEntries, path);

  //qDebug() << result;


}

void AppManager::sendEventToTable(const QStringList& oldEntries, const QStringList& newEntries, QString path)
{
  QVector<QString> eventStruct;

  QString eventType;
  QString isFolder;
  QString timeStamp;

  if(newEntries.size() < oldEntries.size())
  {
    for(int i=0; i<newEntries.size(); i++)
    {
      if(!newEntries.contains(oldEntries[i]))
      {
        eventType = "Removed";
        path = path + QDir::separator() + oldEntries[i];
      }
    }
  }

  else if(newEntries.size() > oldEntries.size())
  {
    for(int i=0; i<newEntries.size(); i++)
    {
      if(!oldEntries.contains(newEntries[i]))
      {
        eventType = "Created";
        path = path + QDir::separator() + newEntries[i];
      }
    }
  }

  else
  {
    for(int i=0; i<oldEntries.size(); i++)
    {
      if(!oldEntries.contains(newEntries[i]))
      {
        eventType = "Edited";
        path = path + QDir::separator() + newEntries[i];
      }
    }
  }

  // something wrong above

  QFileInfo info(path);

  isFolder = "No";
  if(info.isDir())
  {
    isFolder = "Yes";
  }

  QDateTime dateTime = QDateTime::currentDateTime();

  timeStamp = dateTime.toString("dd/MM/yyyy HH:mm");

  qDebug() << eventType << path << isFolder << timeStamp;

  // update related entry
  entryHistory[path] = newEntries;

  eventStruct.append(eventType);
  eventStruct.append(path);
  eventStruct.append(isFolder);
  eventStruct.append(timeStamp);

  // insert table

  //return event;
}

