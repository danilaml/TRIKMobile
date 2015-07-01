#pragma once

#include "blocks/abstractblock.h"

class LeftBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit LeftBlock(QObject *parent = 0);
	virtual ~LeftBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
