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

	QString thenBody() const;
	void setThenBody(const QString &thenBody);

	QString elseBody() const;
	void setElseBody(const QString &elseBody);

private:
	QString mCondition;
	QString mThenBody;
	QString mElseBody;
};

