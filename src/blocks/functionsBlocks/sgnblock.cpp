#include "sgnblock.h"

SgnBlock::SgnBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

SgnBlock::~SgnBlockk()
{

}

QString SgnBlock::toString(int indent) const
{
	QString res = readTemplate("functions/sgn.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString SgnBlock::blockType() const
{
	return "sgnBlock";
}

QString SgnBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString SgnBlock::argument() const
{
	return getProp("argument");
}

void SgnBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}

