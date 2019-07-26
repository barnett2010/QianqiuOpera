#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>

class ConfigPrivate;
class Config :public QObject
{
    Q_OBJECT

public:
    ~Config();

    static Config * instance();

public slots:
    static QString value(const QString &key);
    static void setValue(const QString &key, const QString &value);

signals:
    void valueChanged(const QString &key, const QString &value);

private:
    explicit Config(QObject *parent = 0);

    QScopedPointer<ConfigPrivate> d_ptr;
};

#endif // CONFIG_H
