#include "EventTableModel.h"

EventTable::EventTable(QObject *parent)
  : QAbstractTableModel(parent)
{
   m_table.append( { "Event type", "Path", "Is folder", "Timestamp" } );
}

int EventTable::rowCount(const QModelIndex &parent) const
{
  if (parent.isValid())
  {
    return 0;
  }

  return m_table.size();
}

int EventTable::columnCount(const QModelIndex &parent) const
{
  if (parent.isValid())
  {
    return 0;
  }

  return m_table.at(0).size();
}


QVariant EventTable::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  switch (role) {
  case DataRole: {
      return m_table.at(index.row()).at(index.column());
  }
  case HeadingRole: {
      return index.row() == 0;
  }
  default: break;
  }
  return QVariant();
}

QHash<int, QByteArray> EventTable::roleNames() const
{
  return { { DataRole,    "display" },
           { HeadingRole, "heading" }
  };
}


//bool EventTable::insertRows(int row, int count, const QModelIndex &parent)
//{
//  beginInsertRows(parent, row, row + count - 1);
//  // FIXME: Implement me!
//  endInsertRows();
//  return true;
//}

//bool EventTable::insertColumns(int column, int count, const QModelIndex &parent)
//{
//  beginInsertColumns(parent, column, column + count - 1);
//  // FIXME: Implement me!
//  endInsertColumns();
//  return true;
//}

//bool EventTable::removeRows(int row, int count, const QModelIndex &parent)
//{
//  beginRemoveRows(parent, row, row + count - 1);
//  // FIXME: Implement me!
//  endRemoveRows();
//  return true;
//}

//bool EventTable::removeColumns(int column, int count, const QModelIndex &parent)
//{
//  beginRemoveColumns(parent, column, column + count - 1);
//  // FIXME: Implement me!
//  endRemoveColumns();
//  return true;
//}
