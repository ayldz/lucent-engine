#include "window.h"


namespace lucent
{

	Window::~Window()
	{
		glfwTerminate();
	}
	


	void Window::Init()
	{
		m_isClosed = false;
		m_wHandle = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
		if (!m_wHandle)
		{
			std::cout << "Window cannot be created." << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(m_wHandle);
		glfwSetKeyCallback(m_wHandle, 
			[](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				{
					glfwSetWindowShouldClose(window, true);
				}
			});
	}

	void Window::Update() 
	{
		while (!m_isClosed)
		{
			glClear(GL_COLOR_BUFFER_BIT);

			glClearColor(0.6f, 0.8f, 0.6f, 1.0f);

			glBegin(GL_TRIANGLES);

			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
			glVertex2f(0.0f, 0.5f);

			glEnd();

			glfwSwapBuffers(m_wHandle);
			glfwPollEvents();

			m_isClosed = glfwWindowShouldClose(m_wHandle);
		}
	}

	void Window::SetTitle(std::string_view title)
	{
		m_title = title;
	}

}
