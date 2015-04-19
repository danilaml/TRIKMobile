#pragma once

#include "blocks/abstractblock.h"

class HeadBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit HeadBlock(QObject *parent = 0);
	HeadBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~HeadBlock();

	virtual QString toString(int indent = 0) const;

	QString expression() const;
	void setExpression(const QString &expression);

	QString condition() const;
	void setCondition(const QString &condition);

	QSharedPointer<AbstractBlock> body() const;
	void setBody(const QSharedPointer<AbstractBlock> &body);

private:
	QString mExpression;
	QString mCondition;
	QSharedPointer<AbstractBlock> mBody;
};
