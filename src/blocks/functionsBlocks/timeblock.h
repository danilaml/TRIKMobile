#pragma once

#include "blocks/abstractblock.h"

class TimeBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit TimeBlock(QObject *parent = 0);
	virtual ~TimeBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};

