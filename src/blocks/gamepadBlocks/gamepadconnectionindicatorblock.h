#pragma once

#include "blocks/abstractblock.h"

class GamepadConnectionIndicatorBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GamepadConnectionIndicatorBlock(QObject *parent = 0);
	virtual ~GamepadConnectionIndicatorBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};

