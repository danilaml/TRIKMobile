#pragma once

#include <QObject>
#include "blocks/abstractblock.h"

class ScriptGenerator : public QObject
{
	Q_OBJECT
public:
	explicit ScriptGenerator(QObject *parent = 0);
	~ScriptGenerator();

	static QString generate(QSharedPointer<AbstractBlock> root);
};
