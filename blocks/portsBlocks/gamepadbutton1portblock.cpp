#include "gamepadbutton1portblock.h"

GamepadButton1PortBlock::GamepadButton1PortBlock(QObject *parent) : AbstractBlock(parent)
{

}

GamepadButton1PortBlock::~GamepadButton1PortBlock()
{

}

QString GamepadButton1PortBlock::toString(int indent) const
{
	QString res = readTemplate("ports/GamepadButton1Port.t");
	return addIndent(res, indent);
}

QString GamepadButton1PortBlock::blockType() const
{
	return "gamepadButton1PortBlock";
}
