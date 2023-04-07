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

void Window::Update(Scene& scene)
{
	double lastTime = glfwGetTime();
	double elapsedTime = 0.0;

	scene.Start();

	while (!m_isClosed)
	{
		double current = glfwGetTime();
		double deltaTime = current - lastTime;

		std::string FPS = std::to_string(static_cast<int>(1.0 / deltaTime));
		std::string title = "Lucent Engine | FPS : " + FPS;

		elapsedTime += deltaTime;

		if (elapsedTime >= 0.5)
		{
			SetTitle(title);
			elapsedTime = 0.0;
		}

		scene.Update(deltaTime);

		if (Input::GetButton(GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(m_wHandle, true);
		}

		glfwSwapBuffers(m_wHandle);
		glfwPollEvents();

		lastTime = current;

		m_isClosed = glfwWindowShouldClose(m_wHandle);
	}
}

void Window::SetTitle(std::string_view title)
{
	m_title = title;
	glfwSetWindowTitle(m_wHandle, m_title.c_str());
}

