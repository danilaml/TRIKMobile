#include "backwardblock.h"

BackwardBlock::BackwardBlock(QObject *parent) : AbstractBlock(parent)
{

}

BackwardBlock::BackwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

BackwardBlock::~BackwardBlock()
{

}

QString BackwardBlock::toString(int indent) const
{
	QString res = readTemplate("qrc:/engines/backward.t");
	return addIndent(res.replace("@@POWER@@", QString::number(mPower)), indent);
}
int BackwardBlock::power() const
{
	return mPower;
}

void BackwardBlock::setPower(int power)
{
	mPower = power;
}

