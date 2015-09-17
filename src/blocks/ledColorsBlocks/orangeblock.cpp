#include "orangeblock.h"

OrangeBlock::OrangeBlock(QObject *parent) : AbstractBlock(parent)
{

}

OrangeBlock::~OrangeBlock()
{

}

QString OrangeBlock::toString(int indent) const
{
	QString res = readTemplate("ledColors/orange.t");
	return addIndent(res, indent);
}

QString OrangeBlock::blockType() const
{
	return "orangeBlock";
}
