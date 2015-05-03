#include "ledgreenblock.h"

LedGreenBlock::LedGreenBlock(QObject *parent) : AbstractBlock(parent)
{

}

LedGreenBlock::~LedGreenBlock()
{

}

QString LedGreenBlock::toString(int indent) const
{
	QString res = readTemplate("ledColors/green.t");
	return addIndent(res, indent);
}

QString LedGreenBlock::blockType() const
{
	return "ledGreenBlock";
}
