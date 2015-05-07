#pragma once

#include <QMap>
#include <QList>
#include "blocks/abstractblock.h"

class AbstractBlock;

class BlockFactory
{
public:
	explicit BlockFactory();
	~BlockFactory();

	QList<QString> registeredBlocks() const;
	AbstractBlock *getInstance(const QString &blockType) const;

private:
	template<typename T>
	AbstractBlock *createBlock(const QString &blockType) {
		AbstractBlock *block = new T();
		block->setBlockType(blockType);
		return block;
	}
	template<typename T>
	void registerBlock(const QString &blockType) {
		mConstructors[blockType] = &BlockFactory::createBlock<T>;
	}

	QMap<QString, AbstractBlock*(BlockFactory::*)(const QString &)> mConstructors;
};
