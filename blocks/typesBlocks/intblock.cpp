#include "intblock.h"

IntBlock::IntBlock(QObject *parent) : AbstractBlock(parent)
{

}

IntBlock::~IntBlock()
{

}

QString IntBlock::toString(int indent) const
{
	QString res = readTemplate("types/int.t");
	return addIndent(res, indent);
}

QString IntBlock::blockType() const
{
	return "intBlock";
}
