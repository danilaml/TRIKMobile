#include "forwardblock.h"
#include "QFile"
#include "QTextStream"

ForwardBlock::ForwardBlock(AbstractBlock *n, QObject *parent) : AbstractBlock(n, parent)
{

}

ForwardBlock::~ForwardBlock()
{

}

QString ForwardBlock::toString(int ident) const
{
	QFile templ(":/engines/forward.t");
	QString res = "";
	if (!templ.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug("failed to open forward.t");
		return res;
	}
	QTextStream input;
	input.setDevice(&templ);
	input.setCodec("UTF-8");
	res = input.readAll();
	templ.close();
	return res.replace("@@POWER@@", QString::number(mPower));
}

