#include "PathListModel.h"

PathList::PathList(QObject *parent)
  : QAbstractListModel(parent)
{
}

QHash<int, QByteArray> PathList::roleNames() const
{
  return { { PathRole, "path" },
             //...
  };
}

int PathList::rowCount(const QModelIndex &parent) const
{
  Q_UNUSED(parent);

  if(parent.isValid())
  {
    return 0;
  }

  return m_paths.count();
}

QVariant PathList::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
  {
    return QVariant();
  }

  const QString path = m_paths.at(index.row());

  switch (role) {
    case PathRole: return path;
  }

  return QVariant();
}

bool PathList::setData(const QModelIndex &index, const QVariant &value, int role)
{
  if(!index.isValid())
  {
    return 0;
  }

  QString path = m_paths.at(index.row());
  switch (role) {
  case PathRole:
    path = value.toString(); break;
  }

  if(setItemAt(index.row(), path))
  {
    qDebug() << "Path changed!";
    emit dataChanged(index, index, QList<int>() << role);
    return true;
  }
  return false;
}

Qt::ItemFlags PathList::flags(const QModelIndex &index) const
{
  if(!index.isValid())
  {
    return Qt::NoItemFlags;
  }
  return Qt::ItemIsEditable;
}

QString PathList::getPathAt(const int &index)
{
  return m_paths[index];
}

void PathList::addPathToList(const QString &path)
{
  if(!m_paths.contains(path))
  {
    int rowIndex = rowCount();

    beginInsertRows(QModelIndex(), rowIndex, rowIndex);

    m_paths.append(path);

    endInsertRows();

    qDebug() << path << " added to listview!";
  }
}

void PathList::removePathFromList(const int &i)
{
  beginRemoveRows(QModelIndex(), i, i);

  m_paths.removeAt(i);

  endRemoveRows();

  qDebug() << "Path removed!";
}

bool PathList::setItemAt(int index, const QString &path)
{
  if(index < 0 || index >= m_paths.size() )
  {
    return false;
  }

  const QString &old_path = m_paths.at(index);

  if(path == old_path)
  {
    return false;
  }

  m_paths[index] = path;

  return true;
}
