#include "greenblock.h"

GreenBlock::GreenBlock(QObject *parent) : AbstractBlock(parent)
{

}

GreenBlock::~GreenBlock()
{

}

QString GreenBlock::toString(int indent) const
{
	QString res = readTemplate("backgroundColors/green.t");
	return addIndent(res, indent);
}

QString GreenBlock::blockType() const
{
	return "greenBlock";
}
