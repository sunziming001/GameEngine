#include "core/AbsGameApplication.h"


AbsGameApplication::AbsGameApplication(int argc, char** argv)
{

}

void AbsGameApplication::exec()
{
	std::string strHint;
	AbsGameApplication::AppStage curStage = AbsGameApplication::Init;

	if (onInit(strHint))
	{
		while (onCanNextLoop())
		{
			curStage = AbsGameApplication::BeforeRender;
			if (!onBeforeRender(strHint))
			{
				onErrorHint(curStage, strHint);
				break;
			}
				

			curStage = AbsGameApplication::Render;
			if (!onRender(strHint))
			{
				onErrorHint(curStage, strHint);
				break;
			}

			curStage = AbsGameApplication::AfterRender;
			if (!onAfterRender(strHint))
			{
				onErrorHint(curStage, strHint);
				break;
			}
		}
	}
	else
	{
		onErrorHint(curStage, strHint);
	}

	curStage = AbsGameApplication::Uninit;
	
	if (onUninit(strHint))
	{
		onOverHint(curStage, strHint);
	}
	else {
		onErrorHint(curStage, strHint);
	}

}