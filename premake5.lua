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

--Include directories relative to root folder(solution directory)
IncludeDir = {}
IncludeDir["GLFW"]="Hazel/vendor/GLFW/include"
IncludeDir["Glad"]="Hazel/vendor/Glad/include"
IncludeDir["ImGui"]="Hazel/vendor/imgui"

include "Hazel/vendor/GLFW" --把GLFW项目下的premake添加到此文件中
include "Hazel/vendor/Glad"
include "Hazel/vendor/imgui"

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
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"Glad",
		"GLFW",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"HZ_PLATFORM_WINDOW",
			"HZ_BUILD_DLL",
			"HZ_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/SandBox")
		}

	filter "configurations:Debug"
	defines "HZ_DEBUG"
	buildoptions "/MDd"
	symbols "on"

	filter "configurations:Release"
	defines "HZ_RELEASE"
	buildoptions "/MD"
	optimize "on"

	filter "configurations:Dist"
	defines "HZ_DIST"
	buildoptions "/MD"
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
	buildoptions "/MDd"
	symbols "on"

	filter "configurations:Release"
	defines "HZ_RELEASE"
	buildoptions "/MD"
	optimize "on"

	filter "configurations:Dist"
	defines "HZ_DIST"
	buildoptions "/MD"
	optimize "on"