#include "variabledeclarationblock.h"

VariableDeclarationBlock::VariableDeclarationBlock(QObject *parent) : AbstractBlock(parent)
{
	propertyNames << "name";
	propertyMap["name"] = "newName";
}

VariableDeclarationBlock::~VariableDeclarationBlock()
{

}

QString VariableDeclarationBlock::toString(int indent) const
{
	QString res = readTemplate("variables/variableDeclaration.t");
	res.replace("@@TYPE@@", "var").replace("@@NAME@@", getProp("name"));
	return addIndent(res, indent);
}

QString VariableDeclarationBlock::blockType() const
{
	return "variableDeclarationBlock";
}

QString VariableDeclarationBlock::statusString() const
{
	return QString("Name: %1").arg(getProp("name"));
}

QString VariableDeclarationBlock::name() const
{
	return getProp("name");
}

void VariableDeclarationBlock::setName(const QString &name)
{
	propertyMap["name"] = name;
}
