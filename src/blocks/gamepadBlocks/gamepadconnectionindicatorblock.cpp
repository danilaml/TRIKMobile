#include "gamepadconnectionindicatorblock.h"

GamepadConnectionIndicatorBlock::GamepadConnectionIndicatorBlock(QObject *parent) : AbstractBlock(parent)
{

}

GamepadConnectionIndicatorBlock::~GamepadConnectionIndicatorBlock()
{

}

QString GamepadConnectionIndicatorBlock::toString(int indent) const
{
	QString res = readTemplate("gamepad/gamepadConnectionIndicator.t");
	return addIndent(res, indent);
}

QString GamepadConnectionIndicatorBlock::blockType() const
{
	return "gamepadConnectionIndicatorBlock";
}
