#pragma once

#include "blocks/abstractblock.h"

class BackwardBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit BackwardBlock(QObject *parent = 0);
	virtual ~BackwardBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString power() const;
	void setPower(const QString &power);
	QString port() const;
	void setPort(const QString &port);
};
