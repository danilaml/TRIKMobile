#include "backwardblock.h"

BackwardBlock::BackwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

BackwardBlock::~BackwardBlock()
{

}

QString BackwardBlock::toString(int ident) const
{
	QString res = readAll(":/engines/backward.t");
	return res.replace("@@POWER@@", QString::number(mPower));
}
