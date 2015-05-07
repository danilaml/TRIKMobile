#pragma once

#include "blocks/abstractblock.h"

class DoWhileBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit DoWhileBlock(QObject *parent = 0);
	virtual ~DoWhileBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString condition() const;
	void setCondition(const QString &condition);
};
