#pragma once

#include "blocks/abstractblock.h"

class InfiniteBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit InfiniteBlock(QObject *parent = 0);
	virtual ~InfiniteBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;

};
