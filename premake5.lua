workspace "Lucent"
	architecture "x64"
	startproject "Sandbox"
	configurations {"Debug", "Release"}
	
	group "Libs"
		include "Lucent/libs/GLFW"
		include "Lucent/libs/Glad"
	group ""
	
	include "Lucent"
	include "Sandbox"