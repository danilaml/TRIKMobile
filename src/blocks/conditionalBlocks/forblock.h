#pragma once

#include "blocks/abstractblock.h"

class ForBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit ForBlock(QObject *parent = 0);
	virtual ~ForBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString iterator() const;
	void setIterator(const QString &iterator);

	QString initialValue() const;
	void setInitialValue(const QString &initialValue);

	QString bound() const;
	void setBound(const QString &bound);
};
