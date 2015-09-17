#pragma once

#include "blocks/abstractblock.h"

class EscBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit EscBlock(QObject *parent = 0);
	virtual ~EscBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
