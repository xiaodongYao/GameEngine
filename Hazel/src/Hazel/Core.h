#pragma once

#ifdef HZ_PLATFORM_WINDOW
	#ifdef HZ_BUILD_DLL
		#define HZ_API __declspec(dllexport)
	#else
		#define HZ_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#error hazel only support winodws!

#endif // HZ_PLATFORM_WINDOW
