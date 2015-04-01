#pragma once

#include <QObject>
#include <QSharedPointer>

class AbstractBlock : public QObject
{
	Q_OBJECT
public:
	AbstractBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~AbstractBlock();

	virtual QString toString(int ident = 0) const = 0;

	QSharedPointer<AbstractBlock> getNext() const;

protected:
	QString readAll(QString &filename) const;
	QString readAll(const char* filename) const;

	QSharedPointer<AbstractBlock> mNext;

};
