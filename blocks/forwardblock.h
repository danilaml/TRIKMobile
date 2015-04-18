#pragma once

#include "blocks/abstractblock.h"

class ForwardBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit ForwardBlock(QObject *parent = 0);
//	ForwardBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~ForwardBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;

	int power() const;
	void setPower(int power);
	QString port() const;
	void setPort(const QString &port);

private:
	int mPower;
	QString mPort;
};
