#include "config.h"

#include <QCoreApplication>
#include <QSettings>
#include <QSaveFile>
#include <QMap>
#include <QDebug>
#include <QDir>
#include <QFile>

class ConfigPrivate
{
public:
    static Config *pInstance;

    void initDefaultValues();
    QString getEtcPath();
    QString vitalDir;

    QMap<QString, QString> defaultConfigs;
    QSettings *configFile;
};

void ConfigPrivate::initDefaultValues()
{
    defaultConfigs.insert("SeverScheme", "http://");
    //    defaultConfigs.insert("HttpServerHost", "192.168.1.131:8082");
    //    defaultConfigs.insert("HttpServerHost", "ipcser.lz517.cn");
    defaultConfigs.insert("HttpServerHost", "ipcser.lz517.com");
    //    defaultConfigs.insert("HttpServerHost", "192.168.1.163:8081");
    defaultConfigs.insert("DeviceName", "");
    defaultConfigs.insert("CachePath", getEtcPath() + "/cache");
    defaultConfigs.insert("LogPath", getEtcPath() + "logs");
    defaultConfigs.insert("DataPath", QCoreApplication::applicationDirPath() + "/data");
    defaultConfigs.insert("EtcPath", getEtcPath());
    defaultConfigs.insert("DevicePort", "/dev/ttyS3");
    defaultConfigs.insert("IsUseCash", "true");
    defaultConfigs.insert("IsUseVedio", "false");
    defaultConfigs.insert("IsUseIr", "true");
    defaultConfigs.insert("MotorType", "3");
    defaultConfigs.insert("LogoUrl", "qrc:/ui/res/image/logo.png");
    //    defaultConfigs.insert("Temprature", "设置温度");
    defaultConfigs.insert("senmeiHuoDao",
                          "11=11,12=12,13=13,14=14,15=15,16=16,21=21,22=22,23=23,24=24,25=25,26=26,31=31,32=32,33=33,34=34,35=35,36=36,41=41,42=42,43=43,44=44,45=45,46=46,51=51,52=52,53=53,54=54,55=55,56=56,61=61,62=62,63=63,64=64,65=65,66=66");//森美使用
    defaultConfigs.insert("row", "3"); //目前只支持1X1 3X4
    defaultConfigs.insert("col", "4");
    //    defaultConfigs.insert("HttpServerUrl", "192.168.1.131");
#ifdef COMPILE_FOR_ANDROID
    defaultConfigs.insert("FontPath", "file:////sdcard/Fonts/");
#endif
#ifdef COMPILE_FOR_WINDOWS
    defaultConfigs.insert("FontPath", "file:///" + getEtcPath() + "font/");
#endif
}

QString ConfigPrivate::getEtcPath()
{
#ifdef COMPILE_FOR_LINUX
    QDir dir = QCoreApplication::applicationDirPath();
    return dir.path() + "/etc/";
#endif

#ifdef COMPILE_FOR_ANDROID
    return "/sdcard/etc/";
#endif

#ifdef COMPILE_FOR_WINDOWS
    QDir dir = QCoreApplication::applicationDirPath();
    dir.cdUp();
    return dir.path() + "/etc/";
#endif
}

Config *ConfigPrivate::pInstance = 0;
Config *Config::instance()
{
    if (ConfigPrivate::pInstance == 0) {
        ConfigPrivate::pInstance = new Config(QCoreApplication::instance());
    }

    return ConfigPrivate::pInstance;
}

Config::Config(QObject *parent) :
    QObject(parent),
    d_ptr(new ConfigPrivate)
{
    d_ptr->vitalDir = d_ptr->getEtcPath() + "vitalFiles";
    //! init default values;
    //    d_ptr->initDefaultValues();
    //! init config file
    d_ptr->configFile = new QSettings(d_ptr->getEtcPath() + "/config.ini", QSettings::IniFormat);
    d_ptr->configFile->setIniCodec("UTF-8");
    d_ptr->initDefaultValues();
}

Config::~Config()
{
    ConfigPrivate::pInstance = 0;
}

QString Config::value(const QString &key)
{

    if (Config::instance()->d_ptr->configFile->contains(key)) {
        return Config::instance()->d_ptr->configFile->value(key).toString();
    }
    return Config::instance()->d_ptr->defaultConfigs.value(key);

}

void Config::setValue(const QString &key, const QString &value)
{
    qDebug() << "Config::setValue: " << key << "->" << value;

    if (value == Config::value(key)) {
        return;
    }

    Config::instance()->d_ptr->configFile->setValue(key, value);
    Config::instance()->d_ptr->configFile->sync();

    emit Config::instance()->valueChanged(key, value);
}
