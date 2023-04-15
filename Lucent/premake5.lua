project "Lucent"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"


	files 
	{ 
		"src/**.h",
		"src/**.cpp",
		"libs/glm/**.hpp",
		"libs/glm/**.inl",
		"libs/stb/stb_image.h"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	includedirs
	{
		"src",
		"libs/GLFW/include",
		"libs/Glad/include",
		"libs/Box2D/include",
		"libs/glm",
		"libs/stb"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"Box2D",
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