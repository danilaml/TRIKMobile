#include "lessblock.h"

LessBlock::LessBlock(QObject *parent) : AbstractBlock(parent)
{

}

LessBlock::~LessBlock()
{

}

QString LessBlock::toString(int indent) const
{
	QString res = readTemplate("signs/less.t");
	return addIndent(res, indent);
}

QString LessBlock::blockType() const
{
	return "lessBlock";
}
