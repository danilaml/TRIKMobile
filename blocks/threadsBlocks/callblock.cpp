#include "callblock.h"

CallBlock::CallBlock(QObject *parent) : AbstractBlock(parent)
{

}

CallBlock::CallBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

CallBlock::~CallBlock()
{

}

QString CallBlock::toString(int indent) const
{
	QString res = readTemplate("threads/call.t");
	res.replace("@@THREAD_ID@@", QString::number(mThreadId)).replace("@@NAME@@", mName);
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

int CallBlock::threadId() const
{
    return mThreadId;
}

void CallBlock::setThreadId(int threadId)
{
    mThreadId = threadId;
}

QString CallBlock::name() const
{
    return mName;
}

void CallBlock::setName(const QString &name)
{
    mName = name;
}
