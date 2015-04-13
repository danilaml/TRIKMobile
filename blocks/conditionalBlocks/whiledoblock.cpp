#include "whiledoblock.h"

WhileDoBlock::WhileDoBlock(QObject *parent) : AbstractBlock(parent)
{

}

WhileDoBlock::WhileDoBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

WhileDoBlock::~WhileDoBlock()
{

}

QString WhileDoBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/whileDo.t");
	res.replace("@@CONDITION@@", mCondition).replace("@@BODY@@", mBody->toString());
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString WhileDoBlock::condition() const
{
	return mCondition;
}

void WhileDoBlock::setCondition(const QString &condition)
{
	mCondition = condition;
}

QSharedPointer<AbstractBlock> WhileDoBlock::body() const
{
    return mBody;
}

void WhileDoBlock::setBody(const QSharedPointer<AbstractBlock> &body)
{
    mBody = body;
}
