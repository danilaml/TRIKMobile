#pragma once

#include "blocks/abstractblock.h"

class GamepadButtonBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GamepadButtonBlock(QObject *parent = 0);
	GamepadButtonBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~GamepadButtonBlock();

	virtual QString toString(int indent = 0) const;

	int port() const;
	void setPort(int port);

private:
	int mPort;
};
