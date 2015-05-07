#include "blockfactory.h"
#include "blocks/enginesBlocks/forwardblock.h"
#include "blocks/conditionalBlocks/infiniteblock.h"

BlockFactory::BlockFactory()
{
	registerBlock<ForwardBlock>("forwardBlock");
	registerBlock<InfiniteBlock>("infiniteBlock");
}

BlockFactory::~BlockFactory()
{
}

QList<QString> BlockFactory::registeredBlocks() const
{
	return mConstructors.keys();
}

AbstractBlock *BlockFactory::getInstance(const QString &blockType) const
{
	return (const_cast<BlockFactory* const>(this)->*(mConstructors[blockType]))(blockType);
}
