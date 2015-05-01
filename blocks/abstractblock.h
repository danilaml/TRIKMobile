#pragma once

#include <QObject>
#include <QList>
#include <QVariantMap>

class BlockModel;

class AbstractBlock : public QObject
{
	Q_OBJECT
public:
	explicit AbstractBlock(QObject *parent = 0);
	AbstractBlock(QList<BlockModel *> n, QObject *parent = 0);
	AbstractBlock(const QString &blockType, QObject *parent = 0);
	virtual ~AbstractBlock();

	virtual QString toString(int indent = 0) const = 0;
	//virtual QString blockType() const = 0;
	virtual QString statusString() const;

	int childrenCount() const;
	QList<BlockModel *> children() const;
	void setChildren(const QList<BlockModel *> &children);

	QList<QString> getPropertyNames() const;
	void setPropertyNames(const QList<QString> &value);

	QVariantMap getPropertyMap() const;
	void setPropertyMap(const QVariantMap &value);

	QString blockType() const;
	void setBlockType(const QString &blockType);

protected:
	QString readTemplate(QString &filename) const;
	QString readTemplate(const char* filename) const;
	QString addIndent(const QString &code, int indent) const;
	QString getProp(const QString &key) const;

	QString mBlockType;
	QList<QString> propertyNames;
	QVariantMap propertyMap;
	QList<BlockModel *> mChildren;
};
