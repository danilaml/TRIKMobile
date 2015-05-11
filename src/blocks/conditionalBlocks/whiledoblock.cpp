#include "whiledoblock.h"
#include "blockmodel.h"

WhileDoBlock::WhileDoBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "condition";
	propertyMap["condition"] = "true";
	mChildren << new BlockModel();
}

WhileDoBlock::~WhileDoBlock()
{

}

QString WhileDoBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/whileDo.t");
	QString body;
	if (mChildren.size() > 0) {
		body = mChildren.at(0)->toString(1);
	}
	res.replace("@@CONDITION@@", getProp("condition")).replace("@@BODY@@", body);
	return addIndent(res, indent);
}

QString WhileDoBlock::blockType() const
{
	return "whileDoBlock";
}

QString WhileDoBlock::statusString() const
{
	return QString("Condition: %1").arg(getProp("condition"));
}

QString WhileDoBlock::condition() const
{
	return getProp("condition");
}

void WhileDoBlock::setCondition(const QString &condition)
{
	propertyMap["condition"] = condition;
}
