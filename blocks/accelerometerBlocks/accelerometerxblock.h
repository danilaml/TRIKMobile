#pragma once

#include "blocks/abstractblock.h"

class AccelerometerXBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AccelerometerXBlock(QObject *parent = 0);
	AccelerometerXBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~AccelerometerXBlock();

	virtual QString toString(int indent = 0) const;
};
