
workspace "RM-Engine"
    configurations { "Debug", "Release" }
    architecture "x64"
    startproject "Sandbox"

engineName = "RM-Engine"
launcherName = "RM-Launcher"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = engineName .. "/third-party/glfw"


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
        IncludeDir.GLFW .. "/include",
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
        (launcherName),
        "glfw3dll.lib",
        "opengl32.lib",
        "user32.lib",
        "gdi32.lib",
        "shell32.lib"
    }

    libdirs
    {
        IncludeDir.GLFW .. "/lib-vc2022"
    }
	
	buildoptions { "/utf-8" }

    filter "system:windows"
        systemversion "latest"


    filter "toolset:msc*"
        buildoptions { "/Zc:preprocessor" }