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
	
	includedirs
	{
		"libs/GLFW/include"
	}
	
	links
	{
		"GLFW",
		"opengl32.lib"
	}
	
	filter "configurations:Debug"
		defines {"DEBUG"}
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines {"RELEASE"}
		runtime "Release"
		symbols "On"