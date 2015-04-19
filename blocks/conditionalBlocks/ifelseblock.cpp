#include "ifelseblock.h"

IfElseBlock::IfElseBlock(QObject *parent) : AbstractBlock(parent)
{

}

IfElseBlock::IfElseBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

IfElseBlock::~IfElseBlock()
{

}

QString IfElseBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/ifElse.t");
	res.replace("@@CONDITION@@", mCondition).replace("@@THEN_BODY@@", mThenBody->toString()).replace("@@ELSE_BODY@@",mElseBody->toString());
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString IfElseBlock::condition() const
{
	return mCondition;
}

void IfElseBlock::setCondition(const QString &condition)
{
	mCondition = condition;
}

QSharedPointer<AbstractBlock> IfElseBlock::thenBody() const
{
	return mThenBody;
}

void IfElseBlock::setThenBody(const QSharedPointer<AbstractBlock> &thenBody)
{
	mThenBody = thenBody;
}

QSharedPointer<AbstractBlock> IfElseBlock::elseBody() const
{
	return mElseBody;
}

void IfElseBlock::setElseBody(const QSharedPointer<AbstractBlock> &elseBody)
{
	mElseBody = elseBody;
}
