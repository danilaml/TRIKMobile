#include "absblock.h"

AbsBlock::AbsBlock(QObject *parent) : AbstractBlock(parent)
{

}

AbsBlock::AbsBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

AbsBlock::~AbsBlock()
{

}

QString AbsBlock::toString(int indent) const
{
	QString res = readTemplate("functions/abs.t");
	res.replace("@@ARGUMENT@@", mArgument);
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString AbsBlock::argument() const
{
	return mArgument;
}

void AbsBlock::setArgument(const QString &argument)
{
	mArgument = argument;
}
