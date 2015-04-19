#pragma once

#include "blocks/abstractblock.h"

class IntBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit IntBlock(QObject *parent = 0);
	IntBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~IntBlock();

	virtual QString toString(int indent = 0) const;
};
