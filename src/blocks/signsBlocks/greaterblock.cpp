#include "greaterblock.h"

GreaterBlock::GreaterBlock(QObject *parent) : AbstractBlock(parent)
{

}

GreaterBlock::~GreaterBlock()
{

}

QString GreaterBlock::toString(int indent) const
{
	QString res = readTemplate("signs/greater.t");
	return addIndent(res, indent);
}

QString GreaterBlock::blockType() const
{
	return "greaterBlock";
}
