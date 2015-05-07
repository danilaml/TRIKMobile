#pragma once

#include "blocks/abstractblock.h"

class AbsBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AbsBlock(QObject *parent = 0);
	virtual ~AbsBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};
