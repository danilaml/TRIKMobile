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

	QSharedPointer<AbstractBlock> body() const;
	void setBody(const QSharedPointer<AbstractBlock> &body);

private:
	QSharedPointer<AbstractBlock> mBody;
};
