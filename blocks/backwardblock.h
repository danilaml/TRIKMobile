#pragma once

#include "blocks/abstractblock.h"

class BackwardBlock : public AbstractBlock
{
	Q_OBJECT
public:
	BackwardBlock(AbstractBlock *n, QObject *parent = 0);
	virtual ~BackwardBlock();

	virtual QString toString(int ident) const;

private:
	int mPower;
};
