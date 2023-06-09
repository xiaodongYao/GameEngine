#pragma once

#ifdef HZ_PLATFORM_WINDOW

#if HZ_DYNAMIC_LINK
	#ifdef HZ_BUILD_DLL
		#define HZ_API __declspec(dllexport)
	#else
		#define HZ_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#define HZ_API
#endif
#else
	#error hazel only support winodws!
#endif // HZ_PLATFORM_WINDOW


#ifdef HZ_DEBUG
	#define HZ_ENABLE_ASSERTS
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) {if(!(x)) { HZ_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak; } }
	#define HZ_CORE_ASSERT(x, ...) {if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak; } }
#else
	#define HZ_ASSERT(x,...)
	#define HZ_CORE_ASSERT(x,...)

#endif // HZ_ENABLE_ASSERTS


#define BIT(x) (1<<x)

#define HAZEL_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)