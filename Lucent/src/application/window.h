#pragma once
#include <iostream>
#include <string>
#include <string_view>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../graphics/sprite.h"
#include "../core/sprite_renderer.h"
#include "input.h"

#include "../core/scene.h"


class Window
{
private:
	GLFWwindow* m_wHandle{};

	int m_width{};
	int m_height{};
	std::string m_title{};

	bool m_isClosed{};

public:
	Window(std::string_view title, int, int);
	virtual ~Window();

	void Update(const Scene& scene);
	void SetTitle(std::string_view);
	//void SetSize(int width, int height);
private:
	void Init();
};



