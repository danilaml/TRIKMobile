#pragma once

#include "blocks/abstractblock.h"

class IfElseBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit IfElseBlock(QObject *parent = 0);
	IfElseBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~IfElseBlock();

	virtual QString toString(int indent = 0) const;

	QString condition() const;
	void setCondition(const QString &condition);

	QSharedPointer<AbstractBlock> thenBody() const;
	void setThenBody(const QSharedPointer<AbstractBlock> &thenBody);

	QSharedPointer<AbstractBlock> elseBody() const;
	void setElseBody(const QSharedPointer<AbstractBlock> &elseBody);

private:
	QString mCondition;
	QSharedPointer<AbstractBlock> mThenBody;
	QSharedPointer<AbstractBlock> mElseBody;
};

