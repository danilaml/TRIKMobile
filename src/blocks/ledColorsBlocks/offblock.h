#pragma once

#include "blocks/abstractblock.h"

class OffBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit OffBlock(QObject *parent = 0);
	virtual ~OffBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
