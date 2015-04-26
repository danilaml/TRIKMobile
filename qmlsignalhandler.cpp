#include <QDebug>
#include <QVariant>
#include "qmlsignalhandler.h"
#include "scriptgenerator.h"
#include "blocks/enginesBlocks/forwardblock.h"
#include "blocks/sayblock.h"

QmlSignalHandler::QmlSignalHandler(QObject *parent) : QObject(parent), mConnector("192.168.1.1")
{
}

QmlSignalHandler::~QmlSignalHandler()
{
	//delete mModel;
}

void QmlSignalHandler::handleSend()
{
	//qDebug() << scriptList.toStringList();
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

BlockModel *QmlSignalHandler::model() const
{
	return mModel;
}

void QmlSignalHandler::setModel(BlockModel *model)
{
	mModel = model;
}




