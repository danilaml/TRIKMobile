#pragma once

#include "blocks/abstractblock.h"

class AdditionBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AdditionBlock(QObject *parent = 0);
	AdditionBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~AdditionBlock();

	virtual QString toString(int indent = 0) const;

	QString left() const;
	void setLeft(const QString &left);

	QString right() const;
	void setRight(const QString &right);

private:
	QString mLeft;
	QString mRight;
};
