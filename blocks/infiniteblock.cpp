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
	res.replace("@@BODY@@", mBody);
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString InfiniteBlock::body() const
{
	return mBody;
}

void InfiniteBlock::setBody(const QString &body)
{
	mBody = body;
}
