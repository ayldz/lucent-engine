#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <functional>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include "input.h"


class Window
{
private:
	GLFWwindow* m_wHandle{};

	int m_width{};
	int m_height{};
	std::string m_title{};

public:
	bool m_isClosed{};

	Window(int, int, std::string_view);
	~Window();

	void Update();
	void SetTitle(std::string_view);

	void UpdateWindowSize(int width, int height);
private:
	void Init();
};



