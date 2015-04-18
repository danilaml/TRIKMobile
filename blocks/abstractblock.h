#pragma once

#include <QObject>
#include <QList>

class BlockModel;

class AbstractBlock : public QObject
{
	Q_OBJECT
public:
	explicit AbstractBlock(QObject *parent = 0);
	AbstractBlock(QList<BlockModel *> n, QObject *parent = 0);
	virtual ~AbstractBlock();

	virtual QString toString(int indent = 0) const = 0;
	virtual QString blockType() const = 0;

	int childrenCount() const;
	QList<BlockModel *> children() const;
	void setChildren(const QList<BlockModel *> &children);

	QList<QString> getPropertyNames() const;
	void setPropertyNames(const QList<QString> &value);

protected:
	QString readTemplate(QString &filename) const;
	QString readTemplate(const char* filename) const;
	QString addIndent(const QString &code, int indent) const;

	QList<QString> propertyNames;
	QList<BlockModel *> mChildren;
};
