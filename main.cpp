#include <QApplication>
#include <QQmlApplicationEngine>
#include "qmlsignalhandler.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	QObject *appwindow = engine.rootObjects().first();
	QmlSignalHandler mysg;
	QObject::connect(appwindow, SIGNAL(sendPressed(QVariant)), &mysg, SLOT(handleSend(QVariant)));
	QObject::connect(appwindow, SIGNAL(runPressed(QString)), &mysg, SLOT(handleRun(QString)));
	QObject::connect(appwindow, SIGNAL(ipChanged(QString)), &mysg, SLOT(handleIpChanged(QString)));

	return app.exec();
}
