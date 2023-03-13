#pragma once
#include <iostream>
#include <string>
#include <string_view>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
		Window(std::string_view, int, int);

		virtual ~Window();

		void Update();

		void SetTitle(std::string_view);
	
	private:
		void Init();
	};
}


