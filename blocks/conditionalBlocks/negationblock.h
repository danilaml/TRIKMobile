#pragma once

#include "blocks/abstractblock.h"

class NegationBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit NegationBlock(QObject *parent = 0);
	NegationBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~NegationBlock();

	virtual QString toString(int indent = 0) const;

	QString condition() const;
	void setCondition(const QString &condition);

private:
	QString mCondition;
};
