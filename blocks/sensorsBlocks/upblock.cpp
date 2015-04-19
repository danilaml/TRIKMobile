#include "upblock.h"

UpBlock::UpBlock(QObject *parent) : AbstractBlock(parent)
{

}

UpBlock::UpBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

UpBlock::~UpBlock()
{

}

QString UpBlock::toString(int indent) const
{
	QString res = readTemplate("sensors/Up.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
