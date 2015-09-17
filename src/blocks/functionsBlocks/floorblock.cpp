#include "floorblock.h"

FloorBlock::FloorBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "argument";
	propertyMap["argument"] = "1";
}

FloorBlock::~FloorBlock()
{

}

QString FloorBlock::toString(int indent) const
{
	QString res = readTemplate("functions/floor.t");
	res.replace("@@ARGUMENT@@", getProp("argument"));

	return addIndent(res, indent);
}

QString FloorBlock::blockType() const
{
	return "floorBlock";
}

QString FloorBlock::statusString() const
{
	return QString("Argument: %1").arg(getProp("argument"));
}

QString FloorBlock::argument() const
{
	return getProp("argument");
}

void FloorBlock::setArgument(const QString &argument)
{
	propertyMap["argument"] = argument;
}
