#pragma once

#include "blocks/abstractblock.h"

class StopBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit StopBlock(QObject *parent = 0);
	virtual ~StopBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString port() const;
	void setPort(const QString &port);
};
