#include "ledgreenblock.h"

LedGreenBlock::LedGreenBlock(QObject *parent) : AbstractBlock(parent)
{

}

LedGreenBlock::LedGreenBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

LedGreenBlock::~LedGreenBlock()
{

}

QString LedGreenBlock::toString(int indent) const
{
	QString res = readTemplate("ledColors/green.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
