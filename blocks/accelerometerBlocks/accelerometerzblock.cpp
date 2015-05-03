#include "accelerometerzblock.h"

AccelerometerZBlock::AccelerometerZBlock(QObject *parent) : AbstractBlock(parent)
{

}

AccelerometerZBlock::~AccelerometerZBlock()
{

}

QString AccelerometerZBlock::toString(int indent) const
{
	QString res = readTemplate("accelerometer/accelerometerZ.t");
	return addIndent(res, indent);
}

QString AccelerometerZBlock::blockType() const
{
	return "accelerometerZBlock";
}

