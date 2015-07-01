#include "gamepadpadblock.h"

GamepadPadBlock::GamepadPadBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "port";
	propertyMap["port"] = "M1";
}

GamepadPadBlock::~GamepadPadBlock()
{

}

QString GamepadPadBlock::toString(int indent) const
{
	QString res = readTemplate("gamepad/gamepadPad.t");
	res.replace("@@PORT@@", getProp("port"));

	return addIndent(res, indent);
}

QString GamepadPadBlock::blockType() const
{
	return "gamepadPadBlock";
}

QString GamepadPadBlock::statusString() const
{
	return QString("Port: %1").arg(getProp("port"));
}

QString GamepadPadBlock::port() const
{
	return getProp("port");
}

void GamepadPadBlock::setPort(const QString &port)
{
	propertyMap["port"] = port;
}
