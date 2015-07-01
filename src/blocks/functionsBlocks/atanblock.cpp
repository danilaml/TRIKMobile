#include "atanblock.h"

AtanBlock::AtanBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

AtanBlock::~AtanBlock()
{

}

QString AtanBlock::toString(int indent) const
{
	QString res = readTemplate("functions/atan.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString AtanBlock::blockType() const
{
	return "atanBlock";
}

QString AtanBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString AtanBlock::argument() const
{
	return getProp("argument");
}

void AtanBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}

