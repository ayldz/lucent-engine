workspace "Lucent"
	architecture "x64"
	configurations {"Debug", "Release"}
	
project "lucent"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	targetdir "bin/%{cfg.buildcfg}"
	
	files { "src/**.h", "src/**.hpp", "src/.c", "src/.cpp"}
	
	filter "configurations:Debug"
		defines {"DEBUG"}
		symbols "On"
	
	filter "configurations:Release"
		defines {"RELEASE"}
		symbols "On"