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
	res.replace("@@CONDITION@@", mCondition).replace("@@BODY@@", mBody);
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

QString WhileDoBlock::body() const
{
	return mBody;
}

void WhileDoBlock::setBody(const QString &body)
{
	mBody = body;
}
