#include "game.h"

Game::~Game()
{
	delete m_window;
	m_window = nullptr;

	delete m_scene;
	m_scene = nullptr;

	delete entity;
	entity = nullptr;

	delete renderer;
	renderer = nullptr;
}

void Game::Init()
{
	m_window = new Window(960, 540, "Lucent Engine | FPS : 0.0");
	m_scene = new Scene();
	
	entity = new Entity();
	renderer = new SpriteRenderer("Sprite Renderer");
	transform = new Transform("Transform");
	script = new Script("Script");

	entity->AddComponent(*renderer);
	entity->AddComponent(*transform);
	entity->AddComponent(*script);

	m_scene->AddEntity(*entity);
	

	//TODO: Fix it. Adding second entity is not working
	// 
	//entity2 = new Entity();
	//renderer2 = new SpriteRenderer("Sprite Renderer2");
	//transform2 = new Transform("Transform2");
	//transform2->SetPosition(glm::vec3(750, 250, 0));

	//entity2->AddComponent(*renderer2);
	//entity2->AddComponent(*transform2);

	//m_scene->AddEntity(*entity2);
}

void Game::Run()
{
	m_window->Update(*m_scene);
}
