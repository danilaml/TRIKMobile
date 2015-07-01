#pragma once

#include "blocks/abstractblock.h"

class OneCaseBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit OneCaseBlock(QObject *parent = 0);
	virtual ~OneCaseBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString value() const;
	void setValue(const QString &value);
};
