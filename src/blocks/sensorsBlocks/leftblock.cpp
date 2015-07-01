#include "leftblock.h"

LeftBlock::LeftBlock(QObject *parent) : AbstractBlock(parent)
{

}

LeftBlock::~LeftBlock()
{

}

QString LeftBlock::toString(int indent) const
{
	QString res = readTemplate("sensors/Left.t");
	return addIndent(res, indent);
}

QString LeftBlock::blockType() const
{
	return "leftBlock";
}
