#pragma once

#include "blocks/abstractblock.h"

class AsinBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AsinBlock(QObject *parent = 0);
	virtual ~AsinBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};

