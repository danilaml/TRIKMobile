#pragma once

#include "blocks/abstractblock.h"

class GreenBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GreenBlock(QObject *parent = 0);
	virtual ~GreenBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
