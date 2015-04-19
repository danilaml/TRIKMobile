#pragma once

#include "blocks/abstractblock.h"

class AbsBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit AbsBlock(QObject *parent = 0);
	AbsBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~AbsBlock();

	virtual QString toString(int indent = 0) const;

	QString argument() const;
	void setArgument(const QString &argument);

private:
	QString mArgument;
};
