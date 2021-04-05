#ifndef ABSGAMEAPPLICATION_H
#define ABSGAMEAPPLICATION_H

#include "CoreMacros.h"
#include <string>

class IMPORT_EXPORT AbsGameApplication
{
public:
	enum AppStage {
		Init,
		BeforeRender,
		Render,
		AfterRender,
		Uninit
	};
	AbsGameApplication(int argc, char** argv);
	void exec();

protected:
	virtual bool onInit(std::string& errHint)=0;
	virtual bool onCanNextLoop() = 0;
	virtual bool onBeforeRender(std::string& errHint) = 0;
	virtual bool onRender(std::string& errHint) = 0;
	virtual bool onAfterRender(std::string& errHint) = 0;
	virtual bool onUninit(std::string& errHint) = 0;

	virtual void onErrorHint(AbsGameApplication::AppStage stage, const std::string& errHint)=0;
	virtual void onOverHint(AbsGameApplication::AppStage stage, const std::string& overHint)=0;


};


#endif