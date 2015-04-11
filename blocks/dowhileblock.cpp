#include "dowhileblock.h"

DoWhileBlock::DoWhileBlock(QObject *parent) : AbstractBlock(parent)
{

}

DoWhileBlock::DoWhileBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

DoWhileBlock::~DoWhileBlock()
{

}

QString DoWhileBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/doWhile.t");
	res.replace("@@BODY@@", mBody).replace("@@CONDITION@@", mCondition);
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString DoWhileBlock::body() const
{
	return mBody;
}

void DoWhileBlock::setBody(const QString &body)
{
	mBody = body;
}

QString DoWhileBlock::condition() const
{
	return mCondition;
}

void DoWhileBlock::setCondition(const QString &condition)
{
	mCondition = condition;
}
