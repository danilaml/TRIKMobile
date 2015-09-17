#include "notgreaterblock.h"

NotGreaterBlock::NotGreaterBlock(QObject *parent) : AbstractBlock(parent)
{

}

NotGreaterBlock::~NotGreaterBlock()
{

}

QString NotGreaterBlock::toString(int indent) const
{
	QString res = readTemplate("signs/notGreater.t");
	return addIndent(res, indent);
}

QString NotGreaterBlock::blockType() const
{
	return "notGreaterBlock";
}
