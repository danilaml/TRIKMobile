#include <QFile>
#include "QTextStream"
#include "abstractblock.h"

AbstractBlock::AbstractBlock(QObject *parent) : QObject(parent)
{

}

AbstractBlock::AbstractBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : QObject(parent), mNext(n)
{

}

AbstractBlock::~AbstractBlock()
{

}

QSharedPointer<AbstractBlock> AbstractBlock::getNext() const
{
	return mNext;
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
	qDebug("HERE IN INDENT");
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


