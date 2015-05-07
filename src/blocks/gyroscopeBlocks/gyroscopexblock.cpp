#include "gyroscopexblock.h"

GyroscopeXBlock::GyroscopeXBlock(QObject *parent) : AbstractBlock(parent)
{

}

GyroscopeXBlock::~GyroscopeXBlock()
{

}

QString GyroscopeXBlock::toString(int indent) const
{
	QString res = readTemplate("gyroscope/gyroscopeX.t");
	return addIndent(res, indent);
}

QString GyroscopeXBlock::blockType() const
{
	return "gyroscopeXBlock";
}
