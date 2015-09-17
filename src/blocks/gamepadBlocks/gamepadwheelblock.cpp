#include "gamepadwheelblock.h"

GamepadWheelBlock::GamepadWheelBlock(QObject *parent) : AbstractBlock(parent)
{

}

GamepadWheelBlock::~GamepadWheelBlock()
{

}

QString GamepadWheelBlock::toString(int indent) const
{
	QString res = readTemplate("gamepad/gamepadWheel.t");
	return addIndent(res, indent);
}

QString GamepadWheelBlock::blockType() const
{
	return "gamepadWheelBlock";
}

