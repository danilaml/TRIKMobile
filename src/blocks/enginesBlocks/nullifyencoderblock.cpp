#include "nullifyencoderblock.h"

NullifyEncoderBlock::NullifyEncoderBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "port";
	propertyMap["port"] = "M1";
}

NullifyEncoderBlock::~NullifyEncoderBlock()
{

}

QString NullifyEncoderBlock::toString(int indent) const
{
	QString res = readTemplate("engines/nullifyEncoder.t");
	res.replace("@@PORT@@", getProp("port"));

	return addIndent(res, indent);
}

QString NullifyEncoderBlock::blockType() const
{
	return "nullifyEncoderBlock";
}

QString NullifyEncoderBlock::statusString() const
{
	return QString("Port: %1").arg(getProp("port"));
}

QString NullifyEncoderBlock::port() const
{
	return getProp("port");
}

void NullifyEncoderBlock::setPort(const QString &port)
{
	propertyMap["port"] = port;
}

