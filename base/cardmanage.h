#ifndef CARDMANAGE_H
#define CARDMANAGE_H

#include <QObject>

class CardManage : public QObject
{
    Q_OBJECT
public:
    explicit CardManage(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CARDMANAGE_H
