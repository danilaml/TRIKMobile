#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "qmlsignalhandler.h"
#include "blockmodel.h"
#include "blocks/enginesBlocks/forwardblock.h"
#include "blocks/conditionalBlocks/infiniteblock.h"
#include "blocks/sayblock.h"
#include "blocks/drawingBlocks/smileblock.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
//	engine.load(QUrl(QStringLiteral("qrc:/BlocksView.qml")));

	BlockModel bmodel2;
	bmodel2.setItems(QList<AbstractBlock *>() << new ForwardBlock() << new SayBlock() << new SmileBlock());
	auto infblock = new InfiniteBlock();
	infblock->setChildren(QList<BlockModel *>() << &bmodel2);
	auto blocks = (QList<AbstractBlock *>() << new ForwardBlock() << infblock);
	BlockModel bmodel1;
	bmodel1.setItems(blocks);

	QmlSignalHandler mysg;
	mysg.setModel(&bmodel1);

	engine.rootContext()->setContextProperty("blockModel", mysg.model());
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	QObject *appwindow = engine.rootObjects().first();
	QObject::connect(appwindow, SIGNAL(sendPressed()), &mysg, SLOT(handleSend()));
	QObject::connect(appwindow, SIGNAL(runPressed(QString)), &mysg, SLOT(handleRun(QString)));
	QObject::connect(appwindow, SIGNAL(ipChanged(QString)), &mysg, SLOT(hadleIpChange(QString)));
	QObject::connect(appwindow, SIGNAL(stopPressed()), &mysg, SLOT(handleStop()));

	return app.exec();
}
