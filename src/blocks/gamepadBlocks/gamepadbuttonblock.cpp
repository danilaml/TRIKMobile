#include "gamepadbuttonblock.h"

GamepadButtonBlock::GamepadButtonBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "port";
	propertyMap["port"] = "M1";
}

GamepadButtonBlock::~GamepadButtonBlock()
{

}

QString GamepadButtonBlock::toString(int indent) const
{
	QString res = readTemplate("gamepad/gamepadButton.t");
	res.replace("@@PORT@@", getProp("port"));

	return addIndent(res, indent);
}

QString GamepadButtonBlock::blockType() const
{
	return "gamepadButtonBlock";
}

QString GamepadButtonBlock::statusString() const
{
	return QString("Port: %1").arg(getProp("port"));
}

QString GamepadButtonBlock::port() const
{
	return getProp("port");
}

void GamepadButtonBlock::setPort(const QString &port)
{
	propertyMap["port"] = port;
}
