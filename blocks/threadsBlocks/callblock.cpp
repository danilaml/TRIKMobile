#include "callblock.h"

CallBlock::CallBlock(QObject *parent) : AbstractBlock(parent)
{
	propertyNames << "threadId" << "name";
	propertyMap["threadId"] = "1";
	propertyMap["name"] = "thread1";
}

CallBlock::~CallBlock()
{

}

QString CallBlock::toString(int indent) const
{
	QString res = readTemplate("threads/call.t");
	res.replace("@@THREAD_ID@@", getProp("threadId")).replace("@@NAME@@", getProp("name"));
	return addIndent(res, indent);
}

QString CallBlock::blockType() const
{
	return "callBlock";
}

QString CallBlock::statusString() const
{
	return QString("ThreadId: %1, Name: %2").arg(getProp("threadId"), getProp("name"));
}

QString CallBlock::threadId() const
{
	return getProp("threadId");
}

void CallBlock::setThreadId(const QString threadId)
{
	propertyMap["threadId"] = threadId;
}

QString CallBlock::name() const
{
	return getProp("name");
}

void CallBlock::setName(const QString &name)
{
	propertyMap["name"] = name;
}
