#include "scriptgenerator.h"
#include <QDebug>
#include <QVariant>

ScriptGenerator::ScriptGenerator(QObject *parent) : QObject(parent), mConnector("192.168.1.1")
{
	mScripts["Forward"] = "Forward script";
	mScripts["Backwards"] = "Backwards script";
	mScripts["Right"] = "Right script";
	mScripts["Left"] = "Left script";
}

ScriptGenerator::~ScriptGenerator()
{

}

void ScriptGenerator::handleSend(const QVariant &scriptList)
{
    //qDebug() << scriptList.toStringList();
	QStringList list = scriptList.toStringList();
	for (const QString &names : list)
	{
		qDebug() << mScripts.value(names);
//		const QString &names2 = "var __interpretation_started_timestamp__;var pi = 3.14159265;var main = function(){__interpretation_started_timestamp__ = Date.now();brick.display().setBackground(\"white\");while (true) {if (brick.sensor(A1).read() > 50) {brick.sadSmile();} else {brick.smile();}script.wait(10);}}";
//		Connector connector("192.168.1.1");
//		connector.uploadProgram("ProgramName", names2);
//		connector.runProgram("ProgramName");
//		connector.stopRobot();
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

