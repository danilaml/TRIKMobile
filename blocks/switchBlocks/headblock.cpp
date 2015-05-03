#include "headblock.h"
#include "blockmodel.h"

HeadBlock::HeadBlock(QObject *parent) : AbstractBlock(parent)
{
	propertyNames << "expression" << "condition";
	propertyMap["expression"] = "port";
	propertyMap["condition"] = "M1";
}

HeadBlock::~HeadBlock()
{

}

QString HeadBlock::toString(int indent) const
{
	QString res = readTemplate("switch/head.t");
	QString body;
	if (mChildren.size() > 0) {
		body = mChildren.at(0)->toString(1);
	}
	res.replace("@@EXPRESSION@@", getProp("expression")).replace("@@CONDITION@@", getProp("condition")).replace("@@BODY@@", body);
	return addIndent(res, indent);
}

QString HeadBlock::blockType() const
{
	return "headBlock";
}

QString HeadBlock::statusString() const
{
	return QString("Expression: %1, Condition: %2").arg(getProp("expression"), getProp("condition"));
}

QString HeadBlock::expression() const
{
	return getProp("expression");
}

void HeadBlock::setExpression(const QString &expression)
{
	propertyMap["expression"] = expression;
}

QString HeadBlock::condition() const
{
	return getProp("condition");
}

void HeadBlock::setCondition(const QString &condition)
{
	propertyMap["condition"] = condition;
}
