#include "forblock.h"
#include "blockmodel.h"

ForBlock::ForBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "iterator" << "initialValue" << "bound";
	propertyMap["iterator"] = "i";
	propertyMap["initialValue"] = "0";
	propertyMap["bound"] = "10";
}

ForBlock::~ForBlock()
{

}

QString ForBlock::toString(int indent) const
{
	QString res = readTemplate("conditional/for.t");
	QString body;
	if (mChildren.size() > 0) {
		body = mChildren.at(0)->toString(1);
	}
	res.replace("@@ITERATOR_TYPE@@", "var").replace("@@ITERATOR@@", getProp("iterator"));
	res.replace("@@INITIAL_VALUE@@", getProp("initialValue")).replace("@@BOUND@@", getProp("bound"));
	res.replace("@@BODY@@", body);
	return addIndent(res, indent);
}

QString ForBlock::blockType() const
{
	return "forBlock";
}

QString ForBlock::statusString() const
{
	return QString("Iterator: %1, InitialValue: %2, Bound: %3").arg(getProp("iterator"), getProp("initialValue"), getProp("bound"));
}

QString ForBlock::iterator() const
{
	return getProp("iterator");
}

void ForBlock::setIterator(const QString &iterator)
{
	propertyMap["iterator"] = iterator;
}

QString ForBlock::initialValue() const
{
	return getProp("initialValue");
}

void ForBlock::setInitialValue(const QString &initialValue)
{
	propertyMap["initialValue"] = initialValue;
}

QString ForBlock::bound() const
{
	return getProp("bound");
}

void ForBlock::setBound(const QString &bound)
{
	propertyMap["bound"] = bound;
}
