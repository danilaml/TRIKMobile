#pragma once

#include "blocks/abstractblock.h"

class RandomBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit RandomBlock(QObject *parent = 0);
	virtual ~RandomBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};
