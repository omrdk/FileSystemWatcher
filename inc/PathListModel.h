#ifndef PATHLIST_H
#define PATHLIST_H

#include <QAbstractListModel>

struct Content {
  QString path;
  //...
};

class PathList : public QAbstractListModel
{
  Q_OBJECT

  private:
    QList<Content> m_paths;

  public:
    explicit PathList(QObject *parent = nullptr);

    enum Roles {
        PathRole = Qt::UserRole + 1
    };

    Q_INVOKABLE void addPathToList(const QString &path);

    Q_INVOKABLE void removePathFromList(const int &i);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

  protected:
    QHash<int, QByteArray> roleNames() const;
};

#endif // PATHLIST_H
