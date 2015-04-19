#include "headblock.h"

HeadBlock::HeadBlock(QObject *parent) : AbstractBlock(parent)
{

}

HeadBlock::HeadBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

HeadBlock::~HeadBlock()
{

}

QString HeadBlock::toString(int indent) const
{
	QString res = readTemplate("switch/head.t");
	res.replace("@@EXPRESSION@@", mExpression).replace("@@CONDITION@@", mCondition).replace("@@BODY@@", mBody->toString());
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString HeadBlock::expression() const
{
	return mExpression;
}

void HeadBlock::setExpression(const QString &expression)
{
	mExpression = expression;
}

QString HeadBlock::condition() const
{
	return mCondition;
}

void HeadBlock::setCondition(const QString &condition)
{
	mCondition = condition;
}

QSharedPointer<AbstractBlock> HeadBlock::body() const
{
	return mBody;
}

void HeadBlock::setBody(const QSharedPointer<AbstractBlock> &body)
{
	mBody = body;
}
