#ifndef PATHLIST_H
#define PATHLIST_H

#include <QAbstractListModel>

class PathList : public QAbstractListModel
{
  Q_OBJECT

  private:
    QString path;

    QList<QString> m_paths;

    bool setItemAt(int index, const QString &path);

  public:

    explicit PathList(QObject *parent = nullptr);

    enum Roles {
        PathRole = Qt::DisplayRole,
    };

    Q_INVOKABLE void addPathToList(const QString &path);

    Q_INVOKABLE void removePathFromList(const int &i);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

  protected:

    QHash<int, QByteArray> roleNames() const override;
};

#endif // PATHLIST_H
