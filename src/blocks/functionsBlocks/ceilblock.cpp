#include "ceilblock.h"

CeilBlock::CeilBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

CeilBlock::~CeilBlock()
{

}

QString CeilBlock::toString(int indent) const
{
	QString res = readTemplate("functions/ceil.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString CeilBlock::blockType() const
{
	return "ceilBlock";
}

QString CeilBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString CeilBlock::argument() const
{
	return getProp("argument");
}

void CeilBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}

