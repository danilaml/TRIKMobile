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

	QString body() const;
	void setBody(const QString &body);
	QString condition() const;
	void setCondition(const QString &condition);

private:
	QString mBody;
	QString mCondition;
};
