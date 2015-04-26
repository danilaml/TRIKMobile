#pragma once

#include "blocks/abstractblock.h"

class NullifyEncoderBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit NullifyEncoderBlock(QObject *parent = 0);
	virtual ~NullifyEncoderBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString port() const;
	void setPort(const QString &port);
};
