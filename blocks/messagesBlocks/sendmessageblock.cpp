#include "sendmessageblock.h"

SendMessageBlock::SendMessageBlock(QObject *parent) : AbstractBlock(parent)
{

}

SendMessageBlock::SendMessageBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

SendMessageBlock::~SendMessageBlock()
{

}

QString SendMessageBlock::toString(int indent) const
{
	QString res = readTemplate("messages/sendMessage.t");
	res.replace("@@HULL_NUMBER@@", QString::number(mHullNumber)).replace("@@MESSAGE@@", "\"" + mMessage + "\"");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

int SendMessageBlock::hullNumber() const
{
	return mHullNumber;
}

void SendMessageBlock::setHullNumber(int hullNumber)
{
	mHullNumber = hullNumber;
}

QString SendMessageBlock::message() const
{
	return mMessage;
}

void SendMessageBlock::setMessage(const QString &message)
{
	mMessage = message;
}
