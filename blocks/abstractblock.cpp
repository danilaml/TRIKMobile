#include <QFile>
#include "QTextStream"
#include "abstractblock.h"

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

QString AbstractBlock::readAll(QString &filename) const
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

QString AbstractBlock::readAll(const char* filename) const
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


