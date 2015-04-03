#pragma once

#include "blocks/abstractblock.h"

class ForwardBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit ForwardBlock(QObject *parent = 0);
	ForwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~ForwardBlock();

	virtual QString toString(int indent = 0) const;

	int power() const;
	void setPower(int power);
	int port() const;
	void setPort(int port);

private:
	int mPower;
	int mPort;
};
