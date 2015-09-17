#pragma once

#include "blocks/abstractblock.h"

class SubprogramCallBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit SubprogramCallBlock(QObject *parent = 0);
	virtual ~SubprogramCallBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString name() const;
	void setName(const QString &name);
};
