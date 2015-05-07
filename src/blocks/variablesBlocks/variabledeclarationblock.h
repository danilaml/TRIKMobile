#pragma once

#include "blocks/abstractblock.h"

class VariableDeclarationBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit VariableDeclarationBlock(QObject *parent = 0);
	virtual ~VariableDeclarationBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString name() const;
	void setName(const QString &name);
};
