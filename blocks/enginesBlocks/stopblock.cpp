#include "stopblock.h"

StopBlock::StopBlock(QObject *parent) : AbstractBlock(parent)
{

}

StopBlock::StopBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

StopBlock::~StopBlock()
{

}

QString StopBlock::toString(int indent) const
{
	QString res = readTemplate("engines/stop.t");
	res.replace("@@PORT@@", QString::number(mPort));
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

int StopBlock::port() const
{
	return mPort;
}

void StopBlock::setPort(int port)
{
	mPort = port;
}
