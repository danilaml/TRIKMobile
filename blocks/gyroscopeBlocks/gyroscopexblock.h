#pragma once

#include "blocks/abstractblock.h"

class GyroscopeXBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GyroscopeXBlock(QObject *parent = 0);
	virtual ~GyroscopeXBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
