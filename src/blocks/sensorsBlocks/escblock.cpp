#include "escblock.h"

EscBlock::EscBlock(QObject *parent) : AbstractBlock(parent)
{

}

EscBlock::~EscBlock()
{

}

QString EscBlock::toString(int indent) const
{
	QString res = readTemplate("sensors/Esc.t");
	return addIndent(res, indent);
}

QString EscBlock::blockType() const
{
	return "escBlock";
}
