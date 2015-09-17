#include "defaultblock.h"
#include "blockmodel.h"

DefaultBlock::DefaultBlock(QObject *parent) : AbstractBlock(parent)
{
	mChildren << new BlockModel();
}

DefaultBlock::~DefaultBlock()
{

}

QString DefaultBlock::toString(int indent) const
{
	QString res = readTemplate("switch/default.t");
	QString body;
	if (mChildren.size() > 0) {
		body = mChildren.at(0)->toString(1);
	}
	res.replace("@@BODY@@", body);
	return addIndent(res, indent);
}

QString DefaultBlock::blockType() const
{
	return "defaultBlock";
}
