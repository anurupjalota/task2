#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <csvclass.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

     CsvClass csvClass;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/task2/main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    qmlRegisterType<CsvClass>("com.mycompany.CsvClass", 1, 0, "CsvClass");
    engine.load(url);

    return app.exec();
}
