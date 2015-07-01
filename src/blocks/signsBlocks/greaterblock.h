#pragma once

#include "blocks/abstractblock.h"

class GreaterBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GreaterBlock(QObject *parent = 0);
	virtual ~GreaterBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
