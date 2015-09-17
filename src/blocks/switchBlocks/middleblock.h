#pragma once

#include "blocks/abstractblock.h"

class MiddleBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit MiddleBlock(QObject *parent = 0);
	virtual ~MiddleBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString condition() const;
	void setCondition(const QString &condition);
};
