#include "dowhileblock.h"
#include "blockmodel.h"

DoWhileBlock::DoWhileBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "condition";
	propertyMap["condition"] = "true";
	mChildren << new BlockModel();
}

DoWhileBlock::~DoWhileBlock()
{

}

QString DoWhileBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/doWhile.t");
	QString body;
	if (mChildren.size() > 0) {
		body = mChildren.at(0)->toString(1);
	}
	res.replace("@@BODY@@", body).replace("@@CONDITION@@", getProp("condition"));
	return addIndent(res, indent);
}

QString DoWhileBlock::blockType() const
{
	return "doWhileBlock";
}

QString DoWhileBlock::statusString() const
{
	return QString("Condition: %1").arg(getProp("condition"));
}

QString DoWhileBlock::condition() const
{
	return getProp("condition");
}

void DoWhileBlock::setCondition(const QString &condition)
{
	propertyMap["condition"] = condition;
}
