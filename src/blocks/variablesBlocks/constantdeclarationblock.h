#pragma once

#include "blocks/abstractblock.h"

class ConstantDeclarationBlock : public AbstractBlock
{
	Q_OBJECT
public:
	explicit ConstantDeclarationBlock(QObject *parent = 0);
	virtual ~ConstantDeclarationBlock();

	virtual QString toString(int indent = 0) const;
	virtual QString blockType() const;
	virtual QString statusString() const;

	QString name() const;
	void setName(const QString &name);

	QString value() const;
	void setValue(const QString &value);
};
