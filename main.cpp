#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QScreen>

#include "common/qobjectlistmodel.h"
#include "base/config.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qDebug() << QString::fromUtf8("程序启动中...");

    //! ui
    QQuickView viewer;

    qmlRegisterType<QObjectListModel>("com.jpgk.qmlcomponents", 1, 0, "QObjectListModel");

    viewer.engine()->rootContext()->setContextProperty("Config", Config::instance());

    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setSource(QUrl("qrc:/main.qml"));

    //#ifdef LOCAL_DEBUG
#ifdef COMPILE_FOR_WINDOWS
    viewer.setGeometry(800, 450, 960, 540);
    viewer.show();
#elif COMPILE_FOR_ANDROID
    int width = 1080;
    int height = 1920;
    QScreen *screen = QGuiApplication::screens().value(0);
    if (screen) {
        width = screen->size().width();
        height = screen->size().height();
    }
    viewer.setGeometry(0, 0, width, height);
    viewer.show();
#else
    viewer.showFullScreen();
#endif
    qDebug() << QString::fromUtf8("界面显示完毕");

    return app.exec();
}
