#include "sqrtblock.h"

SqrtBlock::SqrtBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

SqrtBlock::~SqrtBlock()
{

}

QString SqrtBlock::toString(int indent) const
{
	QString res = readTemplate("functions/sqrt.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString SqrtBlock::blockType() const
{
	return "sqrtBlock";
}

QString SqrtBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString SqrtBlock::argument() const
{
	return getProp("argument");
}

void SqrtBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}
