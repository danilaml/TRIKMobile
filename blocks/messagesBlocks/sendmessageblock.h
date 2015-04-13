#pragma once

#include "blocks/abstractblock.h"

class SendMessageBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit SendMessageBlock(QObject *parent = 0);
	SendMessageBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~SendMessageBlock();

	virtual QString toString(int indent = 0) const;

	int hullNumber() const;
	void setHullNumber(int hullNumber);

	QString message() const;
	void setMessage(const QString &message);

private:
	int mHullNumber;
	QString mMessage;
};
