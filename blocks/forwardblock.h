#pragma once

#include "blocks/abstractblock.h"

class ForwardBlock : public AbstractBlock
{
	Q_OBJECT
public:
	ForwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~ForwardBlock();

	virtual QString toString(int ident = 0) const;

private:
	int mPower;
};
