#pragma once

#include <QObject>
#include <QMap>
#include <QStringList>
#include "blocks/abstractblock.h"

class ScriptGenerator : public QObject
{
	Q_OBJECT
public:
	explicit ScriptGenerator(QObject *parent = 0);
	//ScriptGenerator(QMap<QString, QString> &consts, QObject *parent = 0);
	~ScriptGenerator();

	QString generate(AbstractBlock *root) const;

	QMap<QString, QString> getConstants() const;
	void setConstants(const QMap<QString, QString> &value);

	QStringList getVars() const;
	void setVars(const QStringList &value);

private:
	QString readTemplate(QString &filename) const;
	QString readTemplate(const char *filename) const;

	QMap<QString, QString> constants;
	QStringList variables;
};
