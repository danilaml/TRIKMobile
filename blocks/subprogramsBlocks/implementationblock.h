#pragma once

#include "blocks/abstractblock.h"

class ImplementationBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit ImplementationBlock(QObject *parent = 0);
	ImplementationBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~ImplementationBlock();

	virtual QString toString(int indent = 0) const;

	QString name() const;
	void setName(const QString &name);

	QSharedPointer<AbstractBlock> body() const;
	void setBody(const QSharedPointer<AbstractBlock> &body);

private:
	QString mName;
	QSharedPointer<AbstractBlock> mBody;
};
