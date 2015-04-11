#include "sayblock.h"

SayBlock::SayBlock(QObject *parent) : AbstractBlock(parent)
{

}

SayBlock::SayBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

SayBlock::~SayBlock()
{

}

QString SayBlock::toString(int indent) const
{
	QString res = readTemplate("say.t");
	res.replace("@@TEXT@@","\"" + mText + "\"");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

QString SayBlock::text() const
{
	return mText;
}

void SayBlock::setText(const QString &text)
{
	mText = text;
}
