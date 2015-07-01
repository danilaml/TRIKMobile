#include "motionblock.h"

MotionBlock::MotionBlock(QObject *parent) : AbstractBlock(parent)
{

}

MotionBlock::~MotionBlock()
{

}

QString MotionBlock::toString(int indent) const
{
	QString res = readTemplate("sensors/motion.t");
	return addIndent(res, indent);
}

QString MotionBlock::blockType() const
{
	return "motionBlock";
}

