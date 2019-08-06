#ifndef Card_H
#define Card_H

#include <QObject>
#include <QQmlPropertyMap>

class Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString imgPath READ imgPath WRITE setImgPath NOTIFY imgPathChanged)
    Q_PROPERTY(int season READ season WRITE setSeason NOTIFY seasonChanged)


    Q_PROPERTY(double price READ price WRITE setPrice NOTIFY priceChanged)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(QString detail READ detail WRITE setDetail NOTIFY detailChanged)
    Q_PROPERTY(int goodsState READ goodsState WRITE setGoodsState NOTIFY goodsStateChanged)
    Q_PROPERTY(QString baseInfo READ baseInfo WRITE setBaseInfo NOTIFY baseInfoChanged)
    Q_PROPERTY(int ordering READ ordering WRITE setOrdering NOTIFY orderingChanged)
    Q_PROPERTY(int passage READ passage WRITE setPassage NOTIFY passageChanged)
    Q_PROPERTY(bool addGoods READ addGoods WRITE setAddGoods NOTIFY addGoodsChanged)
    Q_PROPERTY(int retailId READ retailId WRITE setRetailId NOTIFY retailIdChanged)
    Q_PROPERTY(QList<int> inventorysList READ inventorysList WRITE setInventorysList NOTIFY inventorysListChanged)
    Q_PROPERTY(QQmlPropertyMap properties READ properties NOTIFY propertiesChanged)

public:
    explicit Card(QObject *parent = 0);
    ~Card();

signals:
    void idChanged();
    void nameChanged();
    void priceChanged();
    void imgPathChanged();
    void countChanged();
    void detailChanged();
    void goodsStateChanged();
    void baseInfoChanged();
    void orderingChanged();
    void propertiesChanged();
    void passageChanged();
    void addGoodsChanged();
    void inventorysListChanged();
    void retailIdChanged();
    void seasonChanged();
public:
    int id() const;
    void setId(const int &gid);

    QString name() const;
    void setName(const QString &name);

    double price() const;
    void setPrice(double price);

    QString imgPath() const;
    void setImgPath(const QString &path);

    int count() const;
    void setCount(int count);

    QString detail() const;
    void setDetail(const QString &detail);

    int goodsState() const;
    void setGoodsState(int goodsState);

    QString baseInfo() const;
    void setBaseInfo(const QString &baseInfo);

    int ordering() const;
    void setOrdering(int ordering);

    QQmlPropertyMap *properties() const;

    QList<int> inventorysList() const;
    void setInventorysList(QList<int> &inventoryList);

    //    QString getGoodsJson();


    int passage() const;
    void setPassage(int passage);

    bool addGoods() const;
    void setAddGoods(bool addGoods);

    int retailId() const;
    void setRetailId(int retailId);

    int season() const;
    void setSeason(int season);

private:
    int m_id;
    QString m_name;
    double m_price;
    QString m_imgPath;
    int m_count;
    QString m_detail;
    int m_goodsState;
    QString m_baseInfo;
    int m_ordering;
    QList<int> m_inventoryList;
    int m_passage;
    bool m_addGoods;
    int m_retailId;
    int m_season;//1春 2夏 3秋 4东
    QQmlPropertyMap *m_proerties;
};

#endif // Card_H
