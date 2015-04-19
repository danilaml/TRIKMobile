#include <QFile>
#include <QTextStream>
#include "scriptgenerator.h"

ScriptGenerator::ScriptGenerator(QObject *parent) : QObject(parent)
{

}

//ScriptGenerator::ScriptGenerator(QMap<QString, QString> &consts, QObject *parent)
//	: QObject(parent), constants(consts)
//{

//}

ScriptGenerator::~ScriptGenerator()
{

}

QString ScriptGenerator::generate(AbstractBlock *root) const
{
	QString resultCode = readTemplate("main.t");
	QString mainCode = root->toString(1);
	resultCode.replace("@@SUBPROGRAMS_FORWARDING@@", "");
	resultCode.replace("@@SUBPROGRAMS@@", "");
	resultCode.replace("@@THREADS_FORWARDING@@", "");
	resultCode.replace("@@THREADS@@", "");
	resultCode.replace("@@MAIN_CODE@@", mainCode);
	resultCode.replace("@@INITHOOKS@@", "");
	resultCode.replace("@@TERMINATEHOOKS@@", "");
	resultCode.replace("@@USERISRHOOKS@@", "");

	QString constsAndVars;
	for (const QString &constName : constants.keys()) {
		constsAndVars += QString("var %1 = %2;\n").arg(constName, constants.value(constName));
	}
	for (const QString &varName : variables) {
		constsAndVars += QString("var %1;").arg(varName);
	}

	resultCode.replace("@@VARIABLES@@", constsAndVars);
	resultCode.replace(QRegExp("\n(\n)+"), "\n\n");

	return resultCode;
}

QString ScriptGenerator::readTemplate(QString &filename) const
{
	QFile templ(QStringLiteral(":/trikQts/templates/") + filename);
	QString res;
	if (!templ.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug("failed to open"); //TODO: add filename
		return res;
	}
	QTextStream input;
	input.setDevice(&templ);
	input.setCodec("UTF-8");
	res = input.readAll();
	templ.close();

	return res;
}

QString ScriptGenerator::readTemplate(const char* filename) const
{
	QFile templ(QStringLiteral(":/trikQts/templates/") + filename);
	QString res;
	if (!templ.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug("failed to open"); //TODO: add filename
		return res;
	}
	QTextStream input;
	input.setDevice(&templ);
	input.setCodec("UTF-8");
	res = input.readAll();
	templ.close();

	return res;
}
QStringList ScriptGenerator::getVars() const
{
	return variables;
}

void ScriptGenerator::setVars(const QStringList &value)
{
	variables = value;
}

QMap<QString, QString> ScriptGenerator::getConstants() const
{
	return constants;
}

void ScriptGenerator::setConstants(const QMap<QString, QString> &value)
{
	constants = value;
}



