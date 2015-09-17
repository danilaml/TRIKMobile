#pragma once

#include "blocks/abstractblock.h"

class AtanBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AtanBlock(QObject *parent = 0);
	virtual ~AtanBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};

