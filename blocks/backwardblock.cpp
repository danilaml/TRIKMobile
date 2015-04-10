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
	QString res = readTemplate("engines/backward.t");
	res.replace("@@PORT@@", mPort).replace("@@POWER@@", QString::number(mPower));
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

int BackwardBlock::power() const
{
	return mPower;
}

void BackwardBlock::setPower(int power)
{
	mPower = power;
}

QString BackwardBlock::port() const
{
	return mPort;
}

void BackwardBlock::setPort(const QString &port)
{
	mPort = port;
}


