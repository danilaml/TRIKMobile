#pragma once

#include "blocks/abstractblock.h"

class SqrtBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit SqrtBlock(QObject *parent = 0);
	virtual ~SqrtBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};
