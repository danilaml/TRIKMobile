#include "implementationblock.h"

ImplementationBlock::ImplementationBlock(QObject *parent) : AbstractBlock(parent)
{

}

ImplementationBlock::ImplementationBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

ImplementationBlock::~ImplementationBlock()
{

}

QString ImplementationBlock::toString(int indent) const
{
	QString res = readTemplate("subprograms/implementation.t");
	res.replace("@@NAME@@", mName).replace("@@BODY@@", mBody->toString());
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString ImplementationBlock::name() const
{
	return mName;
}

void ImplementationBlock::setName(const QString &name)
{
	mName = name;
}

QSharedPointer<AbstractBlock> ImplementationBlock::body() const
{
	return mBody;
}

void ImplementationBlock::setBody(const QSharedPointer<AbstractBlock> &body)
{
	mBody = body;
}
