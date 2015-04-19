#include "gamepadbutton1portblock.h"

GamepadButton1PortBlock::GamepadButton1PortBlock(QObject *parent) : AbstractBlock(parent)
{

}

GamepadButton1PortBlock::GamepadButton1PortBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

GamepadButton1PortBlock::~GamepadButton1PortBlock()
{

}

QString GamepadButton1PortBlock::toString(int indent) const
{
	QString res = readTemplate("ports/GamepadButton1Port.t");
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}
