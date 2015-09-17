#include "acosblock.h"

AcosBlock::AcosBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

AcosBlock::~AcosBlock()
{

}

QString AcosBlock::toString(int indent) const
{
	QString res = readTemplate("functions/acos.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString AcosBlock::blockType() const
{
	return "acosBlock";
}

QString AcosBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString AcosBlock::argument() const
{
	return getProp("argument");
}

void AcosBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}
