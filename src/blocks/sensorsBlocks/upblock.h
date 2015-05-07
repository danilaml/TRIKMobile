#pragma once

#include "blocks/abstractblock.h"

class UpBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit UpBlock(QObject *parent = 0);
	virtual ~UpBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
