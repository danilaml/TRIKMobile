#pragma once

#include "blocks/abstractblock.h"

class GamepadButton1PortBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GamepadButton1PortBlock(QObject *parent = 0);
	virtual ~GamepadButton1PortBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
