#pragma once

#include "blocks/abstractblock.h"

class LedGreenBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit LedGreenBlock(QObject *parent = 0);
	LedGreenBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~LedGreenBlock();

	virtual QString toString(int indent = 0) const;
};
