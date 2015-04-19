#include "additionblock.h"

AdditionBlock::AdditionBlock(QObject *parent) : AbstractBlock(parent)
{

}

AdditionBlock::AdditionBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

AdditionBlock::~AdditionBlock()
{

}

QString AdditionBlock::toString(int indent) const
{
	QString res = readTemplate("luaPrinting/addition.t");
	res.replace("@@LEFT@@", mLeft).replace("@@RIGHT@@", mRight);
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString AdditionBlock::left() const
{
    return mLeft;
}

void AdditionBlock::setLeft(const QString &left)
{
    mLeft = left;
}

QString AdditionBlock::right() const
{
    return mRight;
}

void AdditionBlock::setRight(const QString &right)
{
    mRight = right;
}
