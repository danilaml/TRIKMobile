#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "qmlsignalhandler.h"
#include "blockmodel.h"
#include "blocks/forwardblock.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
//	engine.load(QUrl(QStringLiteral("qrc:/BlocksView.qml")));

	BlockModel bmodel2;
	bmodel2.setItems(QList<AbstractBlock *>() << new ForwardBlock() << new ForwardBlock());
	auto fwblock = new ForwardBlock();
	fwblock->setPort("M1");
	fwblock->setPower("42");
	fwblock->setChildren(QList<BlockModel *>() << &bmodel2);
	auto blocks = (QList<AbstractBlock *>() << new ForwardBlock() << fwblock);
	BlockModel bmodel1;
	bmodel1.setItems(blocks);

	engine.rootContext()->setContextProperty("blockModel", &bmodel1);
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//	QQmlApplicationEngine engine;
//	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//	QObject *appwindow = engine.rootObjects().first();
//	QmlSignalHandler mysg;
//	QObject::connect(appwindow, SIGNAL(sendPressed(QVariant)), &mysg, SLOT(handleSend(QVariant)));
//	QObject::connect(appwindow, SIGNAL(runPressed(QString)), &mysg, SLOT(handleRun(QString)));
//	QObject::connect(appwindow, SIGNAL(ipChanged(QString)), &mysg, SLOT(hadleIpChange(QString)));
//	QObject::connect(appwindow, SIGNAL(stopPressed()), &mysg, SLOT(handleStop()));

	return app.exec();
}
