#include "ifblock.h"
#include "blockmodel.h"

IfBlock::IfBlock(QObject *parent) : AbstractBlock(parent)
{
	propertyNames << "condition";
	propertyMap["condition"] = "true";
}

IfBlock::~IfBlock()
{

}

QString IfBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/if.t");
	QString thenBody;
	if (mChildren.size() > 0) {
		thenBody = mChildren.at(0)->toString(1);
	}
	res.replace("@@CONDITION@@", getProp("condition")).replace("@@THEN_BODY@@", thenBody);
	return addIndent(res, indent);
}

QString IfBlock::blockType() const
{
	return "ifBlock";
}

QString IfBlock::statusString() const
{
	return QString("Condition: %1").arg(getProp("condition"));
}

QString IfBlock::condition() const
{
	return getProp("condition");
}

void IfBlock::setCondition(const QString &condition)
{
	propertyMap["condition"] = condition;
}
