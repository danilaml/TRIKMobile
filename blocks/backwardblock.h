#pragma once

#include "blocks/abstractblock.h"

class BackwardBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit BackwardBlock(QObject *parent = 0);
	BackwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~BackwardBlock();

	virtual QString toString(int indent) const;

	int power() const;
	void setPower(int power);

private:
	int mPower;
};
