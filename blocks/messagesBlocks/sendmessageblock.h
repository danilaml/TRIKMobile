#pragma once

#include "blocks/abstractblock.h"

class SendMessageBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit SendMessageBlock(QObject *parent = 0);
	virtual ~SendMessageBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString hullNumber() const;
	void setHullNumber(const QString hullNumber);

	QString message() const;
	void setMessage(const QString &message);
};
