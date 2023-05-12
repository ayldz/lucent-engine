#include "game.h"

Game& Game::Instance()
{
	static Game* instance = new Game;
	return *instance;
}

Game::~Game()
{
	delete m_scene;
	m_scene = nullptr;
	delete m_window;
	m_window = nullptr;
}

void Game::Init()
{
	m_window = new Window(960, 540, "Lucent Engine | FPS : 0.0");
}

void Game::Run()
{
	double lastTime = glfwGetTime();
	double elapsedTime = 0.0;

	// Start 
	this->Start();

	while (!m_window->m_isClosed)
	{
		double current = glfwGetTime();
		double deltaTime = current - lastTime;

		// Calculate FPS
		std::string FPS = std::to_string(static_cast<int>(1.0 / deltaTime));
		std::string title = "Lucent Engine | FPS : " + FPS;

		elapsedTime += deltaTime;

		if (elapsedTime >= 0.5)
		{
			m_window->SetTitle(title);
			elapsedTime = 0.0;
		}

		// Update
		this->Update(deltaTime);
		
		// Render
		this->Render();

		lastTime = current;
	}

	Resources::Clear();
}

void Game::Start() {
	if (m_scene != nullptr)
		m_scene->S_Start();
}

void Game::Update(double deltaTime) {
	if (m_scene !=  nullptr)
		m_scene->S_Update(deltaTime);
	m_window->Update();
}

void Game::Render() {
	if (m_scene != nullptr)
		m_scene->S_Render();
}

void Game::Quit() {

}