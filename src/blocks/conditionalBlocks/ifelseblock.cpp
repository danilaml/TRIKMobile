#include "ifelseblock.h"
#include "blockmodel.h"

IfElseBlock::IfElseBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "condition";
	propertyMap["condition"] = "true";
}

IfElseBlock::~IfElseBlock()
{
	mChildren << new BlockModel() << new BlockModel();
}

QString IfElseBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/ifElse.t");
	QString thenBody;
	QString elseBody;
	if (mChildren.size() > 0) {
		thenBody = mChildren.at(0)->toString(1);
		elseBody = mChildren.at(1)->toString(1);
	}
	res.replace("@@CONDITION@@", getProp("condition")).replace("@@THEN_BODY@@", thenBody).replace("@@ELSE_BODY@@", elseBody);
	return addIndent(res, indent);
}

QString IfElseBlock::blockType() const
{
	return "ifElseBlock";
}

QString IfElseBlock::statusString() const
{
	return QString("Condition: %1").arg(getProp("condition"));
}

QString IfElseBlock::condition() const
{
	return getProp("condition");
}

void IfElseBlock::setCondition(const QString &condition)
{
	propertyMap["condition"] = condition;
}
