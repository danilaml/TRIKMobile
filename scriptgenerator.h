#pragma once

#include <QObject>
#include <QMap>

class ScriptGenerator : public QObject
{
    Q_OBJECT
public:
    explicit ScriptGenerator(QObject *parent = 0);
    ~ScriptGenerator();

//signals:

public slots:
    void handleSend(const QVariant &scriptList);

private:
    QMap<QString, QString> scripts;

};
