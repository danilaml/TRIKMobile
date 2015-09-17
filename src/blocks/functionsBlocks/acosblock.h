#pragma once

#include "blocks/abstractblock.h"

class AcosBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AcosBlock(QObject *parent = 0);
	virtual ~AcosBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString argument() const;
	void setArgument(const QString &argument);
};
