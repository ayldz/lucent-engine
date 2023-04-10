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
	m_scene = new Scene();
	
	Entity* entity = new Entity();
	entity->AddComponent<SpriteRenderer>("SpriteRenderer");
	entity->AddComponent<Script>("Script");

	
	Transform& transform = entity->AddComponent<Transform>("Transform");
	transform.SetPosition(glm::vec3(480, 270, 0));
	transform.SetScale(glm::vec3(50.0f, 50.0f, 0.0f));
	m_scene->AddEntity(*entity);
}

void Game::Run()
{
	double lastTime = glfwGetTime();
	double elapsedTime = 0.0;

	// Start 
	this->Start();
	m_scene->Start();

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
		m_scene->Update(deltaTime);
		m_window->Update();

		// Render
		this->Render();

		lastTime = current;
	}
}

void Game::Render() {
	m_scene->Render();
}

