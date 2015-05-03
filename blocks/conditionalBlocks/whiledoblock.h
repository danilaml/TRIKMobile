#pragma once

#include "blocks/abstractblock.h"

class WhileDoBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit WhileDoBlock(QObject *parent = 0);
	virtual ~WhileDoBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString condition() const;
	void setCondition(const QString &condition);
};
