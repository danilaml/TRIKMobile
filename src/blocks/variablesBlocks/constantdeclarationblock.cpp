#include "constantdeclarationblock.h"

ConstantDeclarationBlock::ConstantDeclarationBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "name" << "value";
	propertyMap["name"] = "newName";
	propertyMap["value"] = "value";
}

ConstantDeclarationBlock::~ConstantDeclarationBlock()
{

}

QString ConstantDeclarationBlock::toString(int indent) const
{
	QString res = readTemplate("variables/constantDeclaration.t");
	res.replace("@@TYPE@@", "var").replace("@@NAME@@", getProp("name")).replace("@VALUE@", getProp("value"));
	return addIndent(res, indent);
}

QString ConstantDeclarationBlock::blockType() const
{
	return "constantDeclarationBlock";
}

QString ConstantDeclarationBlock::statusString() const
{
	return QString("Name: %1, Value: %2").arg(getProp("name"), getProp("value"));
}

QString ConstantDeclarationBlock::name() const
{
	return getProp("name");
}

void ConstantDeclarationBlock::setName(const QString &name)
{
	propertyMap["name"] = name;
}

QString ConstantDeclarationBlock::value() const
{
	return getProp("value");
}

void ConstantDeclarationBlock::setValue(const QString &value)
{
	propertyMap["value"] = value;
}
