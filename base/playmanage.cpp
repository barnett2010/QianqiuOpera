#include "playmanage.h"

PlayManage::PlayManage(QObject *parent) : QObject(parent)
{
    m_cardInfoModel = new  QObjectListModel(this);
}

QObjectListModel *PlayManage::cardInfoModel()
{
    return m_cardInfoModel;
}
