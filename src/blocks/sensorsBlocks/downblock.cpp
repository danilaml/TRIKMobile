#include "downblock.h"

DownBlock::DownBlock(QObject *parent) : AbstractBlock(parent)
{

}

DownBlock::~DownBlock()
{

}

QString DownBlock::toString(int indent) const
{
	QString res = readTemplate("sensors/Down.t");
	return addIndent(res, indent);
}

QString DownBlock::blockType() const
{
	return "downBlock";
}

