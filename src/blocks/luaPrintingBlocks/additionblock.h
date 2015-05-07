#pragma once

#include "blocks/abstractblock.h"

class AdditionBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AdditionBlock(QObject *parent = 0);
	virtual ~AdditionBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString left() const;
	void setLeft(const QString &left);

	QString right() const;
	void setRight(const QString &right);
};
