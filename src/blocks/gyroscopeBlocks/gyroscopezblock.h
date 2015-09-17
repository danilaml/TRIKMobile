#pragma once

#include "blocks/abstractblock.h"

class GyroscopeZBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GyroscopeZBlock(QObject *parent = 0);
	virtual ~GyroscopeZBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
