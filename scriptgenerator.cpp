#include "scriptgenerator.h"
#include <QDebug>
#include <QVariant>

#include "connector.h"

ScriptGenerator::ScriptGenerator(QObject *parent) : QObject(parent)
{
	scripts["Forward"] = "Forward script";
	scripts["Backwards"] = "Backwards script";
	scripts["Right"] = "Right script";
	scripts["Left"] = "Left script";
}

ScriptGenerator::~ScriptGenerator()
{

}

void ScriptGenerator::handleSend(const QVariant &scriptList) {
	//qDebug() << scriptList.toStringList();
	QStringList list = scriptList.toStringList();
	for (const QString &names : scriptList.toStringList()) {
		qDebug() << scripts.value(names);
		//Connector connector();
	}
	Connector test(list.last());
	test.uploadProgram("test", "ar __interpretation_started_timestamp__;"
						"var pi = 3.14159265;"
						"var S;"
						"var Sold;"
						"var u;"
						"var main = function()"
					   "{"
						" __interpretation_started_timestamp__ = Date.now();"

						  " S = brick.sensor(A1).read();"
						  " Sold = S;"
						   "while (true) {"
							   "u = 2.5 * (S - brick.sensor(A1).read()) + 5 * (Sold - brick.sensor(A1).read());"
							   "Sold = brick.sensor(A1).read();"
							   "brick.motor(M4).setPower(50 - u);"
							   "brick.motor(M3).setPower(50 + u);"
							   "script.wait(30);"
						   "}"
					   "}");
}

