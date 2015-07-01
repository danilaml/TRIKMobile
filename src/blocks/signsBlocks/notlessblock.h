#pragma once

#include "blocks/abstractblock.h"

class NotLessBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit NotLessBlock(QObject *parent = 0);
	virtual ~NotLessBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
