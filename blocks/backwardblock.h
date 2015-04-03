#pragma once

#include "blocks/abstractblock.h"

class BackwardBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit BackwardBlock(QObject *parent = 0);
	BackwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~BackwardBlock();

	virtual QString toString(int indent = 0) const;

	int power() const;
	void setPower(int power);
	int port() const;
	void setPort(int port);

private:
	int mPower;
	int mPort;
};
