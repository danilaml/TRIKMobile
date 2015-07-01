#pragma once

#include "blocks/abstractblock.h"

class ClearScreenBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit ClearScreenBlock(QObject *parent = 0);
	virtual ~ClearScreenBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};


