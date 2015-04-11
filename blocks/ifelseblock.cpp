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
	res.replace("@@THEN_BODY@@", mThenBody).replace("@@ELSE_BODY@@",mElseBody).replace("@@CONDITION@@", mCondition);
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

QString IfElseBlock::thenBody() const
{
	return mThenBody;
}

void IfElseBlock::setThenBody(const QString &thenBody)
{
	mThenBody = thenBody;
}

QString IfElseBlock::elseBody() const
{
	return mElseBody;
}

void IfElseBlock::setElseBody(const QString &elseBody)
{
	mElseBody = elseBody;
}
