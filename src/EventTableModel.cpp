#include "EventTableModel.h"

EventTable::EventTable(QObject *parent)
  : QAbstractTableModel(parent)
{
}

QVariant EventTable::headerData(int section, Qt::Orientation orientation, int role) const
{
  // FIXME: Implement me!
}

int EventTable::rowCount(const QModelIndex &parent) const
{
  if (parent.isValid())
    return 0;

  // FIXME: Implement me!
}

int EventTable::columnCount(const QModelIndex &parent) const
{
  if (parent.isValid())
    return 0;

  // FIXME: Implement me!
}

bool EventTable::hasChildren(const QModelIndex &parent) const
{
  // FIXME: Implement me!
}

bool EventTable::canFetchMore(const QModelIndex &parent) const
{
  // FIXME: Implement me!
  return false;
}

void EventTable::fetchMore(const QModelIndex &parent)
{
  // FIXME: Implement me!
}

QVariant EventTable::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  // FIXME: Implement me!
  return QVariant();
}

bool EventTable::insertRows(int row, int count, const QModelIndex &parent)
{
  beginInsertRows(parent, row, row + count - 1);
  // FIXME: Implement me!
  endInsertRows();
  return true;
}

bool EventTable::insertColumns(int column, int count, const QModelIndex &parent)
{
  beginInsertColumns(parent, column, column + count - 1);
  // FIXME: Implement me!
  endInsertColumns();
  return true;
}

bool EventTable::removeRows(int row, int count, const QModelIndex &parent)
{
  beginRemoveRows(parent, row, row + count - 1);
  // FIXME: Implement me!
  endRemoveRows();
  return true;
}

bool EventTable::removeColumns(int column, int count, const QModelIndex &parent)
{
  beginRemoveColumns(parent, column, column + count - 1);
  // FIXME: Implement me!
  endRemoveColumns();
  return true;
}
