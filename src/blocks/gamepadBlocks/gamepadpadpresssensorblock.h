#pragma once

#include "blocks/abstractblock.h"

class GamepadPadPressSensorBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit GamepadPadPressSensorBlock(QObject *parent = 0);
	virtual ~GamepadPadPressSensorBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString port() const;
	void setPort(const QString &port);
};
