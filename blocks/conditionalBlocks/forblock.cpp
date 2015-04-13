#include "forblock.h"

ForBlock::ForBlock(QObject *parent) : AbstractBlock(parent)
{

}

ForBlock::ForBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

ForBlock::~ForBlock()
{

}

QString ForBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/for.t");
	res.replace("@@ITERATOR_TYPE@@", mIteratorType).replace("@@ITERATOR@@", mIterator);
	res.replace("@@INITIAL_VALUE@@", mInitialValue).replace("@@BOUND@@", mBound).replace("@@BODY@@", mBody->toString());
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString ForBlock::iteratorType() const
{
	return mIteratorType;
}

void ForBlock::setIteratorType(const QString &iteratorType)
{
	mIteratorType = iteratorType;
}

QString ForBlock::iterator() const
{
	return mIterator;
}

void ForBlock::setIterator(const QString &iterator)
{
	mIterator = iterator;
}

QString ForBlock::initialValue() const
{
	return mInitialValue;
}

void ForBlock::setInitialValue(const QString &initialValue)
{
	mInitialValue = initialValue;
}

QString ForBlock::bound() const
{
	return mBound;
}

void ForBlock::setBound(const QString &bound)
{
	mBound = bound;
}

QSharedPointer<AbstractBlock> ForBlock::body() const
{
    return mBody;
}

void ForBlock::setBody(const QSharedPointer<AbstractBlock> &body)
{
    mBody = body;
}
