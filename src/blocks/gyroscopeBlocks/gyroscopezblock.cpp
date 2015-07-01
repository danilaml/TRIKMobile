#include "gyroscopezblock.h"

GyroscopeZBlock::GyroscopeZBlock(QObject *parent) : AbstractBlock(parent)
{

}

GyroscopeZBlock::~GyroscopeZBlock()
{

}

QString GyroscopeZBlock::toString(int indent) const
{
	QString res = readTemplate("gyroscope/gyroscopeZ.t");
	return addIndent(res, indent);
}

QString GyroscopeZBlock::blockType() const
{
	return "gyroscopeZBlock";
}
