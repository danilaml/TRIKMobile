#pragma once

#include "blocks/abstractblock.h"

class CallBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit CallBlock(QObject *parent = 0);
	CallBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~CallBlock();

	virtual QString toString(int indent = 0) const;

	int threadId() const;
	void setThreadId(int threadId);

	QString name() const;
	void setName(const QString &name);

private:
	int mThreadId;
	QString mName;
};
