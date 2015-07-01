#include "middleblock.h"
#include "blockmodel.h"

MiddleBlock::MiddleBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames<< "condition";
	propertyMap["condition"] = "M1";
	mChildren << new BlockModel();
}

MiddleBlock::~MiddleBlock()
{

}

QString MiddleBlock::toString(int indent) const
{
	QString res = readTemplate("switch/middle.t");
	QString body;
	if (mChildren.size() > 0) {
		body = mChildren.at(0)->toString(1);
	}
	res.replace("@@CONDITION@@", getProp("condition")).replace("@@BODY@@", body);
	return addIndent(res, indent);
}

QString MiddleBlock::blockType() const
{
	return "middleBlock";
}

QString HeadBlock::statusString() const
{
	return QString("Condition: %1").arg(getProp("condition"));
}

QString HeadBlock::condition() const
{
	return getProp("condition");
}

void HeadBlock::setCondition(const QString &condition)
{
	propertyMap["condition"] = condition;
}

