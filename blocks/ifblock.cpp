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
	res.replace("@@THEN_BODY@@", mThenBody).replace("@@CONDITION@@", mCondition);
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

QString IfBlock::thenBody() const
{
	return mThenBody;
}

void IfBlock::setThenBody(const QString &thenBody)
{
	mThenBody = thenBody;
}
