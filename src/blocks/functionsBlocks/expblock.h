#pragma once

#include "blocks/abstractblock.h"

class ExpBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit ExpBlock(QObject *parent = 0);
	virtual ~ExpBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};


