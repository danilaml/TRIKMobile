#include "negationblock.h"
#include "blockmodel.h"

NegationBlock::NegationBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "condition";
	propertyMap["condition"] = "true";
}

NegationBlock::~NegationBlock()
{

}

QString NegationBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/negation.t");
	res.replace("@@CONDITION@@", getProp("condition"));
	return addIndent(res, indent);
}

QString NegationBlock::blockType() const
{
	return "negationBlock";
}

QString NegationBlock::statusString() const
{
	return QString("Condition: %1").arg(getProp("condition"));
}

QString NegationBlock::condition() const
{
	return getProp("condition");
}

void NegationBlock::setCondition(const QString &condition)
{
	propertyMap["condition"] = condition;
}
