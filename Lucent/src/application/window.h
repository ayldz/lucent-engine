#pragma once
#include <iostream>
#include <string>
#include <string_view>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../graphics/sprite.h"
#include "../core/sprite_renderer.h"
#include "../core/scene.h"

#include "input.h"

class Window
{
private:
	GLFWwindow* m_wHandle{};

	int m_width{};
	int m_height{};
	std::string m_title{};

	bool m_isClosed{};

public:
	Window(int, int, std::string_view);
	virtual ~Window();

	void Update(Scene& scene);
	void SetTitle(std::string_view);
	//void SetSize(int width, int height);
private:
	void Init();
};



