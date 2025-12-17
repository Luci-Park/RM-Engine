
workspace "RM-Engine"
    configurations { "Debug", "Release" }
    architecture "x64"
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
engineName = "RM-Engine"
launcherName = "RM-Launcher"


project (engineName)
    location (engineName)
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "%{prj.name}/src/pch.cpp"
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/third-party/spdlog/include",
        engineName .. "/src"
    }
	
	buildoptions { "/utf-8" }
    
    filter "system:windows"
        systemversion "latest"

    filter "toolset:msc*"
        buildoptions { "/Zc:preprocessor" }

project (launcherName)
    location (launcherName)
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "%{prj.name}/src/pch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        engineName .. "/src"
    }

    links
    {
        (engineName)
    }
	
	buildoptions { "/utf-8" }

    filter "system:windows"
        systemversion "latest"

    filter "toolset:msc*"
        buildoptions { "/Zc:preprocessor" }


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "pch.h"
    pchsource "%{prj.name}/src/pch.cpp"
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        engineName .. "/src"
    }

    links
    {
        (launcherName)
    }
	
	buildoptions { "/utf-8" }

    filter "system:windows"
        systemversion "latest"

    filter "toolset:msc*"
        buildoptions { "/Zc:preprocessor" }