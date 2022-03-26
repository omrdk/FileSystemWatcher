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

  return m_paths.count();
}

QVariant PathList::data(const QModelIndex &index, int role) const
{
  if (index.row() < 0 || index.row() >= m_paths.count())
  {
    return QVariant();
  }

  const Content content = m_paths[index.row()];

  if (role == PathRole)
  {
    return content.path;
  }

  return QVariant();
}

void PathList::addPathToList(const QString &path)
{
  int rowIndex = rowCount();

  beginInsertRows(QModelIndex(), rowIndex, rowIndex);

  Content content;

  content.path = path;

  m_paths.append(content);

  endInsertRows();
}

void PathList::removePathFromList(const int &i)
{
  beginRemoveRows(QModelIndex(), i, i);

  m_paths.removeAt(i);

  endRemoveRows();
}

QVariant PathList::headerData(int section, Qt::Orientation orientation, int role) const
{
  // FIXME: Implement me!
}



