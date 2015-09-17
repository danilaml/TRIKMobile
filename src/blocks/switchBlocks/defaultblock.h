#pragma once

#include "blocks/abstractblock.h"

class DefaultBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit DefaultBlock(QObject *parent = 0);
	virtual ~DefaultBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
