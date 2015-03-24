#pragma once

#include <QObject>
#include <QMap>
#include "connector.h"

class ScriptGenerator : public QObject
{
	Q_OBJECT
public:
	explicit ScriptGenerator(QObject *parent = 0);
	~ScriptGenerator();

//signals:

public slots:
	void handleSend(const QVariant &scriptList);
	void handleRun(const QString &name);
	void handleStop();

private:
	QMap<QString, QString> mScripts;
	Connector mConnector;
};
