#include "infiniteblock.h"

InfiniteBlock::InfiniteBlock(QObject *parent) : AbstractBlock(parent)
{

}

InfiniteBlock::InfiniteBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

InfiniteBlock::~InfiniteBlock()
{

}

QString InfiniteBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/infinite.t");
	res.replace("@@BODY@@", mBody->toString());
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QSharedPointer<AbstractBlock> InfiniteBlock::body() const
{
	return mBody;
}

void InfiniteBlock::setBody(const QSharedPointer<AbstractBlock> &body)
{
	mBody = body;
}
