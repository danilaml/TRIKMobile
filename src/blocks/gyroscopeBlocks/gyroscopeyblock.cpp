#include "gyroscopeyblock.h"

GyroscopeYBlock::GyroscopeYBlock(QObject *parent) : AbstractBlock(parent)
{

}

GyroscopeYBlock::~GyroscopeYBlock()
{

}

QString GyroscopeYBlock::toString(int indent) const
{
	QString res = readTemplate("gyroscope/gyroscopeY.t");
	return addIndent(res, indent);
}

QString GyroscopeYBlock::blockType() const
{
	return "gyroscopeYBlock";
}
