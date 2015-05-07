#pragma once

#include "blocks/abstractblock.h"

class SadSmileBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit SadSmileBlock(QObject *parent = 0);
	virtual ~SadSmileBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
