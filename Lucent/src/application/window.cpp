#include "window.h"


Window::Window(int width = 960, int height = 540, std::string_view title = "Lucent Engine")
	: m_width{ width }, m_height{ height }, m_title{title}
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

	glViewport(0, 0, m_width, m_height);

	glfwSetCursorPosCallback(m_wHandle, Input::CursorPositionCallback);
	glfwSetMouseButtonCallback(m_wHandle, Input::MouseButtonCallback);
	glfwSetKeyCallback(m_wHandle, Input::KeyCallback);
}

void Window::Update() {
	if (Input::GetButton(KeyCode::Escape))
	{
		glfwSetWindowShouldClose(m_wHandle, true);
	}

	glfwSwapBuffers(m_wHandle);
	glfwPollEvents();

	m_isClosed = glfwWindowShouldClose(m_wHandle);
}

void Window::SetTitle(std::string_view title)
{
	m_title = title;
	glfwSetWindowTitle(m_wHandle, m_title.c_str());
}

