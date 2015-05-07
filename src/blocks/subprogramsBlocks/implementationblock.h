#pragma once

#include "blocks/abstractblock.h"

class ImplementationBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit ImplementationBlock(QObject *parent = 0);
	virtual ~ImplementationBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString name() const;
	void setName(const QString &name);
};
