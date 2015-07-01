#pragma once

#include "blocks/abstractblock.h"

class GamepadWheelBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GamepadWheelBlock(QObject *parent = 0);
	virtual ~GamepadWheelIndicatorBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};

