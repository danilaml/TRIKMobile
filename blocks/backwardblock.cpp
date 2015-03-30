#include "backwardblock.h"
#include "QFile"
#include "QTextStream"

BackwardBlock::BackwardBlock(AbstractBlock *n, QObject *parent) : AbstractBlock(n, parent)
{

}

BackwardBlock::~BackwardBlock()
{

}

QString BackwardBlock::toString(int ident) const
{
	QFile templ(":/engines/backward.t");
	QString res = "";
	if (!templ.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug("failed to open backward.t");
		return res;
	}
	QTextStream input;
	input.setDevice(&templ);
	input.setCodec("UTF-8");
	res = input.readAll();
	templ.close();
	return res.replace("@@POWER@@", QString::number(mPower));
}
