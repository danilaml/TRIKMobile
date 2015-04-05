#pragma once

#include "blocks/abstractblock.h"

class TimerBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit TimerBlock(QObject *parent = 0);
	TimerBlock(QSharedPointer<AbstractBlock> &n, QObject *parent = 0);
	virtual ~TimerBlock();

	virtual QString toString(int indent = 0) const;

	int delay() const;
	void setDelay(int delay);

private:
	int mDelay;
};
