#pragma once

#include "blocks/abstractblock.h"

class WhileDoBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit WhileDoBlock(QObject *parent = 0);
	WhileDoBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~WhileDoBlock();

	virtual QString toString(int indent = 0) const;

	QString condition() const;
	void setCondition(const QString &condition);

	QSharedPointer<AbstractBlock> body() const;
	void setBody(const QSharedPointer<AbstractBlock> &body);

private:
	QString mCondition;
	QSharedPointer<AbstractBlock> mBody;
};