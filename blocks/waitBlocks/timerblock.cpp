#include "timerblock.h"

TimerBlock::TimerBlock(QObject *parent) : AbstractBlock(parent)
{
	propertyNames << "delay";
	propertyMap["delay"] = "1000";
}

TimerBlock::~TimerBlock()
{

}

QString TimerBlock::toString(int indent) const
{
	QString res = readTemplate("wait/timer.t");
	res.replace("@@DELAY@@", getProp("delay"));

	return addIndent(res, indent);
}

QString TimerBlock::blockType() const
{
	return "timerBlock";
}

QString TimerBlock::statusString() const
{
	return QString("Delay: %1").arg(getProp("delay"));
}

QString TimerBlock::delay() const
{
	return getProp("delay");
}

void TimerBlock::setDelay(const QString &delay)
{
	propertyMap["delay"] = delay;
}
