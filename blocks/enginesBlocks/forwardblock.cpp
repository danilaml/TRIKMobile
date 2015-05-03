#include "forwardblock.h"

ForwardBlock::ForwardBlock(QObject *parent) : AbstractBlock(parent)
{
	propertyNames << "power" << "port";
	propertyMap["power"] = "100";
	propertyMap["port"] = "M1";
}

ForwardBlock::~ForwardBlock()
{

}

QString ForwardBlock::toString(int indent) const
{
	QString res = readTemplate("engines/forward.t");
	res.replace("@@PORT@@", getProp("port")).replace("@@POWER@@", getProp("power"));

	return addIndent(res, indent);
}

QString ForwardBlock::statusString() const
{
	return QString("Port: %1, Power: %2").arg(getProp("port"), getProp("power"));
}

QString ForwardBlock::power() const
{
	return getProp("power");
}

void ForwardBlock::setPower(const QString &power)
{
	propertyMap["power"] = power;
}

QString ForwardBlock::port() const
{
	return getProp("port");
}

void ForwardBlock::setPort(const QString &port)
{
	propertyMap["port"] = port;
}
