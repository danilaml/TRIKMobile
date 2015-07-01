#include "offblock.h"

OffBlock::OffBlock(QObject *parent) : AbstractBlock(parent)
{

}

OffBlock::~OffBlock()
{

}

QString OffBlock::toString(int indent) const
{
	QString res = readTemplate("ledColors/off.t");
	return addIndent(res, indent);
}

QString OffBlock::blockType() const
{
	return "offBlock";
}
