#ifndef EVENTTABLE_H
#define EVENTTABLE_H

#include <QAbstractTableModel>

class EventTable : public QAbstractTableModel
{
    Q_OBJECT

  public:

    explicit EventTable(QObject *parent = nullptr);

    enum TableRoles
    {
      DataRole = Qt::UserRole + 1,
      HeadingRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    void addRowToTable(const QVector<QString> &data);

    void clearTable();

  private:

    QVector<QVector<QString>> m_table;

    QVector<QString> header = { "Event type", "Path", "Is folder", "Timestamp" };
};

#endif // EVENTTABLE_H
