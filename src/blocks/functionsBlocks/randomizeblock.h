#pragma once

#include "blocks/abstractblock.h"

class RandomizeBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit RandomizeBlock(QObject *parent = 0);
	virtual ~RandomizeBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};


