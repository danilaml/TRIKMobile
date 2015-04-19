#include "greenblock.h"

GreenBlock::GreenBlock(QObject *parent) : AbstractBlock(parent)
{

}

GreenBlock::GreenBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

GreenBlock::~GreenBlock()
{

}

QString GreenBlock::toString(int indent) const
{
	QString res = readTemplate("backgroundColors/green.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
