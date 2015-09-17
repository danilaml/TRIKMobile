#include "expblock.h"

ExpBlock::ExpBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

ExpBlock::~ExpBlock()
{

}

QString ExpBlock::toString(int indent) const
{
	QString res = readTemplate("functions/exp.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString ExpBlock::blockType() const
{
	return "expBlock";
}

QString ExpBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString ExpBlock::argument() const
{
	return getProp("argument");
}

void ExpBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}
