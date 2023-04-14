project "Sanbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	files 
	{ 
		"src/**.h",
		"src/**.cpp",
		-- "libs/glm/**.hpp",
		-- "libs/glm/**.inl",
		-- "libs/stb/stb_image.h"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	includedirs
	{
    "%{wks.location}/Lucent/src",
    "%{wks.location}/Lucent/libs/GLFW/include",
		"%{wks.location}/Lucent/libs/Glad/include",
		"%{wks.location}/Lucent/libs/glm",
		"%{wks.location}/Lucent/libs/stb"
	}
	
	links
	{
		"Lucent",
	}
	
	filter "configurations:Debug"
		defines {"DEBUG"}
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines {"RELEASE"}
		runtime "Release"
		symbols "On"