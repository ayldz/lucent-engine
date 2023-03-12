workspace "Lucent"
	architecture "x64"
	configurations {"Debug", "Release"}
	
	group "Libs"
		include "Lucent/libs/GLFW"
	group ""
	
	include "Lucent"