#include "lnblock.h"

LnBlock::LnBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

LnBlock::~LnBlock()
{

}

QString LnBlock::toString(int indent) const
{
	QString res = readTemplate("functions/ln.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString LnBlock::blockType() const
{
	return "lnBlock";
}

QString LnBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString LnBlock::argument() const
{
	return getProp("argument");
}

void LnBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}
