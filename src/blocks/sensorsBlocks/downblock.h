#pragma once

#include "blocks/abstractblock.h"

class DownBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit DownBlock(QObject *parent = 0);
	virtual ~DownBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
