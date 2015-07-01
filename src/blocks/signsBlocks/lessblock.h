#pragma once

#include "blocks/abstractblock.h"

class LessBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit LessBlock(QObject *parent = 0);
	virtual ~LessBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
