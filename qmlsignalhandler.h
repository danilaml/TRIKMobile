#pragma once

#include <QObject>
#include <QMap>
#include "connector.h"
#include "blockmodel.h"

class QmlSignalHandler : public QObject
{
	Q_OBJECT
public:
	explicit QmlSignalHandler(QObject *parent = 0);
	~QmlSignalHandler();

	BlockModel *model() const;
	void setModel(BlockModel *model);

public slots:
	void handleSend();
	void handleRun(const QString &name);
	void handleStop();
	void hadleIpChange(const QString &newIp);

private:
	Connector mConnector;
	BlockModel *mModel;
};
