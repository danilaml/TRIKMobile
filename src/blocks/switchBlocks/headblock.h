#pragma once

#include "blocks/abstractblock.h"

class HeadBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit HeadBlock(QObject *parent = 0);
	virtual ~HeadBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString expression() const;
	void setExpression(const QString &expression);

	QString condition() const;
	void setCondition(const QString &condition);
};
