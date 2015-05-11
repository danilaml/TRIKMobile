#include "implementationblock.h"
#include "blockmodel.h"

ImplementationBlock::ImplementationBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "name";
	propertyMap["name"] = "newFunction";
	mChildren << new BlockModel();
}

ImplementationBlock::~ImplementationBlock()
{

}

QString ImplementationBlock::toString(int indent) const
{
	QString res = readTemplate("subprograms/implementation.t");
	QString body;
	if (mChildren.size() > 0) {
		body = mChildren.at(0)->toString(1);
	}
	res.replace("@@NAME@@", getProp("name")).replace("@@BODY@@", body);
	return addIndent(res, indent);
}

QString ImplementationBlock::blockType() const
{
	return "implementationBlock";
}

QString ImplementationBlock::statusString() const
{
	return QString("Name: %1").arg(getProp("name"));
}

QString ImplementationBlock::name() const
{
	return getProp("name");
}

void ImplementationBlock::setName(const QString &name)
{
	propertyMap["name"] = name;
}
