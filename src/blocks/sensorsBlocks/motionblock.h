#pragma once

#include "blocks/abstractblock.h"

class MotionBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit MotionBlock(QObject *parent = 0);
	virtual ~MotionBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
