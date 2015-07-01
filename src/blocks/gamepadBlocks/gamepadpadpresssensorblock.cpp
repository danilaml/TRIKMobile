#include "gamepadpadpresssensorblock.h"

GamepadPadPressSensorBlock::GamepadPadPressSensorBlock(QObject *parent) : AbstractBlock(parent)
{
	//propertyNames << "port";
	propertyMap["port"] = "M1";
}

GamepadPadPressSensorBlock::~GamepadPadPressSensorBlock()
{

}

QString GamepadPadPressSensorBlock::toString(int indent) const
{
	QString res = readTemplate("gamepad/gamepadPadPressSensor.t");
	res.replace("@@PORT@@", getProp("port"));

	return addIndent(res, indent);
}

QString GamepadPadPressSensorBlock::blockType() const
{
	return "gamepadPadPressSensorBlock";
}

QString GamepadPadPressSensorBlock::statusString() const
{
	return QString("Port: %1").arg(getProp("port"));
}

QString GamepadPadPressSensorBlock::port() const
{
	return getProp("port");
}

void GamepadPadPressSensorBlock::setPort(const QString &port)
{
	propertyMap["port"] = port;
}
