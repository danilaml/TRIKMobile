#include "sadsmileblock.h"

SadSmileBlock::SadSmileBlock(QObject *parent) : AbstractBlock(parent)
{

}

SadSmileBlock::SadSmileBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

SadSmileBlock::~SadSmileBlock()
{

}

QString SadSmileBlock::toString(int indent) const
{
	QString res = readTemplate("drawing/sadSmile.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
