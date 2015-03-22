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
		//Connector connector();
    }
}

