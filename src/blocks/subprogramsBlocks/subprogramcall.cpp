#include "subprogramcallblock.h"

SubprogramCallBlock::SubprogramCallBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "name";
	propertyMap["name"] = "newFunction";
}

SubprogramCallBlock::~SubprogramCallBlock()
{

}

QString SubprogramCallBlock::toString(int indent) const
{
	QString res = readTemplate("subprograms/subprogramCall.t");
	res.replace("@@NAME@@", getProp("name"));

	return addIndent(res, indent);
}

QString SubprogramCallBlock::blockType() const
{
	return "subprogramCallBlock";
}

QString SubprogramCallBlock::statusString() const
{
	return QString("Name: %1").arg(getProp("name"));
}

QString SubprogramCallBlock::name() const
{
	return getProp("name");
}

void SubprogramCallBlock::setName(const QString &name)
{
	propertyMap["name"] = name;
}
