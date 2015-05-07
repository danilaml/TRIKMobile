#pragma once

#include "blocks/abstractblock.h"

class SayBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit SayBlock(QObject *parent = 0);
	virtual ~SayBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString text() const;
	void setText(const QString &text);
};
