#include "additionblock.h"

AdditionBlock::AdditionBlock(QObject *parent) : AbstractBlock(parent)
{
	propertyNames << "left" << "right";
	propertyMap["left"] = "1";
	propertyMap["right"] = "2";
}

AdditionBlock::~AdditionBlock()
{

}

QString AdditionBlock::toString(int indent) const
{
	QString res = readTemplate("luaPrinting/addition.t");
	res.replace("@@LEFT@@", getProp("left")).replace("@@RIGHT@@", getProp("right"));
	return addIndent(res, indent);
}

QString AdditionBlock::blockType() const
{
	return "additionBlock";
}

QString AdditionBlock::statusString() const
{
	return QString("Left: %1, Right: %2").arg(getProp("left"), getProp("right"));
}

QString AdditionBlock::left() const
{
	return getProp("left");
}

void AdditionBlock::setLeft(const QString &left)
{
	propertyMap["left"] = left;
}

QString AdditionBlock::right() const
{
	return getProp("right");
}

void AdditionBlock::setRight(const QString &right)
{
	propertyMap["right"] = right;
}
