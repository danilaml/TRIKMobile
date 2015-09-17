#include "notlessblock.h"

NotLessBlock::NotLessBlock(QObject *parent) : AbstractBlock(parent)
{

}

NotLessBlock::~NotLessBlock()
{

}

QString NotLessBlock::toString(int indent) const
{
	QString res = readTemplate("signs/notLess.t");
	return addIndent(res, indent);
}

QString NotLessBlock::blockType() const
{
	return "notLessBlock";
}
