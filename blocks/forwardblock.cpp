#include "forwardblock.h"

ForwardBlock::ForwardBlock(QObject *parent) : AbstractBlock(parent), mPort("M1"), mPower("100")
{
	propertyNames << "power" << "port";
}

//ForwardBlock::ForwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
//{

//}

ForwardBlock::~ForwardBlock()
{

}

QString ForwardBlock::toString(int indent) const
{
	QString res = readTemplate("engines/forward.t");
	res.replace("@@PORT@@", mPort).replace("@@POWER@@", mPower);
//	if (!mNext.isNull()) {
//		res.append(mNext->toString());
//	}
	return addIndent(res, indent);
}

QString ForwardBlock::blockType() const
{
	return "forwardblock";
}

QString ForwardBlock::statusString() const
{
	return QString("Port: %1, Power: %2").arg(mPort, mPower);
}

QString ForwardBlock::power() const
{
	return mPower;
}

void ForwardBlock::setPower(const QString &power)
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



