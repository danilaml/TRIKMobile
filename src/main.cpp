#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "qmlsignalhandler.h"
#include "blockmodel.h"
#include "blocks/enginesBlocks/forwardblock.h"
#include "blocks/conditionalBlocks/infiniteblock.h"
#include "blocks/sayblock.h"
#include "blocks/drawingBlocks/smileblock.h"
#include "blocks/conditionalBlocks/ifblock.h"
#include "blocks/conditionalBlocks/ifelseblock.h"
#include "blocks/drawingBlocks/sadsmileblock.h"
#include "blocks/waitBlocks/timerblock.h"
#include "blocks/enginesBlocks/stopblock.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
//	engine.load(QUrl(QStringLiteral("qrc:/BlocksView.qml")));

//	BlockModel *bmodel3 = new BlockModel();
//	bmodel3->setItems(QList<AbstractBlock *>() << new SayBlock());
//	auto ifBlock = new IfBlock();
//	ifBlock->setChildren(QList<BlockModel *>() << bmodel3);

//	BlockModel *bmodel4 = new BlockModel();
//	bmodel4->setItems(QList<AbstractBlock *>() << new SmileBlock());
//	BlockModel *bmodel5 = new BlockModel();
//	bmodel5->setItems(QList<AbstractBlock *>() << new SadSmileBlock());
//	auto ifElseBlock = new IfElseBlock();
//	ifElseBlock->setChildren(QList<BlockModel *>() << bmodel4 << bmodel5);

//	BlockModel *bmodel2 = new BlockModel();
//	bmodel2->setItems(QList<AbstractBlock *>() << new ForwardBlock() << new SayBlock() << new SmileBlock() << ifBlock);
//	auto infblock = new InfiniteBlock();
//	infblock->setChildren(QList<BlockModel *>() << bmodel2);
//	auto blocks = (QList<AbstractBlock *>() << new ForwardBlock() << infblock << ifElseBlock);
//	BlockModel *bmodel1 = new BlockModel();
//	bmodel1->setItems(blocks);

	QmlSignalHandler mysg;
//	mysg.setModel(bmodel1);

	engine.rootContext()->setContextProperty("blockModel", mysg.model());
	QStringList registeredBlocks = mysg.factory().registeredBlocks();
	engine.rootContext()->setContextProperty("registeredBlocks", registeredBlocks);
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	QObject *appwindow = engine.rootObjects().first();
	QObject::connect(appwindow, SIGNAL(addBlock(QString,QString)), &mysg, SLOT(handleAdd(QString,QString)));
	QObject::connect(appwindow, SIGNAL(sendPressed(QString)), &mysg, SLOT(handleSend(QString)));
	QObject::connect(appwindow, SIGNAL(runPressed(QString)), &mysg, SLOT(handleRun(QString)));
	QObject::connect(appwindow, SIGNAL(ipChanged(QString)), &mysg, SLOT(hadleIpChange(QString)));
	QObject::connect(appwindow, SIGNAL(stopPressed()), &mysg, SLOT(handleStop()));
	QObject::connect(appwindow, SIGNAL(loadModel(QUrl)), &mysg, SLOT(handleModelLoad(QUrl)));
	QObject::connect(appwindow, SIGNAL(saveModel(QUrl)), &mysg, SLOT(handleModelSave(QUrl)));

	return app.exec();
}
