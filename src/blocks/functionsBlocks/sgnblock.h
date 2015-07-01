#pragma once

#include "blocks/abstractblock.h"

class SgnBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit SgnBlock(QObject *parent = 0);
	virtual ~SgnBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};
