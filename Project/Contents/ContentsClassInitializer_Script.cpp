


//=========================================================
//This Code is Automatically generated by CodeGenerator.exe
//=========================================================


#include "PCH_Contents.h"

#include "ContentsClassInitializer.h"
#include <Engine/ComMgr.h>
#include "strKey_Script.h"


#include "Script_TestScript.h"

#define CONSTRUCTOR_T(T) ComMgr::AddComConstructor<T>(strKey::Script::##T)

namespace mh
{
	using namespace mh::define;
	void ContentsClassInitializer::InitScript()
	{
		CONSTRUCTOR_T(Script_TestScript);
	}
}
