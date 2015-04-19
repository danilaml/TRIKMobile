#include "smileblock.h"

SmileBlock::SmileBlock(QObject *parent) : AbstractBlock(parent)
{

}

SmileBlock::SmileBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

SmileBlock::~SmileBlock()
{

}

QString SmileBlock::toString(int indent) const
{
	QString res = readTemplate("drawing/smile.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
