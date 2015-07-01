#pragma once

#include "blocks/abstractblock.h"

class LnBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit LnBlock(QObject *parent = 0);
	virtual ~LnBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};

