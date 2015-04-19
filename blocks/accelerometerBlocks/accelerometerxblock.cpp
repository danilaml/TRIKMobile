#include "accelerometerxblock.h"

AccelerometerXBlock::AccelerometerXBlock(QObject *parent) : AbstractBlock(parent)
{

}

AccelerometerXBlock::AccelerometerXBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

AccelerometerXBlock::~AccelerometerXBlock()
{

}

QString AccelerometerXBlock::toString(int indent) const
{
	QString res = readTemplate("accelerometer/accelerometerX.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
