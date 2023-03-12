project "Lucent"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	targetdir "bin/%{cfg.buildcfg}"
	
	files 
	{ 
		"src/**.h",
		"src/**.cpp",
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	filter "configurations:Debug"
		defines {"DEBUG"}
		symbols "On"
	
	filter "configurations:Release"
		defines {"RELEASE"}
		symbols "On"