#pragma once

#include <QtNetwork/QTcpSocket>
#include <QtCore/QTimer>

#include "connectorhandler.h"

class Connector : public QObject
{
	Q_OBJECT
public:
	explicit Connector(const QString &serverIpSettingsKey);
	~Connector();

	void changeServerIP(const QString &newServerIP);

	bool uploadProgram(const QString &programName);
	bool uploadProgram(const QString &programName, const QString programScript);

	bool runProgram(const QString &programName);
	bool runDirectCommand(const QString &directCommand, bool asScript = false);

	bool stopRobot();

	void requestData(const QString &sensor);

	void connect();
	void disconnect();

signals:
	void connected(bool result, const QString &errorString);
	void disconnected();

	void newScalarSensorData(const QString &port, int data);
	void newVectorSensorData(const QString &port, QVector<int> const &data);

private slots:
	void processControlMessage(const QString &message);
	void processTelemetryMessage(const QString &message);

	void versionTimeOut();

private:
	void send(const QString &data, QTcpSocket &socket);

	void versionRequest();

	QTcpSocket mSocket;

	QString mCurrentIP;

	ConnectorHandler mControlConnection;
	ConnectorHandler mTelemetryConnection;

	bool mIsConnected;

	QTimer mVersionTimer;

	static QString readAll(QString const &fileName);

	QString mServerIpSettingsKey;

};
