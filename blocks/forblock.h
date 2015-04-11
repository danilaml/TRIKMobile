#pragma once

#include "blocks/abstractblock.h"

class ForBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit ForBlock(QObject *parent = 0);
	ForBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~ForBlock();

	virtual QString toString(int indent = 0) const;

	QString iteratorType() const;
	void setIteratorType(const QString &iteratorType);

	QString iterator() const;
	void setIterator(const QString &iterator);

	QString initialValue() const;
	void setInitialValue(const QString &initialValue);

	QString bound() const;
	void setBound(const QString &bound);

	QString body() const;
	void setBody(const QString &body);

private:
	QString mIteratorType;
	QString mIterator;
	QString mInitialValue;
	QString mBound;
	QString mBody;
};
