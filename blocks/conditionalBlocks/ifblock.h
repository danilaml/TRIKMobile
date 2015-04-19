#pragma once

#include "blocks/abstractblock.h"

class IfBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit IfBlock(QObject *parent = 0);
	IfBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~IfBlock();

	virtual QString toString(int indent = 0) const;

	QString condition() const;
	void setCondition(const QString &condition);

	QSharedPointer<AbstractBlock> thenBody() const;
	void setThenBody(const QSharedPointer<AbstractBlock> &thenBody);

private:
	QString mCondition;
	QSharedPointer<AbstractBlock> mThenBody;
};