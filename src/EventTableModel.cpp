#include "EventTableModel.h"

EventTable::EventTable(QObject *parent)
  : QAbstractTableModel(parent)
{
   m_table.append(header);
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
  return 4;
}

QVariant EventTable::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
  {
    return QVariant();
  }

  switch (role)
  {
    case DataRole:
    {
        return m_table.at(index.row()).at(index.column());
    }

    case HeadingRole:
    {
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

void EventTable::addRowToTable(const QVector<QString>& data)
{
  beginInsertRows(QModelIndex(), m_table.size(), m_table.size() + 1);

  m_table.append(data);

  endInsertRows();
}

void EventTable::clearTable()
{
  beginResetModel();

  m_table.clear();

  endResetModel();

  addRowToTable(header);
}
