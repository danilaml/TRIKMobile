#include "forwardblock.h"

ForwardBlock::ForwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

ForwardBlock::~ForwardBlock()
{

}

QString ForwardBlock::toString(int ident) const
{
	QString res = readAll(":/engines/forward.t");
	return res.replace("@@POWER@@", QString::number(mPower));
}

