#pragma once

#include "blocks/abstractblock.h"

class SinBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit SinBlock(QObject *parent = 0);
	virtual ~SinBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};
