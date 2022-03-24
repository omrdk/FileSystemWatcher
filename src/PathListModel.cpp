#include "PathListModel.h"

PathList::PathList(QObject *parent)
  : QAbstractListModel(parent)
{
}

QVariant PathList::headerData(int section, Qt::Orientation orientation, int role) const
{
  // FIXME: Implement me!
}

int PathList::rowCount(const QModelIndex &parent) const
{
  // For list models only the root node (an invalid parent) should return the list's size. For all
  // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
  if (parent.isValid())
    return 0;

  // FIXME: Implement me!
}

bool PathList::hasChildren(const QModelIndex &parent) const
{
  // FIXME: Implement me!
}

bool PathList::canFetchMore(const QModelIndex &parent) const
{
  // FIXME: Implement me!
  return false;
}

void PathList::fetchMore(const QModelIndex &parent)
{
  // FIXME: Implement me!
}

QVariant PathList::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  // FIXME: Implement me!
  return QVariant();
}

bool PathList::insertRows(int row, int count, const QModelIndex &parent)
{
  beginInsertRows(parent, row, row + count - 1);
  // FIXME: Implement me!
  endInsertRows();
  return true;
}

bool PathList::removeRows(int row, int count, const QModelIndex &parent)
{
  beginRemoveRows(parent, row, row + count - 1);
  // FIXME: Implement me!
  endRemoveRows();
  return true;
}
