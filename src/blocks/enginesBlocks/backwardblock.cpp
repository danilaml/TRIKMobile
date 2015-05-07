#include "backwardblock.h"

BackwardBlock::BackwardBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "power" << "port";
	propertyMap["power"] = "100";
	propertyMap["port"] = "M1";
}

BackwardBlock::~BackwardBlock()
{

}

QString BackwardBlock::toString(int indent) const
{
	QString res = readTemplate("engines/backward.t");
	res.replace("@@PORT@@", getProp("port")).replace("@@POWER@@", getProp("power"));

	return addIndent(res, indent);
}

QString BackwardBlock::blockType() const
{
	return "backwardBlock";
}

QString BackwardBlock::statusString() const
{
	return QString("Port: %1, Power: %2").arg(getProp("port"), getProp("power"));
}

QString BackwardBlock::power() const
{
	return getProp("power");
}

void BackwardBlock::setPower(const QString &power)
{
	propertyMap["power"] = power;
}

QString BackwardBlock::port() const
{
	return getProp("port");
}

void BackwardBlock::setPort(const QString &port)
{
	propertyMap["port"] = port;
}
