#include "accelerometerxblock.h"

AccelerometerXBlock::AccelerometerXBlock(QObject *parent) : AbstractBlock(parent)
{

}

AccelerometerXBlock::~AccelerometerXBlock()
{

}

QString AccelerometerXBlock::toString(int indent) const
{
	QString res = readTemplate("accelerometer/accelerometerX.t");
	return addIndent(res, indent);
}

QString AccelerometerXBlock::blockType() const
{
	return "accelerometerXBlock";
}
