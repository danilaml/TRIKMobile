#pragma once

#include <QObject>

class AbstractBlock : public QObject
{
	Q_OBJECT
public:
	AbstractBlock(AbstractBlock *n, QObject *parent = 0);
	virtual ~AbstractBlock();

	virtual QString toString(int ident = 0) const = 0;

	AbstractBlock* getNext() const;

protected:
	AbstractBlock *mNext;

};
