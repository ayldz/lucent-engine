#include "window.h"

namespace lucent
{
	Window::Window(std::string_view title , int width , int height )
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

		if (!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}

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
		float vertices[] = 
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		unsigned int vbo;
		
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3, 0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		while (!m_isClosed)
		{
			glClear(GL_COLOR_BUFFER_BIT);

			glClearColor(0.6f, 0.8f, 0.6f, 1.0f);

			glDrawArrays(GL_TRIANGLES, 0, 3);

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
