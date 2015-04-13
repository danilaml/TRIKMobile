#pragma once

#include "blocks/abstractblock.h"

class SmileBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit SmileBlock(QObject *parent = 0);
	SmileBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~SmileBlock();

	virtual QString toString(int indent = 0) const;
};
