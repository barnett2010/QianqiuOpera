#ifndef PLAYMANAGE_H
#define PLAYMANAGE_H

#include <QObject>
#include "items/card.h"
#include "common/qobjectlistmodel.h"

class PlayManage : public QObject
{
    Q_OBJECT
public:
    explicit PlayManage(QObject *parent = nullptr);

    Q_INVOKABLE QObjectListModel *cardInfoModel();

signals:

public slots:

private slots:
    void init();

private:
    QObjectListModel *m_cardInfoModel;
};

#endif // PLAYMANAGE_H
