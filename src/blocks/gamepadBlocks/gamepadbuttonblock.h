#pragma once

#include "blocks/abstractblock.h"

class GamepadButtonBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GamepadButtonBlock(QObject *parent = 0);
	virtual ~GamepadButtonBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString port() const;
	void setPort(const QString &port);
};
