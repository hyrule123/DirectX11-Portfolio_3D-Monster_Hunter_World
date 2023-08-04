#pragma once

#include <regex>
#include <filesystem>

namespace stdfs = std::filesystem;

#ifndef DEBUG_BREAK
#ifdef _DEBUG
#define DEBUG_BREAK DebugBreak()
#else
#define DEBUG_BREAK
#endif
#endif


//#define PRESET constexpr const char*

#define PRESET(_VarNameBase, _String) \
namespace _VarNameBase {\
constexpr const char* A = _String;\
constexpr const wchar_t* W = L##_String;\
}


namespace define_Preset
{
	namespace Path
	{
		PRESET(ContentsProj, "./Project/Contents");
		PRESET(EngineProj, "./Project/Engine");
		PRESET(HLSL_Proj, "./Project/HLSL");


#ifdef _DEBUG
		PRESET(Content, "./Output/Debug/Res");
#else
		PRESET(Content, "./Output/Release/Res");
#endif

		

	}
	
	namespace Keyword
	{

		PRESET(arrNumThreads, "arrNumThreads");
		
		PRESET(ScriptPrefix, "Script_");

		PRESET(IncludeBegin, "#include \"");

		PRESET(NameSpace, "namespace ");
		PRESET(ConstexprInlineConstChar, "PRESET(");
		PRESET(EqualDoubleQuotation, ", \"");
		PRESET(EnumClass, "enum class ");
		PRESET(strKey, "strKey_");

		PRESET(DefineSTRKEY, 
R"(#ifndef STRKEY
#define STRKEY constexpr const char*
#endif
)");


		PRESET(Head, R"(
#pragma once


//=========================================================
//This Code is Automatically generated by CodeGenerator.exe
//=========================================================

)");
		PRESET(Define_Constructor_T,
			R"(#define CONSTRUCTOR_T(T) )"
		);

		PRESET(Constructor_T, "CONSTRUCTOR_T(");
	}

	namespace Regex
	{

		constexpr const char* arrCharsVarForbiddenA[] =
		{
			"\\(","\\)",
			"\\{","\\}",
			"\\[","\\]",
			"\\.","\\s"
		};


		namespace g_VarForbiddenChars
		{
			extern std::regex A;
			extern std::wregex W;
			void CreateVarForbiddenRegex();
		}

		PRESET(AllShader, R"(\w+\.hlsl$)");
		PRESET(CShaderRegex, R"(CS_\w+\.hlsl$)");
		PRESET(ScriptRegex, R"(Script_.+\.h)");
		PRESET(ComponentRegex, R"(Com_.+\.h)");
		
		//[   numthreads   ( %d, %d, %d )   ]
		//[ ] 안에 둘러싸여 있고, 공백 갯수에 상관없이 숫자 3개를 추출
		PRESET(Numthread, R"(.*\((\d+),(\d+),(\d+\)).*)");
	}
}


#include <Engine/define_GPU.h>
namespace define_ShaderGen
{
	struct tShaderSetting
	{
		stdfs::path FileName[(int)mh::define::eGSStage::END];
	};
}

