#pragma once

#include "blocks/abstractblock.h"

class InfiniteBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit InfiniteBlock(QObject *parent = 0);
	InfiniteBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~InfiniteBlock();

	virtual QString toString(int indent = 0) const;

	QString body() const;
	void setBody(const QString &body);

private:
	QString mBody;
};
