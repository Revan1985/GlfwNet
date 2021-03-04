#pragma once

//#include <msclr\marshal_cppstd.h>
#include <string>

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

#if defined(_DEBUG)
#define GLFWNET_ASSERT(condition)				System::Diagnostics::Debug::Assert(condition, #condition);
#define GLFWNET_ASSERT2(condition, details)	System::Diagnostics::Debug::Assert(condition, #condition, details);
#else
#define GLFWNET_ASSERT(condition)
#define GLFWNET_ASSERT2(condition, details)
#endif

#define GLFWNET_SAFEREF(object, member) ((object) == nullptr ? nullptr : (object)->member)

#define GLFWNET_SAFESTRINGTOSTRINGC_C_STR(string) ((string) == nullptr ? nullptr : GlfwNet::StringToStringC(string).c_str())
#define GLFWNET_SAFESTRINGTOSTRINGW_C_STR(string) ((string) == nullptr ? nullptr : GlfwNet::StringToStringW(string).c_str())

namespace GlfwNet
{
	static std::string StringToStringC(String^ s)
	{
		GLFWNET_ASSERT(s != nullptr);

		char* c = (char*)Marshal::StringToHGlobalAnsi(s).ToPointer();
		std::string strC = std::string(c);

		Marshal::FreeHGlobal(IntPtr(c));
		return strC;
	}

	static std::wstring StringToStringW(String^ s)
	{
		GLFWNET_ASSERT(s != nullptr);

		wchar_t* w = (wchar_t*)Marshal::StringToHGlobalUni(s).ToPointer();
		std::wstring strW = std::wstring(w);

		Marshal::FreeHGlobal(IntPtr(w));
		return strW;
	}

	//static std::string ToManagedString(String^ s)
	//{
	//	std::string unmanagedString = msclr::interop::marshal_as<std::string>(s);
	//	return unmanagedString;
	//}
}
