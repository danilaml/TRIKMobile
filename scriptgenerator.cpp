#include "scriptgenerator.h"

ScriptGenerator::ScriptGenerator(QObject *parent) : QObject(parent)
{

}

ScriptGenerator::~ScriptGenerator()
{

}

QString ScriptGenerator::generate(QSharedPointer<AbstractBlock> root)
{
//	QString resultCode = readTemplate("main.t");
//		resultCode.replace("@@SUBPROGRAMS_FORWARDING@@", mCustomizer->factory()->subprograms()->forwardDeclarations());
//		resultCode.replace("@@SUBPROGRAMS@@", mCustomizer->factory()->subprograms()->implementations());
//		resultCode.replace("@@THREADS_FORWARDING@@", mCustomizer->factory()->threads().generateDeclarations());
//		resultCode.replace("@@THREADS@@", mCustomizer->factory()->threads().generateImplementations());
//		resultCode.replace("@@MAIN_CODE@@", mainCode);
//		resultCode.replace("@@INITHOOKS@@", utils::StringUtils::addIndent(
//				mCustomizer->factory()->initCode(), 1));
//		resultCode.replace("@@TERMINATEHOOKS@@", utils::StringUtils::addIndent(
//				mCustomizer->factory()->terminateCode(), 1));
//		resultCode.replace("@@USERISRHOOKS@@", utils::StringUtils::addIndent(
//				mCustomizer->factory()->isrHooksCode(), 1));
//		resultCode.replace("@@VARIABLES@@", mCustomizer->factory()->variables()->generateVariableString());
}

