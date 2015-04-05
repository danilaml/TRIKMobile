#include "timerblock.h"

TimerBlock::TimerBlock(QObject *parent) : AbstractBlock(parent)
{

}

TimerBlock::TimerBlock(QSharedPointer<AbstractBlock> &n, QObject *parent) : AbstractBlock(n, parent)
{

}

TimerBlock::~TimerBlock()
{

}

QString TimerBlock::toString(int indent) const
{
	QString res = readTemplate("wait/timer.t");
	res.replace("@@DELAY@@",QString::number(mDelay));
	return addIndent(res, indent);
}

int TimerBlock::delay() const
{
	return mDelay;
}

void TimerBlock::setDelay(int delay)
{
	mDelay = delay;
}


