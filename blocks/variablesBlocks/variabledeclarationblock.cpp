#include "variabledeclarationblock.h"

VariableDeclarationBlock::VariableDeclarationBlock(QObject *parent) : AbstractBlock(parent)
{

}

VariableDeclarationBlock::VariableDeclarationBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

VariableDeclarationBlock::~VariableDeclarationBlock()
{

}

QString VariableDeclarationBlock::toString(int indent) const
{
	QString res = readTemplate("variables/variableDeclaration.t");
	res.replace("@@TYPE@@", mType).replace("@@NAME@@", mName);
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString VariableDeclarationBlock::type() const
{
	return mType;
}

void VariableDeclarationBlock::setType(const QString &type)
{
	mType = type;
}

QString VariableDeclarationBlock::name() const
{
	return mName;
}

void VariableDeclarationBlock::setName(const QString &name)
{
	mName = name;
}
