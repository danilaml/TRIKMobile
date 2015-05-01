#pragma once

#include <QObject>
#include <QMap>
#include "connector.h"
#include "blockmodel.h"
#include "blockfactory.h"

class QmlSignalHandler : public QObject
{
	Q_OBJECT
public:
	explicit QmlSignalHandler(QObject *parent = 0);
	~QmlSignalHandler();

	BlockModel *model() const;
	void setModel(BlockModel *model);

	BlockFactory factory() const;
	void setFactory(const BlockFactory &factory);

public slots:
	void handleAdd(const QString &blockType, const QString &path);
	void handleSend();
	void handleRun(const QString &name);
	void handleStop();
	void hadleIpChange(const QString &newIp);

private:
	Connector mConnector;
	BlockFactory mFactory;
	BlockModel *mModel;
};
