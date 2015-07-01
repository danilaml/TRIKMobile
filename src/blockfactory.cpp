#include "blockfactory.h"

#include "blocks/accelerometerBlocks/accelerometerxblock.h"
#include "blocks/accelerometerBlocks/accelerometeryblock.h"
#include "blocks/accelerometerBlocks/accelerometerzblock.h"

#include "blocks/backgroundColorsBlocks/greenblock.h"

#include "blocks/conditionalBlocks/dowhileblock.h"
#include "blocks/conditionalBlocks/forblock.h"
#include "blocks/conditionalBlocks/ifblock.h"
#include "blocks/conditionalBlocks/ifelseblock.h"
#include "blocks/conditionalBlocks/infiniteblock.h"
#include "blocks/conditionalBlocks/negationblock.h"
#include "blocks/conditionalBlocks/whiledoblock.h"

#include "blocks/drawingBlocks/clearscreenblock.h"
#include "blocks/drawingBlocks/smileblock.h"
#include "blocks/drawingBlocks/sadsmileblock.h"

#include "blocks/enginesBlocks/backwardblock.h"
#include "blocks/enginesBlocks/forwardblock.h"
#include "blocks/enginesBlocks/nullifyencoderblock.h"
#include "blocks/enginesBlocks/stopblock.h"

#include "blocks/functionsBlocks/absblock.h"
#include "blocks/functionsBlocks/acosblock.h"
#include "blocks/functionsBlocks/asinblock.h"
#include "blocks/functionsBlocks/atanblock.h"
#include "blocks/functionsBlocks/ceilblock.h"
#include "blocks/functionsBlocks/cosblock.h"
#include "blocks/functionsBlocks/expblock.h"
#include "blocks/functionsBlocks/floorblock.h"
#include "blocks/functionsBlocks/lnblock.h"
#include "blocks/functionsBlocks/randomblock.h"
#include "blocks/functionsBlocks/randomizeblock.h"
#include "blocks/functionsBlocks/sgnblock.h"
#include "blocks/functionsBlocks/sinblock.h"
#include "blocks/functionsBlocks/sqrtblock.h"
#include "blocks/functionsBlocks/timeblock.h"

#include "blocks/gamepadBlocks/gamepadbuttonblock.h"
#include "blocks/gamepadBlocks/gamepadconnectionindicatorblock.h"
#include "blocks/gamepadBlocks/gamepadpadblock.h"
#include "blocks/gamepadBlocks/gamepadpadpresssensorblock.h"
#include "blocks/gamepadBlocks/gamepadwheelblock.h"

#include "blocks/gyroscopeBlocks/gyroscopexblock.h"
#include "blocks/gyroscopeBlocks/gyroscopeyblock.h"
#include "blocks/gyroscopeBlocks/gyroscopezblock.h"

#include "blocks/ledColorsBlocks/ledgreenblock.h"
#include "blocks/ledColorsBlocks/ledredblock.h"
#include "blocks/ledColorsBlocks/offblock.h"
#include "blocks/ledColorsBlocks/orangeblock.h"

#include "blocks/luaPrintingBlocks/additionblock.h"

#include "blocks/messagesBlocks/sendmessageblock.h"

#include "blocks/portsBlocks/gamepadbutton1portblock.h"

#include "blocks/sensorsBlocks/downblock.h"
#include "blocks/sensorsBlocks/enterblock.h"
#include "blocks/sensorsBlocks/escblock.h"
#include "blocks/sensorsBlocks/leftblock.h"
#include "blocks/sensorsBlocks/motionblock.h"
#include "blocks/sensorsBlocks/rightblock.h"
#include "blocks/sensorsBlocks/upblock.h"

#include "blocks/signsBlocks/equalsblock.h"
#include "blocks/signsBlocks/greaterblock.h"
#include "blocks/signsBlocks/lessblock.h"
#include "blocks/signsBlocks/notgreaterblock.h"
#include "blocks/signsBlocks/notlessblock.h"

#include "blocks/subprogramsBlocks/implementationblock.h"
#include "blocks/subprogramsBlocks/subprogramcallblock.h"

#include "blocks/switchBlocks/defaultblock.h"
#include "blocks/switchBlocks/headblock.h"
#include "blocks/switchBlocks/middleblock.h"
#include "blocks/switchBlocks/onecaseblock.h"

#include "blocks/threadsBlocks/callblock.h"

#include "blocks/typesBlocks/intblock.h"

#include "blocks/variablesBlocks/constantdeclarationblock.h"
#include "blocks/variablesBlocks/variabledeclarationblock.h"

#include "blocks/videosensorsBlocks/detectlineblock.h"

#include "blocks/waitBlocks/timerblock.h"

#include "blocks/sayblock.h"


BlockFactory::BlockFactory()
{
	registerBlock<AccelerometerXBlock>("accelerometerXBlock");
	registerBlock<AccelerometerYBlock>("accelerometerYBlock");
	registerBlock<AccelerometerZBlock>("accelerometerZBlock");

	registerBlock<GreenBlock>("greenBlock");

	registerBlock<DoWhileBlock>("doWhileBlock");
	registerBlock<ForBlock>("forBlock");
	registerBlock<IfBlock>("ifBlock");
	registerBlock<IfElseBlock>("ifElseBlock");
	registerBlock<InfiniteBlock>("infiniteBlock");
	registerBlock<NegationBlock>("negationBlock");
	registerBlock<WhileDoBlock>("whileDoBlock");

	registerBlock<ClearScreenBlock>("clearScreenBlock");
	registerBlock<SmileBlock>("smileBlock");
	registerBlock<SadSmileBlock>("sadSmileBlock");

	registerBlock<BackwardBlock>("backwardBlock");
	registerBlock<ForwardBlock>("forwardBlock");
	registerBlock<NullifyEncoderBlock>("nullifyEncoderBlock");
	registerBlock<StopBlock>("stopBlock");

	registerBlock<AbsBlock>("absBlock");
	registerBlock<AcosBlock>("acosBlock");
	registerBlock<AsinBlock>("asinBlock");
	registerBlock<AtanBlock>("atanBlock");
	registerBlock<CeilBlock>("ceilBlock");
	registerBlock<CosBlock>("cosBlock");
	registerBlock<ExpBlock>("expBlock");
	registerBlock<FloorBlock>("floorBlock");
	registerBlock<LnBlock>("lnBlock");
	registerBlock<RandomBlock>("randomBlock");
	registerBlock<RandomizeBlock>("randomizeBlock");
	registerBlock<SgnBlock>("sgnBlock");
	registerBlock<SinBlock>("sinBlock");
	registerBlock<SqrtBlock>("sqrtBlock");
	registerBlock<TimeBlock>("timeBlock");

	registerBlock<GamepadButtonBlock>("gamepadButtonBlock");
	registerBlock<GamepadConnectionIndicatorBlock>("gamepadConnectionIndicatorBlock");
	registerBlock<GamepadPadBlock>("gamepadPadBlock");
	registerBlock<GamepadPadPressSensorBlock>("gamepadPadPressSensorBlock");
	registerBlock<GamepadWheelBlock>("gamepadWheelBlock");

	registerBlock<GyroscopeXBlock>("gyroscopeXBlock");
	registerBlock<GyroscopeYBlock>("gyroscopeYBlock");
	registerBlock<GyroscopeZBlock>("gyroscopeZBlock");

	registerBlock<LedGreenBlock>("ledGreenBlock");
	registerBlock<LedRedBlock>("ledRedBlock");
	registerBlock<OffBlock>("offBlock");
	registerBlock<OrangeBlock>("orangeBlock");

	registerBlock<AdditionBlock>("additionBlock");

	registerBlock<SendMessageBlock>("sendMessageBlock");

	registerBlock<GamepadButton1PortBlock>("gamepadButton1PortBlock");

	registerBlock<DownBlock>("downBlock");
	registerBlock<EnterBlock>("enterBlock");
	registerBlock<EscBlock>("escBlock");
	registerBlock<LeftBlock>("leftBlock");
	registerBlock<MotionBlock>("motionBlock");
	registerBlock<RightBlock>("rightBlock");
	registerBlock<UpBlock>("upBlock");

	registerBlock<EqualsBlock>("equalsBlock");
	registerBlock<GreaterBlock>("greaterBlock");
	registerBlock<LessBlock>("lessBlock");
	registerBlock<NotGreaterBlock>("notGreaterBlock");
	registerBlock<NotLessBlock>("notLessBlock");

	registerBlock<ImplementationBlock>("implementationBlock");
	registerBlock<SubprogramCallBlock>("subprogramCallBlock");

	registerBlock<DefaultBlock>("defaultBlock");
	registerBlock<HeadBlock>("headBlock");
	registerBlock<MiddleBlock>("middleBlock");
	registerBlock<OneCaseBlock>("oneCaseBlock");

	registerBlock<CallBlock>("callBlock");

	registerBlock<IntBlock>("intBlock");

	registerBlock<ConstantDeclarationBlock>("constantDeclarationBlock");
	registerBlock<VariableDeclarationBlock>("variableDeclarationBlock");

	registerBlock<DetectLineBlock>("detectLineBlock");

	registerBlock<TimerBlock>("timerBlock");

	registerBlock<SayBlock>("sayBlock");

}

BlockFactory::~BlockFactory()
{
}

QList<QString> BlockFactory::registeredBlocks() const
{
	return mConstructors.keys();
}

AbstractBlock *BlockFactory::getInstance(const QString &blockType) const
{
	return (const_cast<BlockFactory* const>(this)->*(mConstructors[blockType]))(blockType);
}
