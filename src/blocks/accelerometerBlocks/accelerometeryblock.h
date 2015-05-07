#pragma once

#include "blocks/abstractblock.h"

class AccelerometerYBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AccelerometerYBlock(QObject *parent = 0);
	virtual ~AccelerometerYBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
