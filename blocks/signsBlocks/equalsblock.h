#pragma once

#include "blocks/abstractblock.h"

class EqualsBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit EqualsBlock(QObject *parent = 0);
	EqualsBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~EqualsBlock();

	virtual QString toString(int indent = 0) const;
};
