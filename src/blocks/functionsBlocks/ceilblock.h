#pragma once

#include "blocks/abstractblock.h"

class CeilBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit CeilBlock(QObject *parent = 0);
	virtual ~CeilBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};
