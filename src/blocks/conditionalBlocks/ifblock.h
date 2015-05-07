#pragma once

#include "blocks/abstractblock.h"

class IfBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit IfBlock(QObject *parent = 0);
	virtual ~IfBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString condition() const;
	void setCondition(const QString &condition);
};
