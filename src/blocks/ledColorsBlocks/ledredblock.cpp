#include "ledredblock.h"

LedRedBlock::LedRedBlock(QObject *parent) : AbstractBlock(parent)
{

}

LedRedBlock::~LedRedBlock()
{

}

QString LedRedBlock::toString(int indent) const
{
	QString res = readTemplate("ledColors/red.t");
	return addIndent(res, indent);
}

QString LedRedBlock::blockType() const
{
	return "ledRedBlock";
}
