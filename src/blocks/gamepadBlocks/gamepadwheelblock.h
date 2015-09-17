#pragma once

#include "blocks/abstractblock.h"

class GamepadWheelBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GamepadWheelBlock(QObject *parent = 0);
	virtual ~GamepadWheelBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};

