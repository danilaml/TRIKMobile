#pragma once

#include "blocks/abstractblock.h"

class DoWhileBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit DoWhileBlock(QObject *parent = 0);
	DoWhileBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~DoWhileBlock();

	virtual QString toString(int indent = 0) const;

	QSharedPointer<AbstractBlock> body() const;
	void setBody(const QSharedPointer<AbstractBlock> &body);

	QString condition() const;
	void setCondition(const QString &condition);

private:
	QSharedPointer<AbstractBlock> mBody;
	QString mCondition;
};
