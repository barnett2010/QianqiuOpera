#ifndef QOBJECTLISTMODEL_H
#define QOBJECTLISTMODEL_H

#include <QAbstractListModel>

class QObjectListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int itemCount READ itemCount NOTIFY itemCountChanged)

public:
    explicit QObjectListModel(QObject *parent = 0, QList<QObject*> *list = new QList<QObject*>());

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int itemCount() const;

    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    void addItem(QObject *item);
    void insertItem(int index, QObject *item);
    void removeItem(QObject *item);
    void removeItem(int index);
    void reset();
    void move(int oldRow, int newRow);
    QObject * get(int index);
    int indexOf(QObject *obj) const;
    QObject * findItem(const char *propertyName, const QVariant &value);

    //! modify
    QObject * takeItemAt(int index);
    //! --

    template<typename T>
    QList<T*> *getList();
    QList<QObject*> *getList();

    template<typename T>
    void setList(QList<T*> *list);
    void setList(QList<QObject*> *list);

    //! modify
    virtual QHash<int, QByteArray>	roleNames() const;
    //! --

    void refreshModel();

private slots:
    void removeDestroyedItem();

signals:
    void itemAdded(QObject *item);
    void itemCountChanged();

private:
    QList<QObject*> *_list;
    //! modify
    QHash<int, QByteArray> _roleNames;
};

template<typename T>
QList<T*> *QObjectListModel::getList()
{
    return reinterpret_cast<QList<T *> *>(_list);
}

template<typename T>
void QObjectListModel::setList(QList<T*> *list)
{
    setList(reinterpret_cast<QList<QObject *> *>(list));
}

#endif // QOBJECTLISTMODEL_H
