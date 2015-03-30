#include <QApplication>
#include <QQmlApplicationEngine>
#include "scriptgenerator.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	QObject *appwindow = engine.rootObjects().first();
	ScriptGenerator mysg;
	QObject::connect(appwindow, SIGNAL(sendPressed(QVariant)), &mysg, SLOT(handleSend(QVariant)));

	return app.exec();
}
