#pragma once

#include <GLFW/glfw3.h>

#include <array>

namespace lucent
{
	class Input
	{
		// Mouse Position Variables
	private:
		static Input* instance;

		double m_scrollX{}, m_scrollY{};
		double m_posX{}, m_posY{};
		double m_lastX{}, m_lastY{};

		std::array<bool, 3> m_mouseButtonPressed{};
		std::array<bool, 350> m_keyPressed{};

	private:
		Input() = default;

	public:
		
		static Input* Get();

		static double GetMousePosX();
		static double GetMousePosY();
		static bool GetButton(int key);
		static bool GetMouseButton(int button);

		static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};

}

