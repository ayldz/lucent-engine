#include "input.h"


namespace lucent 
{

	Input* Input::Get()
	{
		if (!instance)
		{
			instance = new Input();
		}
		return instance;
	}

	void Input::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
	{
		Get()->m_lastX = Get()->m_posX;
		Get()->m_lastY = Get()->m_posY;
		Get()->m_posX = xpos;
		Get()->m_posY = ypos;
	}

	bool Input::GetMouseButton(int button)
	{
		return Get()->m_mouseButtonPressed[button];
	}

	bool Input::GetButton(int key) 
	{
		return Get()->m_keyPressed[key];
	}

	void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if (action == GLFW_PRESS)
		{
			Get()->m_mouseButtonPressed[button] = true;
		}
		else
		{
			Get()->m_mouseButtonPressed[button] = false;
		}
	}

	void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
		{
			Get()->m_keyPressed[key] = true;
		}
		else
		{
			Get()->m_keyPressed[key] = false;
		}
	}

	double Input::GetMousePosX()
	{
		return Input::Get()->m_posX;
	}

	double Input::GetMousePosY()
	{
		return Input::Get()->m_posY;
	}
}