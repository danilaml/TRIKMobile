#include "detectlineblock.h"

DetectLineBlock::DetectLineBlock(QObject *parent) : AbstractBlock(parent)
{

}

DetectLineBlock::DetectLineBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

DetectLineBlock::~DetectLineBlock()
{

}

QString DetectLineBlock::toString(int indent) const
{
	QString res = readTemplate("videosensors/detectline.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
