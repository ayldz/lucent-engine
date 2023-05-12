#include "input.h"

Input &Input::Instance()
{
	static Input *instance = new Input;
	return *instance;
}

void Input::CursorPositionCallback(GLFWwindow *window, double xpos, double ypos)
{
	Instance().m_lastX = Instance().m_posX;
	Instance().m_lastY = Instance().m_posY;
	Instance().m_posX = xpos;
	Instance().m_posY = ypos;
}

bool Input::GetMouseButton(int button)
{
	return Instance().m_mouseButtonPressed[button];
}

bool Input::GetButton(KeyCode key)
{
	return Instance().m_keyPressed[(int)key];
}

void Input::MouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		Instance().m_mouseButtonPressed[button] = true;
	}
	else
	{
		Instance().m_mouseButtonPressed[button] = false;
	}
}

void Input::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		Instance().m_keyPressed[key] = true;
	}
	// TODO: there is also GL_REPEAT action
	else if (action == GLFW_RELEASE)
	{
		Instance().m_keyPressed[key] = false;
	}
}

double Input::GetMousePosX()
{
	return Instance().m_posX;
}

double Input::GetMousePosY()
{
	return Instance().m_posY;
}
