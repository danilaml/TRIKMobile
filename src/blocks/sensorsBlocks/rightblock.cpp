#include "rightblock.h"

RightBlock::RightBlock(QObject *parent) : AbstractBlock(parent)
{

}

RightBlock::~RightBlock()
{

}

QString RightBlock::toString(int indent) const
{
	QString res = readTemplate("sensors/Right.t");
	return addIndent(res, indent);
}

QString RightBlock::blockType() const
{
	return "rightBlock";
}
