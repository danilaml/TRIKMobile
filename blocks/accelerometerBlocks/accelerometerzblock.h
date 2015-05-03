#pragma once

#include "blocks/abstractblock.h"

class AccelerometerZBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AccelerometerZBlock(QObject *parent = 0);
	virtual ~AccelerometerZBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
