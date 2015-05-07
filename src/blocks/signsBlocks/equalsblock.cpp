#include "equalsblock.h"

EqualsBlock::EqualsBlock(QObject *parent) : AbstractBlock(parent)
{

}

EqualsBlock::~EqualsBlock()
{

}

QString EqualsBlock::toString(int indent) const
{
	QString res = readTemplate("signs/equals.t");
	return addIndent(res, indent);
}

QString EqualsBlock::blockType() const
{
	return "equalsBlock";
}
