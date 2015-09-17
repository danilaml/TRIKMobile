#pragma once

#include "blocks/abstractblock.h"

class OrangeBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit OrangeBlock(QObject *parent = 0);
	virtual ~OrangeBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
};
