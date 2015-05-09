#include <QDebug>
#include <QVariant>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
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

void QmlSignalHandler::handleModelLoad(const QUrl &path)
{

}

void QmlSignalHandler::handleModelSave(const QUrl &path)
{
	QJsonObject jsonModel;
	jsonModel["version"] = "0.9";
	jsonModel["model"] = serializeModel(mModel);

	QJsonDocument jsdoc(jsonModel);
	qDebug() << jsdoc;

	QFile modelFile(path.toLocalFile());
	if (!modelFile.open(QIODevice::WriteOnly)) {
		qWarning("Couldn't open save file.");
		return;
    }
	modelFile.write(jsdoc.toJson());
}

QJsonArray QmlSignalHandler::serializeModel(const BlockModel *model) const
{
	QJsonArray items;
	for (const AbstractBlock *block : model->items()) {
		items.append(serializeBlock(block));
	}
	return items;
}

QJsonObject QmlSignalHandler::serializeBlock(const AbstractBlock *block) const
{
	QJsonObject jsblock;
	jsblock["type"] = block->blockType();

	jsblock["propertyMap"] = QJsonObject::fromVariantMap(block->getPropertyMap());
	QJsonArray children;
	for (const BlockModel *model : block->children()) {
		children.append(serializeModel(model));
	}
	jsblock["children"] = children;
	return jsblock;
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
