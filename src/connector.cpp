#include "connector.h"

#include <QtNetwork/QHostAddress>
#include <QtCore/QFileInfo>
#include <QtCore/QDebug>

static const uint controlPort = 8888;
static const uint telemetryPort = 9000;

Connector::Connector(const QString &serverIpSettingsKey)
	: mControlConnection(controlPort)
	, mTelemetryConnection(telemetryPort)
	, mIsConnected(false)
	, mServerIpSettingsKey(serverIpSettingsKey)
{
	QObject::connect(&mControlConnection, &ConnectorHandler::messageReceived
					 , this, &Connector::processControlMessage);
	QObject::connect(&mTelemetryConnection, &ConnectorHandler::messageReceived
					 , this, &Connector::processTelemetryMessage);
	QObject::connect(&mVersionTimer, &QTimer::timeout, this, &Connector::versionTimeOut);
}

Connector::~Connector()
{
	disconnect();
}

void Connector::changeServerIP(const QString &newServerIP)
{
	if (mServerIpSettingsKey != newServerIP)
	{
		mServerIpSettingsKey = newServerIP;
	}
}

QString Connector::readAll(QString const &fileName)
{
	QFile file(fileName);
	file.open(QIODevice::ReadOnly | QIODevice::Text);

	if (!file.isOpen())
	{
		qDebug() << fileName << " - file open operation failed";
	}

	QTextStream input;
	input.setDevice(&file);
	input.setCodec("UTF-8");
	QString text = input.readAll();
	file.close();
	return text;
}

bool Connector::uploadProgram(const QString &programName)
{
	if (programName.isEmpty())
	{
		return false;
	}
	QString fileContents;
	fileContents = Connector::readAll(programName);
	connect();
	if (!mControlConnection.isConnected())
	{
		return false;
	}
	const QString &fileNameOnARobot = QFileInfo(programName).fileName();
	mControlConnection.send("file:" + fileNameOnARobot + ":" + fileContents);
	return true;
}

bool Connector::uploadProgram(const QString &programName, const QString programScript)
{
	if (programScript.isEmpty())
	{
		return false;
	}
	connect();
	if (!mControlConnection.isConnected())
	{
		return false;
	}
	const QString &fileNameOnARobot = QFileInfo(programName).fileName();
	mControlConnection.send("file:" + fileNameOnARobot + ":" + programScript);
	return true;
}


bool Connector::runProgram(const QString &programName)
{
	connect();
	if (!mControlConnection.isConnected())
	{
		return false;
	}
	mControlConnection.send("run:" + programName);
	return true;
}


bool Connector::runDirectCommand(const QString &directCommand, bool asScript)
{
	if (!mControlConnection.isConnected())
	{
		return false;
	}
	const QString command = asScript ? "directScript" : "direct";
	mControlConnection.send(command + ":" + directCommand);
	return true;
}

bool Connector::stopRobot()
{
	if (!mControlConnection.isConnected())
	{
		return false;
	}
	mControlConnection.send("stop");
	return true;
}

void Connector::requestData(const QString &sensor)
{
	if (!mTelemetryConnection.isConnected())
	{
		return;
	}
	mTelemetryConnection.send("sensor:" + sensor);
}

void Connector::processControlMessage(const QString &message)
{
	const QString errorMarker("error: ");
	const QString infoMarker("info: ");
	const QString versionMarker("version: ");
	const QString fromRobotString("From robot: ");
	const QString requiredVersion("3.0.2");
	if (message.startsWith(versionMarker))
	{
		mVersionTimer.stop();
		const QString currentVersion = message.mid(versionMarker.length());
		if (currentVersion != requiredVersion)
		{
			qDebug() << "TRIK runtime version is too old, please update it by pressing 'Upload Runtime' button on toolbar";
		}
	}
	else if (message.startsWith(errorMarker))
	{
		qDebug() << fromRobotString << message.mid(errorMarker.length());
	}
	else if (message.startsWith(infoMarker))
	{
		qDebug() << fromRobotString << message.mid(infoMarker.length());
	}
	else
	{
		qDebug() << "Incoming message of unknown type: " << message;
	}
}

void Connector::processTelemetryMessage(const QString &message)
{
	const QString sensorMarker("sensor:");
	if (message.startsWith(sensorMarker))
	{
		QString data(message);
		data.remove(0, sensorMarker.length());
		QStringList portAndValue = data.split(":");
		if (portAndValue[1].startsWith('('))
		{
			portAndValue[1].remove(0, 1);
			portAndValue[1].remove(portAndValue[1].length() - 1, 1);
			QStringList stringValues = portAndValue[1].split(",");
			QVector<int> values;
			for (const QString &value : stringValues)
			{
				values.push_back(value.toInt());
			}
			emit newVectorSensorData(portAndValue[0], values);
		} else {
			emit newScalarSensorData(portAndValue[0], portAndValue[1].toInt());
		}
	} else {
		qDebug() << "Incoming message of unknown type: " << message;
	}
}

void Connector::versionTimeOut()
{
	mVersionTimer.stop();
	qDebug() << "Current TRIK runtime version can not be received";
}

void Connector::versionRequest()
{
	mControlConnection.send("version");
	mVersionTimer.start(3000);
}

void Connector::connect()
{
	const QString server = mServerIpSettingsKey;
	QHostAddress hostAddress(server);

	if (hostAddress.isNull())
	{
		qDebug() << "Unable to resolve host";
		return;
	}

	if (mControlConnection.isConnected() && mTelemetryConnection.isConnected())
	{
		if (mCurrentIP == server)
		{
			return;
		}
		disconnect();
	}
	mCurrentIP = server;
	const bool result = mControlConnection.connect(hostAddress) && mTelemetryConnection.connect(hostAddress);
	versionRequest();
	emit connected(result, QString());
}

void Connector::disconnect()
{
	mControlConnection.disconnect();
	mTelemetryConnection.disconnect();
	emit disconnected();
}
