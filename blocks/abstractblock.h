#pragma once

#include <QObject>
#include <QSharedPointer>

class AbstractBlock : public QObject
{
	Q_OBJECT
public:
	explicit AbstractBlock(QObject *parent = 0);
	AbstractBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~AbstractBlock();

	virtual QString toString(int indent = 0) const = 0;

	QSharedPointer<AbstractBlock> getNext() const;

protected:
	QString readTemplate(QString &filename) const;
	QString readTemplate(const char* filename) const;
	QString addIndent(const QString &code, int indent) const;

	QSharedPointer<AbstractBlock> mNext;
};
