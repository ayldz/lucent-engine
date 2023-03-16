#pragma once
#include <iostream>
#include <string>
#include <string_view>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../graphics/sprite.h"
#include "../graphics/sprite_renderer.h"
#include "input.h"

namespace lucent
{
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

		void Update();

		void SetTitle(std::string_view);
	
	private:
		void Init();
	};
}


