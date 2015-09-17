#include "onecaseblock.h"

OneCaseBlock::OneCaseBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "value";
	propertyMap["value"] = "value";
}

OneCaseBlock::~OneCaseBlock()
{

}

QString OneCaseBlock::toString(int indent) const
{
	QString res = readTemplate("switch/oneCase.t");
	res.replace("@@VALUE@@", getProp("value"));
	return addIndent(res, indent);
}

QString OneCaseBlock::blockType() const
{
	return "oneCaseBlock";
}

QString OneCaseBlock::statusString() const
{
	return QString("Value: %1").arg(getProp("value"));
}

QString OneCaseBlock::value() const
{
	return getProp("value");
}

void OneCaseBlock::setValue(const QString &value)
{
	propertyMap["value"] = value;
}
