#include "upblock.h"

UpBlock::UpBlock(QObject *parent) : AbstractBlock(parent)
{

}

UpBlock::~UpBlock()
{

}

QString UpBlock::toString(int indent) const
{
	QString res = readTemplate("sensors/Up.t");
	return addIndent(res, indent);
}

QString UpBlock::blockType() const
{
	return "upBlock";
}
