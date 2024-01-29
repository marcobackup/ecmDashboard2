#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "core/alertqueue.h"
#include "core/uarthandler.h"
#include "core/can/messagehandler.h"
#include "core/controller.h"
#include "core/controller/gauge.h"
#include "core/controller/topbar.h"
#include "core/soundhandler.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    // sound handler
    SoundHandler soundHandler;

    // alert queue handler
    AlertQueue alertQueueHandler;

    // controllers
    Gauge gaugeController;
    TopBar topBarController;

    Controller controller(&gaugeController, &topBarController);

    // uart handler instance
    UartHandler uartHandler;

    // message handler instance
    MessageHandler messageHandler(&controller, &alertQueueHandler);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    // set qt object as property
    QQmlContext *context(engine.rootContext());
    context->setContextProperty("gaugeController", (QObject *) &gaugeController);
    context->setContextProperty("topBarController", (QObject *) &topBarController);
    context->setContextProperty("alertQueueHandler", (QObject *) &alertQueueHandler);

    // listen to incoming uart data
    QObject::connect(&uartHandler, &UartHandler::dataReceived, [&messageHandler](UartHandler::rxMessage data) {
        messageHandler.handleMessageData(data);
    });

    // start up chime effect
    soundHandler.playWarningChimeSoundEffect(2);

    engine.load(url);

    return app.exec();
}
