#include "enterblock.h"

EnterBlock::EnterBlock(QObject *parent) : AbstractBlock(parent)
{

}

EnterBlock::~EnterBlock()
{

}

QString EnterBlock::toString(int indent) const
{
	QString res = readTemplate("sensors/Enter.t");
	return addIndent(res, indent);
}

QString EnterBlock::blockType() const
{
	return "enterBlock";
}
