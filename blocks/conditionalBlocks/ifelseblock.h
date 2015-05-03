#pragma once

#include "blocks/abstractblock.h"

class IfElseBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit IfElseBlock(QObject *parent = 0);
	virtual ~IfElseBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString condition() const;
	void setCondition(const QString &condition);
};

