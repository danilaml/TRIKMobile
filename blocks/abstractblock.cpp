#include "abstractblock.h"

AbstractBlock::AbstractBlock(AbstractBlock *n, QObject *parent) : QObject(parent), mNext(n)
{

}

AbstractBlock::~AbstractBlock()
{

}

AbstractBlock *AbstractBlock::getNext() const
{
	return mNext;
}

