#pragma once

#include "blocks/abstractblock.h"

class VariableDeclarationBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit VariableDeclarationBlock(QObject *parent = 0);
	VariableDeclarationBlock(QSharedPointer<AbstractBlock> n, QObject *parent = 0);
	virtual ~VariableDeclarationBlock();

	virtual QString toString(int indent = 0) const;

	QString type() const;
	void setType(const QString &type);

	QString name() const;
	void setName(const QString &name);

private:
	QString mType;
	QString mName;
};
