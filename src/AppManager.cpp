#include "AppManager.h"


AppManager::AppManager(QObject *parent)
  : QObject{parent}
{



}

QString AppManager::getFileOrDirectoryPath() const
{
  FileManager f;

  QStringList paths;

  if(f.exec())
  {
    paths << f.selectedFiles();
  }

  return paths[0];
}

