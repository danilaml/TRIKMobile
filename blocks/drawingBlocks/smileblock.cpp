#include "smileblock.h"

SmileBlock::SmileBlock(QObject *parent) : AbstractBlock(parent)
{

}

SmileBlock::~SmileBlock()
{

}

QString SmileBlock::toString(int indent) const
{
	QString res = readTemplate("drawing/smile.t");
	return addIndent(res, indent);
}

QString SmileBlock::blockType() const
{
	return "smileBlock";
}
