#include "ifblock.h"

IfBlock::IfBlock(QObject *parent) : AbstractBlock(parent)
{

}

IfBlock::IfBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

IfBlock::~IfBlock()
{

}

QString IfBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/if.t");
	res.replace("@@CONDITION@@", mCondition).replace("@@THEN_BODY@@", mThenBody->toString());
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString IfBlock::condition() const
{
	return mCondition;
}

void IfBlock::setCondition(const QString &condition)
{
	mCondition = condition;
}

QSharedPointer<AbstractBlock> IfBlock::thenBody() const
{
    return mThenBody;
}

void IfBlock::setThenBody(const QSharedPointer<AbstractBlock> &thenBody)
{
    mThenBody = thenBody;
}
