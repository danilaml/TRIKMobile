#include <QDebug>
#include <QVariant>
#include "qmlsignalhandler.h"
#include "scriptgenerator.h"
#include "blocks/forwardblock.h"

QmlSignalHandler::QmlSignalHandler(QObject *parent) : QObject(parent), mConnector("192.168.1.1")
{
	mScripts["Forward"] = "Forward script";
	mScripts["Backwards"] = "Backwards script";
	mScripts["Right"] = "Right script";
	mScripts["Left"] = "Left script";
}

QmlSignalHandler::~QmlSignalHandler()
{

}

void QmlSignalHandler::handleSend(const QVariant &scriptList)
{
    //qDebug() << scriptList.toStringList();
	QStringList list = scriptList.toStringList();
	QMap<QString, QString> consts;
	consts.insert("pi", "3.14159265");
	ScriptGenerator scriptgen;
	scriptgen.setConstants(consts);

	QSharedPointer<ForwardBlock> test(new ForwardBlock());
	test->setPower(42);
	test->setPort(1);

	qDebug() << scriptgen.generate(test);
	for (const QString &names : list)
	{
		qDebug() << mScripts.value(names);
	}
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
