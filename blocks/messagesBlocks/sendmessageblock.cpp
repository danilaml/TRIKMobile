#include "sendmessageblock.h"

SendMessageBlock::SendMessageBlock(QObject *parent) : AbstractBlock(parent)
{
	propertyNames << "hullNumber" << "message";
	propertyMap["hullNumber"] = "1";
	propertyMap["message"] = "New message";
}

SendMessageBlock::~SendMessageBlock()
{

}

QString SendMessageBlock::toString(int indent) const
{
	QString res = readTemplate("messages/sendMessage.t");
	res.replace("@@HULL_NUMBER@@", getProp("hullNumber")).replace("@@MESSAGE@@", "\"" + getProp("message") + "\"");
	return addIndent(res, indent);
}

QString SendMessageBlock::blockType() const
{
	return "sendMessageBlock";
}

QString SendMessageBlock::statusString() const
{
	return QString("HullNumber: %1, Message: %2").arg(getProp("hullNumber"), getProp("message"));
}

QString SendMessageBlock::hullNumber() const
{
	return getProp("hullNumber");
}

void SendMessageBlock::setHullNumber(const QString hullNumber)
{
	propertyMap["hullNumber"] = hullNumber;
}

QString SendMessageBlock::message() const
{
	return getProp("message");
}

void SendMessageBlock::setMessage(const QString &message)
{
	propertyMap["message"] = message;
}
