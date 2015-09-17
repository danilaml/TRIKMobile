#pragma once

#include "blocks/abstractblock.h"

class EnterBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit EnterBlock(QObject *parent = 0);
	virtual ~EnterBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
