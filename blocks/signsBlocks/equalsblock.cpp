#include "equalsblock.h"

EqualsBlock::EqualsBlock(QObject *parent) : AbstractBlock(parent)
{

}

EqualsBlock::EqualsBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

EqualsBlock::~EqualsBlock()
{

}

QString EqualsBlock::toString(int indent) const
{
	QString res = readTemplate("signs/equals.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
