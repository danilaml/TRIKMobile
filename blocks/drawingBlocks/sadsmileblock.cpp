#include "sadsmileblock.h"

SadSmileBlock::SadSmileBlock(QObject *parent) : AbstractBlock(parent)
{

}

SadSmileBlock::~SadSmileBlock()
{

}

QString SadSmileBlock::toString(int indent) const
{
	QString res = readTemplate("drawing/sadSmile.t");
	return addIndent(res, indent);
}

QString SadSmileBlock::blockType() const
{
	return "sadSmileBlock";
}
