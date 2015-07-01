#include "randomizeblock.h"

RandomizeBlock::RandomizeBlock(QObject *parent) : AbstractBlock(parent)
{

}

RandomizeBlock::~RandomizeBlock()
{

}

QString RandomizeBlock::toString(int indent) const
{
	QString res = readTemplate("functions/randomize.t");
	return addIndent(res, indent);
}

QString RandomizeBlock::blockType() const
{
	return "randomizeBlock";
}
