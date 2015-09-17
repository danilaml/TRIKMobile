#include "sinblock.h"

SinBlock::SinBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

SinBlock::~SinBlock()
{

}

QString SinBlock::toString(int indent) const
{
	QString res = readTemplate("functions/sin.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString SinBlock::blockType() const
{
	return "sinBlock";
}

QString SinBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString SinBlock::argument() const
{
	return getProp("argument");
}

void SinBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}
