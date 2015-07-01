#include "asinblock.h"

AsinBlock::AsinBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

AsinBlock::~AsinBlock()
{

}

QString AsinBlock::toString(int indent) const
{
	QString res = readTemplate("functions/asin.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString AsinBlock::blockType() const
{
	return "asinBlock";
}

QString AsinBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString AsinBlock::argument() const
{
	return getProp("argument");
}

void AsinBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}

