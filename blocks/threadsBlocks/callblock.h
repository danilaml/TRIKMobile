#pragma once

#include "blocks/abstractblock.h"

class CallBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit CallBlock(QObject *parent = 0);
	virtual ~CallBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString threadId() const;
	void setThreadId(const QString threadId);

	QString name() const;
	void setName(const QString &name);
};
