#include "blockfactory.h"
#include "blocks/enginesBlocks/forwardblock.h"
#include "blocks/conditionalBlocks/infiniteblock.h"
#include "blocks/enginesBlocks/backwardblock.h"
#include "blocks/enginesBlocks/stopblock.h"
#include "blocks/waitBlocks/timerblock.h"
#include "blocks/drawingBlocks/smileblock.h"
#include "blocks/drawingBlocks/sadsmileblock.h"
#include "blocks/conditionalBlocks/forblock.h"
#include "blocks/conditionalBlocks/ifblock.h"
#include "blocks/conditionalBlocks/ifelseblock.h"
#include "blocks/sayblock.h"
#include "blocks/variablesBlocks/variabledeclarationblock.h"

BlockFactory::BlockFactory()
{
	registerBlock<ForwardBlock>("forwardBlock");
	registerBlock<InfiniteBlock>("infiniteBlock");
	registerBlock<BackwardBlock>("backwardBlock");
	registerBlock<StopBlock>("stopBlock");
	registerBlock<TimerBlock>("timerBlock");
	registerBlock<SmileBlock>("smileBlock");
	registerBlock<SadSmileBlock>("sadSmileBlock");
	registerBlock<ForBlock>("forBlock");
	registerBlock<IfBlock>("ifBlock");
	registerBlock<IfElseBlock>("ifElseBlock");
	registerBlock<SayBlock>("sayBlock");
	registerBlock<VariableDeclarationBlock>("variableDeclarationBlock");
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
