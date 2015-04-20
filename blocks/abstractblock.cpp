#include <QFile>
#include "QTextStream"
#include "abstractblock.h"
#include "blockmodel.h"

AbstractBlock::AbstractBlock(QObject *parent) : QObject(parent)
{

}

AbstractBlock::AbstractBlock(QList<BlockModel *> n, QObject *parent) : QObject(parent), mChildren(n)
{

}

AbstractBlock::~AbstractBlock()
{
	for (auto child : mChildren) {
		delete child;
	}
}

QString AbstractBlock::statusString() const
{
	return "not implemented";
}

int AbstractBlock::childrenCount() const
{
	return mChildren.count();
}

QString AbstractBlock::readTemplate(QString &filename) const
{
	QFile templ(filename);
	QString res;
	if (!templ.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug("failed to open"); //TODO: add filename
		return res;
	}
	QTextStream input;
	input.setDevice(&templ);
	input.setCodec("UTF-8");
	res = input.readAll();
	templ.close();

	return res;
}

QString AbstractBlock::readTemplate(const char* filename) const
{
	QFile templ(QStringLiteral(":/trikQts/templates/") + filename);
	QString res;
	if (!templ.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug("failed to open"); //TODO: add filename
		return res;
	}
	QTextStream input;
	input.setDevice(&templ);
	input.setCodec("UTF-8");
	res = input.readAll();
	templ.close();

	return res;
}

QString AbstractBlock::addIndent(QString const &code, int indent) const
{
	if (!indent) {
		return code;
	}

	QStringList const lines = code.split("\n", QString::SkipEmptyParts);
	QString const indentString(indent, '\t');
	QStringList result;
	for (QString const &line : lines) {
		result << indentString + line;
	}

	return result.join('\n');
}

QString AbstractBlock::getProp(const QString &key) const
{
	return propertyMap[key].toString();
}
QVariantMap AbstractBlock::getPropertyMap() const
{
    return propertyMap;
}

void AbstractBlock::setPropertyMap(const QVariantMap &value)
{
    propertyMap = value;
}


QList<QString> AbstractBlock::getPropertyNames() const
{
    return propertyNames;
}

void AbstractBlock::setPropertyNames(const QList<QString> &value)
{
    propertyNames = value;
}

QList<BlockModel *> AbstractBlock::children() const
{
	return mChildren;
}

void AbstractBlock::setChildren(const QList<BlockModel *> &children)
{
	mChildren = children;
}

