#include "timeblock.h"

TimeBlock::TimeBlock(QObject *parent) : AbstractBlock(parent)
{

}

TimeBlock::~TimeBlock()
{

}

QString TimeBlock::toString(int indent) const
{
	QString res = readTemplate("functions/time.t");
	return addIndent(res, indent);
}

QString TimeBlock::blockType() const
{
	return "timeBlock";
}

