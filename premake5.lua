workspace "Hazel"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "SandBox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hazel"
	location "Hazel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Hazel/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}


	filter "system:windows"
		cppdialect "c++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"HZ_PLATFORM_WINDOW",
			"HZ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/SandBox")
		}

	filter "configurations:Debug"
	defines "HZ_DEBUG"
	symbols "on"

	filter "configurations:Release"
	defines "HZ_RELEASE"
	optimize "on"

	filter "configurations:Dist"
	defines "HZ_DIST"
	optimize "on"


project "SandBox"
	location "SandBox"
	kind "consoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hazel/vendor/spdlog/include",
		"Hazel/src"
	}

	links
	{
		"Hazel"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "on"
		systemversion "latest"


		defines
		{
			"HZ_PLATFORM_WINDOW"
		}


	filter "configurations:Debug"
	defines "HZ_DEBUG"
	symbols "on"

	filter "configurations:Release"
	defines "HZ_RELEASE"
	optimize "on"

	filter "configurations:Dist"
	defines "HZ_DIST"
	optimize "on"