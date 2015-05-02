#pragma once

#include "blocks/abstractblock.h"

class TimerBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit TimerBlock(QObject *parent = 0);
	virtual ~TimerBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString delay() const;
	void setDelay(const QString &delay);
};
