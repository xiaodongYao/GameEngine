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
IncludeDir["glm"]="Hazel/vendor/glm"

include "Hazel/vendor/GLFW" --��GLFW��Ŀ�µ�premake���ӵ����ļ���
include "Hazel/vendor/Glad"
include "Hazel/vendor/imgui"

project "Hazel"
	location "Hazel"
	kind "StaticLib"
	language "C++"
	cppdialect "c++17"
	staticruntime "on"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Hazel/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Glad",
		"GLFW",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HZ_PLATFORM_WINDOW",
			"HZ_BUILD_DLL",
			--"HZ_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}

		--postbuildcommands
		--{
			--("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .."/SandBox/\"")
		--}

	filter "configurations:Debug"
	defines "HZ_DEBUG"
	runtime "Debug"
	symbols "on"

	filter "configurations:Release"
	defines "HZ_RELEASE"
	runtime "Release"
	optimize "on"

	filter "configurations:Dist"
	defines "HZ_DIST"
	runtime "Release"
	optimize "on"


project "SandBox"
	location "SandBox"
	kind "consoleApp"
	language "C++"
	cppdialect "c++17"
	staticruntime "on"

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
		"Hazel/src",
		"Hazel/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Hazel"
	}

	filter "system:windows"
		systemversion "latest"


		defines
		{
			"HZ_PLATFORM_WINDOW"
		}


	filter "configurations:Debug"
	defines "HZ_DEBUG"
	runtime "Debug"
	symbols "on"

	filter "configurations:Release"
	defines "HZ_RELEASE"
	runtime "Release"
	optimize "on"

	filter "configurations:Dist"
	defines "HZ_DIST"
	runtime "Release"
	optimize "on"