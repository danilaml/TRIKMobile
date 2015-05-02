#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "qmlsignalhandler.h"
#include "blockmodel.h"
#include "blocks/enginesBlocks/forwardblock.h"
#include "blocks/conditionalBlocks/infiniteblock.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
//	engine.load(QUrl(QStringLiteral("qrc:/BlocksView.qml")));

	BlockModel *bmodel2 = new BlockModel();
	bmodel2->setItems(QList<AbstractBlock *>() << new ForwardBlock() << new ForwardBlock());
	auto infblock1 = new InfiniteBlock();
	infblock1->setChildren(QList<BlockModel *>() << bmodel2);
	BlockModel *bmodel3 = new BlockModel();
	bmodel3->setItems(QList<AbstractBlock *>() << new ForwardBlock() << infblock1);
	auto infblock2 = new InfiniteBlock();
	infblock2->setChildren(QList<BlockModel *>() << bmodel3);
	auto blocks = (QList<AbstractBlock *>() << new ForwardBlock() << infblock2 << new ForwardBlock());
	BlockModel *bmodel1 = new BlockModel();
	bmodel1->setItems(blocks);

	QmlSignalHandler mysg;
	mysg.setModel(bmodel1);

	engine.rootContext()->setContextProperty("blockModel", mysg.model());
	QStringList registeredBlocks = mysg.factory().registeredBlocks();
	engine.rootContext()->setContextProperty("registeredBlocks", registeredBlocks);
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	QObject *appwindow = engine.rootObjects().first();
	QObject::connect(appwindow, SIGNAL(addBlock(QString,QString)), &mysg, SLOT(handleAdd(QString,QString)));
	QObject::connect(appwindow, SIGNAL(sendPressed()), &mysg, SLOT(handleSend()));
	QObject::connect(appwindow, SIGNAL(runPressed(QString)), &mysg, SLOT(handleRun(QString)));
	QObject::connect(appwindow, SIGNAL(ipChanged(QString)), &mysg, SLOT(hadleIpChange(QString)));
	QObject::connect(appwindow, SIGNAL(stopPressed()), &mysg, SLOT(handleStop()));

	return app.exec();
}
