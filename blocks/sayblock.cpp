#include "sayblock.h"

SayBlock::SayBlock(QObject *parent) : AbstractBlock(parent)
{
	propertyNames << "text";
	propertyMap["text"] = "Hello!";
}

SayBlock::~SayBlock()
{

}

QString SayBlock::toString(int indent) const
{
	QString res = readTemplate("say.t");
	res.replace("@@TEXT@@","\"" + getProp("text") + "\"");

	return addIndent(res, indent);
}

QString SayBlock::blockType() const
{
	return "sayBlock";
}

QString SayBlock::statusString() const
{
	return QString("Text: %1").arg(getProp("text"));
}

QString SayBlock::text() const
{
	return getProp("text");
}

void SayBlock::setText(const QString &text)
{
	propertyMap["text"] = text;
}
