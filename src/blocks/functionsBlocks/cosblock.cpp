#include "cosblock.h"

CosBlock::CosBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

CosBlock::~CosBlock()
{

}

QString CosBlock::toString(int indent) const
{
	QString res = readTemplate("functions/cos.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString CosBlock::blockType() const
{
	return "cosBlock";
}

QString CosBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString CosBlock::argument() const
{
	return getProp("argument");
}

void CosBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}
