#pragma once

#include "blocks/abstractblock.h"

class StopBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit StopBlock(QObject *parent = 0);
	StopBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~StopBlock();

	virtual QString toString(int indent = 0) const;

	int port() const;
	void setPort(int port);

private:
	int mPort;
};
