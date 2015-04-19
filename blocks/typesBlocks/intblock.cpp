#include "intblock.h"

IntBlock::IntBlock(QObject *parent) : AbstractBlock(parent)
{

}

IntBlock::IntBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

IntBlock::~IntBlock()
{

}

QString IntBlock::toString(int indent) const
{
	QString res = readTemplate("types/int.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
