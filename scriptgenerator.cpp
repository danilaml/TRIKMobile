#include "scriptgenerator.h"
#include <QDebug>
#include <QVariant>

ScriptGenerator::ScriptGenerator(QObject *parent) : mConnector("192.168.1.1"), QObject(parent)
{
	mScripts["Forward"] = "Forward script";
	mScripts["Backwards"] = "Backwards script";
	mScripts["Right"] = "Right script";
	mScripts["Left"] = "Left script";
}

ScriptGenerator::~ScriptGenerator()
{

}

void ScriptGenerator::handleSend(const QVariant &scriptList) {
	//qDebug() << scriptList.toStringList();
	QStringList list = scriptList.toStringList();
	for (const QString &names : list) {
		qDebug() << mScripts.value(names);
		//Connector connector();
	}
//	Connector test(list.last());
//	test.uploadProgram("test", "ar __interpretation_started_timestamp__;"
//						"var pi = 3.14159265;"
//						"var S;"
//						"var Sold;"
//						"var u;"
//						"var main = function()"
//					   "{"
//						" __interpretation_started_timestamp__ = Date.now();"

//						  " S = brick.sensor(A1).read();"
//						  " Sold = S;"
//						   "while (true) {"
//							   "u = 2.5 * (S - brick.sensor(A1).read()) + 5 * (Sold - brick.sensor(A1).read());"
//							   "Sold = brick.sensor(A1).read();"
//							   "brick.motor(M4).setPower(50 - u);"
//							   "brick.motor(M3).setPower(50 + u);"
//							   "script.wait(30);"
//						   "}"
//					   "}");
//	test.runProgram("test");
}

void ScriptGenerator::handleRun(const QString &name)
{
	mConnector.runProgram(name);
}

void ScriptGenerator::handleStop()
{
	mConnector.stopRobot();
}

