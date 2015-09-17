#include "randomblock.h"

RandomBlock::RandomBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "0";
}

RandomBlock::~RandomBlock()
{

}

QString RandomBlock::toString(int indent) const
{
	QString res = readTemplate("functions/random.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString RandomBlock::blockType() const
{
	return "randomBlock";
}

QString RandomBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString RandomBlock::argument() const
{
	return getProp("argument");
}

void RandomBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}

