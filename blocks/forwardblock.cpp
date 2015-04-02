#include "forwardblock.h"

ForwardBlock::ForwardBlock(QObject *parent) : AbstractBlock(parent)
{

}

ForwardBlock::ForwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

ForwardBlock::~ForwardBlock()
{

}

QString ForwardBlock::toString(int indent) const
{
	QString res = readTemplate("engines/forward.t");
	return addIndent(res.replace("@@POWER@@", QString::number(mPower)), indent);
}
int ForwardBlock::power() const
{
	return mPower;
}

void ForwardBlock::setPower(int power)
{
	mPower = power;
}


