
workspace ("InsightMath")
	architecture ("x86_64")

	configurations
	{
		"Develop-Exe",
		--"Debug-Lib",
		--"Release-Lib",
	}

	buildFolder = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project ("Library")
	filter "configurations:*Exe"
		kind "ConsoleApp"
	--filter "configurations:*Lib"
	--	kind "StaticLib"
	location ("") -- Root Directory
	language ("C++")
	cppdialect ("C++17")
	targetname ("InsightMath")
	

	targetdir("Binaries/" .. buildFolder)
	objdir("Binaries/Intermediates/" .. buildFolder)

	files
	{
		"Include/**.h",
		"Include/**.cpp",
		"Source/**.h",
		"Source/**.cpp",
	}

	includedirs
	{
		"Include/",
		"Source/",
	}

filter "configurations:Debug-Lib"
	defines "_DEBUG"
	runtime "Debug"
	symbols "on"

filter "configurations:Develop-Exe"
	defines "_DEVELOPMENT"
	runtime "Debug"
	symbols "on"
	
filter "configurations:Release-Lib"
	defines "_RELEASE"
	runtime "Release"
	optimize "on"
	symbols "on"