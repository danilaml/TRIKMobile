#include "gyroscopexblock.h"

GyroscopeXBlock::GyroscopeXBlock(QObject *parent) : AbstractBlock(parent)
{

}

GyroscopeXBlock::GyroscopeXBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

GyroscopeXBlock::~GyroscopeXBlock()
{

}

QString GyroscopeXBlock::toString(int indent) const
{
	QString res = readTemplate("gyroscope/gyroscopeX.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
