#include "window.h"


Window::Window(std::string_view title = "Lucent Engine", int width = 960, int height = 540)
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

	glViewport(0, 0, m_width, m_height);

	glfwSetCursorPosCallback(m_wHandle, Input::CursorPositionCallback);
	glfwSetMouseButtonCallback(m_wHandle, Input::MouseButtonCallback);
	glfwSetKeyCallback(m_wHandle, Input::KeyCallback);
}

void Window::Update(const Scene& scene)
{
	double lastTime = glfwGetTime();
	unsigned int fpsCounter = 0;
	double lag = 0.0;

	while (!m_isClosed)
	{
		double current = glfwGetTime();
		double deltaTime = current - lastTime;

		fpsCounter++;
		lag += deltaTime;

		if (lag >= 1.0 )
		{
			std::string FPS = std::to_string((1.0 / deltaTime) * fpsCounter);
			std::string title = "Lucent Engine | FPS : " + FPS;

			SetTitle(title);

			fpsCounter = 0;
			lag = 0;
		}

		scene.Update(deltaTime);

		if (Input::GetMouseButton(0))
		{
			std::cout << "Mouse Button 0" << std::endl;
		}

		if (Input::GetButton(GLFW_KEY_SPACE))
		{
			std::cout << "Space key is pressed.." << std::endl;
		}

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

