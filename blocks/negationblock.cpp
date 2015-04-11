#include "negationblock.h"

NegationBlock::NegationBlock(QObject *parent) : AbstractBlock(parent)
{

}

NegationBlock::NegationBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

NegationBlock::~NegationBlock()
{

}

QString NegationBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/negation.t");
	res.replace("@@CONDITION@@", mCondition);
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString NegationBlock::condition() const
{
	return mCondition;
}

void NegationBlock::setCondition(const QString &condition)
{
	mCondition = condition;
}
