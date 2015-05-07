#include "absblock.h"

AbsBlock::AbsBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "-14";
}

AbsBlock::~AbsBlock()
{

}

QString AbsBlock::toString(int indent) const
{
	QString res = readTemplate("functions/abs.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString AbsBlock::blockType() const
{
	return "absBlock";
}

QString AbsBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString AbsBlock::argument() const
{
	return getProp("argument");
}

void AbsBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}
