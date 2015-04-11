#pragma once

#include <QObject>
#include <QMap>
#include "connector.h"

class QmlSignalHandler : public QObject
{
	Q_OBJECT
public:
	explicit QmlSignalHandler(QObject *parent = 0);
	~QmlSignalHandler();

	//signals:

public slots:
	void handleSend(const QVariant &scriptList);
	void handleRun(const QString &name);
	void handleStop();

private:
	QMap<QString, QString> mScripts;
	Connector mConnector;
};
