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
	res.replace("@@PORT@@", mPort).replace("@@POWER@@", QString::number(mPower));
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

int ForwardBlock::power() const
{
	return mPower;
}

void ForwardBlock::setPower(int power)
{
	mPower = power;
}

QString ForwardBlock::port() const
{
	return mPort;
}

void ForwardBlock::setPort(const QString &port)
{
	mPort = port;
}



