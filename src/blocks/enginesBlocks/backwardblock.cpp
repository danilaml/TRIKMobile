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
	QString property = getProp("port");
	property.remove(' ');
	QStringList const list = property.split(",", QString::SkipEmptyParts);
	QString result;
	for (QString const &line : list)
	{
		QString res = readTemplate("engines/backward.t");
		res.replace("@@PORT@@", line).replace("@@POWER@@", getProp("power"));
		result += res + "\n";
	}

	return addIndent(result, indent);
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
