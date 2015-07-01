#pragma once

#include "blocks/abstractblock.h"

class GyroscopeYBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GyroscopeYBlock(QObject *parent = 0);
	virtual ~GyroscopeYBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
