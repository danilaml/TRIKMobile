#pragma once

#include "blocks/abstractblock.h"

class RightBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit RightBlock(QObject *parent = 0);
	virtual ~RightBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
