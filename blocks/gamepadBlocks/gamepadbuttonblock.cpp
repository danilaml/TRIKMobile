#include "gamepadbuttonblock.h"

GamepadButtonBlock::GamepadButtonBlock(QObject *parent) : AbstractBlock(parent)
{

}

GamepadButtonBlock::GamepadButtonBlock(QSharedPointer<AbstractBlock> n, QObject *parent) : AbstractBlock(n, parent)
{

}

GamepadButtonBlock::~GamepadButtonBlock()
{

}

QString GamepadButtonBlock::toString(int indent) const
{
	QString res = readTemplate("gamepad/gamepadButton.t");
	res.replace("@@PORT@@", QString::number(mPort));
	if (!mNext.isNull()) {
		res.append(mNext->toString());
	}
	return addIndent(res, indent);
}

int GamepadButtonBlock::port() const
{
	return mPort;
}

void GamepadButtonBlock::setPort(int port)
{
	mPort = port;
}
