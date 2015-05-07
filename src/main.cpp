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

	BlockModel *bmodelTest = new BlockModel();

	auto forwardBlock1 = new ForwardBlock();
	forwardBlock1->setPort("M3");
	forwardBlock1->setPower("100");

	auto forwardBlock2 = new ForwardBlock();
	forwardBlock2->setPort("M4");
	forwardBlock2->setPower("100");

	auto timerBlock1 = new TimerBlock();
	timerBlock1->setDelay("2700");

	auto stopBlock1 = new StopBlock();
	stopBlock1->setPort("M1");

	auto stopBlock2 = new StopBlock();
	stopBlock2->setPort("M2");

	auto stopBlock3 = new StopBlock();
	stopBlock3->setPort("M3");

	auto stopBlock4 = new StopBlock();
	stopBlock4->setPort("M4");

	auto forwardBlock3 = new ForwardBlock();
	forwardBlock3->setPort("M3");
	forwardBlock3->setPower("100");

	auto forwardBlock4 = new ForwardBlock();
	forwardBlock4->setPort("M4");
	forwardBlock4->setPower("50");

	auto timerBlock2 = new TimerBlock();
	timerBlock2->setDelay("2000");

	auto stopBlock5 = new StopBlock();
	stopBlock5->setPort("M1");

	auto stopBlock6 = new StopBlock();
	stopBlock6->setPort("M2");

	auto stopBlock7 = new StopBlock();
	stopBlock7->setPort("M3");

	auto stopBlock8 = new StopBlock();
	stopBlock8->setPort("M4");

	auto forwardBlock5 = new ForwardBlock();
	forwardBlock5->setPort("M3");
	forwardBlock5->setPower("100");

	auto forwardBlock6 = new ForwardBlock();
	forwardBlock6->setPort("M4");
	forwardBlock6->setPower("100");

	auto timerBlock3 = new TimerBlock();
	timerBlock3->setDelay("2000");

	auto listWithBlocks = (QList<AbstractBlock *>() << forwardBlock1 << forwardBlock2
		<< timerBlock1
		<< stopBlock1 << stopBlock2 << stopBlock3 << stopBlock4
		<< forwardBlock3 << forwardBlock4
		<< timerBlock2
		<< stopBlock5 << stopBlock6 << stopBlock7 << stopBlock8
		<< forwardBlock5 << forwardBlock6
		<< timerBlock3);

	bmodelTest->setItems(listWithBlocks);

	BlockModel *bmodel3 = new BlockModel();
	bmodel3->setItems(QList<AbstractBlock *>() << new SayBlock());
	auto ifBlock = new IfBlock();
	ifBlock->setChildren(QList<BlockModel *>() << bmodel3);

	BlockModel *bmodel4 = new BlockModel();
	bmodel4->setItems(QList<AbstractBlock *>() << new SmileBlock());
	BlockModel *bmodel5 = new BlockModel();
	bmodel5->setItems(QList<AbstractBlock *>() << new SadSmileBlock());
	auto ifElseBlock = new IfElseBlock();
	ifElseBlock->setChildren(QList<BlockModel *>() << bmodel4 << bmodel5);

	BlockModel *bmodel2 = new BlockModel();
	bmodel2->setItems(QList<AbstractBlock *>() << new ForwardBlock() << new SayBlock() << new SmileBlock() << ifBlock);
	auto infblock = new InfiniteBlock();
	infblock->setChildren(QList<BlockModel *>() << bmodel2);
	auto blocks = (QList<AbstractBlock *>() << new ForwardBlock() << infblock << ifElseBlock);
	BlockModel *bmodel1 = new BlockModel();
	bmodel1->setItems(blocks);

	QmlSignalHandler mysg;
	//mysg.setModel(bmodel1);
	mysg.setModel(bmodelTest);

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
