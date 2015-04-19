#include "infiniteblock.h"
#include "blockmodel.h"

InfiniteBlock::InfiniteBlock(QObject *parent) : AbstractBlock(parent)
{

}

InfiniteBlock::~InfiniteBlock()
{

}

QString InfiniteBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/infinite.t");
	QString body;
	if (mChildren.size() > 0) {
		body = mChildren.at(0)->toString(1);
	}
	res.replace("@@BODY@@", body);
	return addIndent(res, indent);
}

QString InfiniteBlock::blockType() const
{
	return "infiniteBlock";
}
