#pragma once

#include "blocks/abstractblock.h"

class GamepadPadBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GamepadPadBlock(QObject *parent = 0);
	virtual ~GamepadPadBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString port() const;
	void setPort(const QString &port);
};
