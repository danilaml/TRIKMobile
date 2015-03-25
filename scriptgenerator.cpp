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
    for (const QString &names : scriptList.toStringList()) {
        qDebug() << scripts.value(names);
		const QString &names2 = "var __interpretation_started_timestamp__;var pi = 3.14159265;var main = function(){__interpretation_started_timestamp__ = Date.now();brick.display().setBackground(\"white\");while (true) {if (brick.sensor(A1).read() > 50) {brick.sadSmile();} else {brick.smile();}script.wait(10);}}";
		Connector connector("192.168.1.1");
		connector.stopRobot();
		connector.uploadProgram("ProgramName", names2);
		connector.runProgram("ProgramName");
		connector.stopRobot();
    }
}

