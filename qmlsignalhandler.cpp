#include <QDebug>
#include <QVariant>
#include "qmlsignalhandler.h"
#include "scriptgenerator.h"

QmlSignalHandler::QmlSignalHandler(QObject *parent) : QObject(parent), mConnector("192.168.1.1")
{
}

QmlSignalHandler::~QmlSignalHandler()
{
	delete mModel;
}

void QmlSignalHandler::handleSend()
{
	QMap<QString, QString> consts;
	consts.insert("pi", "3.14159265");
	ScriptGenerator scriptgen;
	scriptgen.setConstants(consts);

	qDebug() << scriptgen.generate(mModel);
	mConnector.uploadProgram("test", scriptgen.generate(mModel));
}

void QmlSignalHandler::handleRun(const QString &name)
{
	mConnector.runProgram(name);
}

void QmlSignalHandler::handleStop()
{
	mConnector.stopRobot();
}

void QmlSignalHandler::hadleIpChange(const QString &newIp)
{
	mConnector.changeServerIP(newIp);
}

BlockFactory QmlSignalHandler::factory() const
{
	return mFactory;
}

void QmlSignalHandler::setFactory(const BlockFactory &factory)
{
	mFactory = factory;
}

BlockModel *QmlSignalHandler::model() const
{
	return mModel;
}

void QmlSignalHandler::setModel(BlockModel *model)
{
	mModel = model;
}

void QmlSignalHandler::handleAdd(const QString &blockType, const QString &path)
{
	mModel->addBlock(mFactory.getInstance(blockType), path);
}
