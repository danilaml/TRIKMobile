#include "clearscreenblock.h"

ClearScreenBlock::ClearScreenBlock(QObject *parent) : AbstractBlock(parent)
{

}

ClearScreenBlock::~ClearScreenBlock()
{

}

QString ClearScreenBlock::toString(int indent) const
{
	QString res = readTemplate("drawing/clearScreen.t");
	return addIndent(res, indent);
}

QString ClearScreenBlock::blockType() const
{
	return "clearScreenBlock";
}
