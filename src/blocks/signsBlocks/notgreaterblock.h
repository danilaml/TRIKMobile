#pragma once

#include "blocks/abstractblock.h"

class NotGreaterBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit NotGreaterBlock(QObject *parent = 0);
	virtual ~NotGreaterBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
