#include "accelerometeryblock.h"

AccelerometerYBlock::AccelerometerYBlock(QObject *parent) : AbstractBlock(parent)
{

}

AccelerometerYBlock::~AccelerometerYBlock()
{

}

QString AccelerometerYBlock::toString(int indent) const
{
	QString res = readTemplate("accelerometer/accelerometerY.t");
	return addIndent(res, indent);
}

QString AccelerometerYBlock::blockType() const
{
	return "accelerometerYBlock";
}

