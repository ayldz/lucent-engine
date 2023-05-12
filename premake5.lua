workspace "Lucent"
	architecture "x64"
	startproject "Sandbox"
	configurations {"Debug", "Release"}
	
	group "Libs"
		include "Lucent/libs/GLFW"
		include "Lucent/libs/Glad"
		include "Lucent/libs/Box2D"
	group ""
	
	include "Lucent"
	include "Sandbox"