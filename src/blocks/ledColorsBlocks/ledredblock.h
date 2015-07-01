#pragma once

#include "blocks/abstractblock.h"

class LedRedBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit LedRedBlock(QObject *parent = 0);
	virtual ~LedRedBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
