#pragma once
#include <iostream>
#include <string>
#include <string_view>

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
		Window(std::string_view title, int width, int height)
			: m_title{ title }, m_width{ width }, m_height{ height } 
		{
			if (!glfwInit())
			{
				std::cout << "glfw cannot be initialized." << std::endl;
			}
			else
			{
				Init();
			}
		}

		virtual ~Window();

		void Update();

		void SetTitle(std::string_view title);
	
	private:
		void Init();
	};
}


