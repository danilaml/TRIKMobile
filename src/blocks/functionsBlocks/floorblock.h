#pragma once

#include "blocks/abstractblock.h"

class FloorBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit FloorBlock(QObject *parent = 0);
	virtual ~FloorBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};
