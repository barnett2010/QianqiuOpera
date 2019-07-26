#include "qobjectlistmodel.h"
#include <QDebug>

QObjectListModel::QObjectListModel(QObject *parent, QList<QObject*> *list)
    : QAbstractListModel(parent),
      _list(list)
{
    //! modify
//    QHash<int, QByteArray> roles;
//    roles[Qt::UserRole + 1] = "object";
//    setRoleNames(roles);
    //! --
    _roleNames[Qt::UserRole + 1] = "object";
}

int QObjectListModel::indexOf(QObject *obj) const
{
    return _list->indexOf(obj);
}

int QObjectListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _list->count();
}

int QObjectListModel::itemCount() const
{
    return _list->count();
}

int QObjectListModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant QObjectListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _list->count())
        return QVariant();

    if (role == Qt::UserRole + 1) {
        QObject *obj = _list->at(index.row());
        return QVariant::fromValue(obj);
    }

    return QVariant(0);
}

bool QObjectListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() >= _list->count())
        return false;

    if (role == Qt::UserRole + 1) {
        _list->replace(index.row(), reinterpret_cast<QObject*>(value.toInt()));
        return true;
    }

    return false;
}

void QObjectListModel::insertItem(int index, QObject *item)
{
    beginInsertRows(QModelIndex(), index, index);
    _list->insert(index, item);
    connect(item, SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
    endInsertRows();

    emit itemAdded(item);
    emit itemCountChanged();
}

void QObjectListModel::addItem(QObject *item)
{
    insertItem(_list->count(), item);
}

void QObjectListModel::removeDestroyedItem()
{
    QObject *obj = QObject::sender();
    removeItem(obj);
}

void QObjectListModel::removeItem(QObject *item)
{
    int index = _list->indexOf(item);
    if (index >= 0) {
        beginRemoveRows(QModelIndex(), index, index);
        _list->removeAt(index);
        disconnect(item, SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
        endRemoveRows();
        emit itemCountChanged();
    }
}

//! modify
QObject * QObjectListModel::takeItemAt(int index)
{
    if(index >= _list->count() || index < 0) {
        return 0;
    }

    beginRemoveRows(QModelIndex(), index, index);
    disconnect(((QObject*)_list->at(index)), SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
    QObject * item = _list->takeAt(index);
    endRemoveRows();
    emit itemCountChanged();

    return item;
}
//! --

void QObjectListModel::removeItem(int index)
{
    if(index >= _list->count() || index < 0) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    disconnect(((QObject*)_list->at(index)), SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
    _list->removeAt(index);
    endRemoveRows();
    emit itemCountChanged();
}

QObject* QObjectListModel::get(int index)
{
    if (index >= _list->count() || index < 0)
        return 0;

    return _list->at(index);
}

QList<QObject*> *QObjectListModel::getList()
{
    return _list;
}

void QObjectListModel::setList(QList<QObject *> *list)
{
    QList<QObject *> *oldList = _list;
    beginResetModel();
    _list = list;
    endResetModel();
    emit itemCountChanged();
    delete oldList;
    qDebug() << "QObjectListModel::setList: " << _list;
}

void QObjectListModel::reset()
{
    //! modify
//    QAbstractListModel::reset();

    beginResetModel();
    _list->clear();
    endResetModel();
    //! --

    emit itemCountChanged();
}

void QObjectListModel::move(int oldRow, int newRow)
{
    //! modify
    if (oldRow == newRow)
        return;
    //! --

    if (oldRow < 0 || oldRow >= _list->count())
        return;

    if (newRow < 0 || newRow >= _list->count())
        return;

    beginMoveRows(QModelIndex(), oldRow, oldRow, QModelIndex(), (newRow > oldRow) ? (newRow + 1) : newRow);
    _list->move(oldRow, newRow);
    endMoveRows();
}

QObject * QObjectListModel::findItem(const char *propertyName, const QVariant &value)
{
    for (int i = 0; i < _list->size(); i++) {
        if (_list->at(i) && value == _list->at(i)->property(propertyName))
            return _list->at(i);
    }
    return 0;
}

QHash<int, QByteArray>	QObjectListModel::roleNames() const
{
    return _roleNames;
}

void QObjectListModel::refreshModel()
{
    beginResetModel();
    endResetModel();
}
