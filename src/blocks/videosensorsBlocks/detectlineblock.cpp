#include "detectlineblock.h"

DetectLineBlock::DetectLineBlock(QObject *parent) : AbstractBlock(parent)
{

}

DetectLineBlock::~DetectLineBlock()
{

}

QString DetectLineBlock::toString(int indent) const
{
	QString res = readTemplate("videosensors/detectline.t");
	return addIndent(res, indent);
}

QString DetectLineBlock::blockType() const
{
	return "detectLineBlock";
}
