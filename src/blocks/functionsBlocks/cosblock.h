#pragma once

#include "blocks/abstractblock.h"

class CosBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit CosBlock(QObject *parent = 0);
	virtual ~CosBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};

