#include "stopblock.h"

StopBlock::StopBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "port";
	propertyMap["port"] = "M1";
}

StopBlock::~StopBlock()
{

}

QString StopBlock::toString(int indent) const
{
	QString res = readTemplate("engines/stop.t");
	res.replace("@@PORT@@", getProp("port"));

	return addIndent(res, indent);
}

QString StopBlock::blockType() const
{
	return "stopBlock";
}

QString StopBlock::statusString() const
{
	return QString("Port: %1").arg(getProp("port"));
}

QString StopBlock::port() const
{
	return getProp("port");
}

void StopBlock::setPort(const QString &port)
{
	propertyMap["port"] = port;
}
