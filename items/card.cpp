#include <QJsonObject>
#include <QJsonDocument>
#include "card.h"

Card::Card(QObject *parent) :
    QObject(parent),
    m_price(0.0),
    m_count(0),
    m_goodsState(0),
    m_addGoods(false),
    m_proerties(0)
{
    m_proerties = new QQmlPropertyMap(this);
}

Card::~Card()
{
}

int Card::id() const
{
    return m_id;
}

void Card::setId(const int &id)
{
    if (id == m_id) {
        return;
    }
    m_id = id;
    emit idChanged();
}

QString Card::name() const
{
    return m_name;
}

void Card::setName(const QString &name)
{
    if (name == m_name) {
        return;
    }
    m_name = name;
    emit nameChanged();
}

double Card::price() const
{
    return m_price;
}

void Card::setPrice(double price)
{
    if (price == m_price) {
        return;
    }
    m_price = price;
    emit priceChanged();
}

QString Card::imgPath() const
{
    return m_imgPath;
}

void Card::setImgPath(const QString &path)
{
    if (path == m_imgPath) {
        return;
    }
    m_imgPath = path;
    emit imgPathChanged();
}

int Card::count() const
{
    return m_count;
}

void Card::setCount(int count)
{
    if (count == m_count) {
        return;
    }
    m_count = count;
    emit countChanged();
}

QString Card::detail() const
{
    return m_detail;
}

void Card::setDetail(const QString &detail)
{
    if (detail == m_detail) {
        return;
    }
    m_detail = detail;
    emit detailChanged();
}

int Card::goodsState() const
{
    return m_goodsState;
}

void Card::setGoodsState(int goodsState)
{
    if (goodsState == m_goodsState) {
        return;
    }
    m_goodsState = goodsState;
    emit goodsStateChanged();
}

QString Card::baseInfo() const
{
    return m_baseInfo;
}

void Card::setBaseInfo(const QString &baseInfo)
{
    if (baseInfo == m_baseInfo) {
        return;
    }
    m_baseInfo = baseInfo;
    emit baseInfoChanged();
}

int Card::ordering() const
{
    return m_ordering;
}

void Card::setOrdering(int ordering)
{
    if (ordering == m_ordering) {
        return;
    }
    m_ordering = ordering;
    emit orderingChanged();
}

QQmlPropertyMap *Card::properties() const
{
    return m_proerties;
}

QList<int> Card::inventorysList() const
{
    return m_inventoryList;
}

void Card::setInventorysList(QList<int> &inventorysList)
{
    m_inventoryList = inventorysList;
    emit inventorysListChanged();
}

//QString Card::getGoodsJson()
//{
//    QJsonObject obj {
//        {"desc", m_detail},
//        {"goodsId", m_gid},
//        {"goodsName", m_name},
//        {"ordering", m_ordering},
//        {"pic", m_imgPath},
//        {"salePrice", m_price}
//    };
//    QString jsonStr = QString(QJsonDocument(obj).toJson());
//    return jsonStr;
//}

int Card::passage() const
{
    return m_passage;
}

void Card::setPassage(int passage)
{
    if (passage == m_passage) {
        return;
    }
    m_passage = passage;
    emit passageChanged();
}

bool Card::addGoods() const
{
    return m_addGoods;
}

void Card::setAddGoods(bool addGoods)
{
    if (addGoods == m_addGoods) {
        return;
    }
    m_addGoods = addGoods;
    emit addGoodsChanged();
}

int Card::retailId() const
{
    return m_retailId;
}

void Card::setRetailId(int retailId)
{
    if (retailId == m_retailId) {
        return;
    }
    m_retailId = retailId;
    emit retailIdChanged();
}

int Card::season() const
{
    return m_season;
}

void Card::setSeason(int season)
{
    if (season == m_season) {
        return;
    }
    m_season = season;
    emit seasonChanged();
}
