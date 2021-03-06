workspace "MathsQuiz"
    architecture "x64"
    language "C++"
	cppdialect "C++20"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MathsQuiz"
    location "MathsQuiz"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/intermediates/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/resource/**.ico",
    }

    filter "system.windows"
        cppdialect "C++20"
        systemversion "latest"
