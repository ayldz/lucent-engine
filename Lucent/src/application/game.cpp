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

	delete transform;
	transform = nullptr;

	delete entity2;
	entity2 = nullptr;

	delete renderer2;
	renderer2 = nullptr;

	delete transform2;
	transform2 = nullptr;
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

	entity->PrintAllComponents();

	transform->SetPosition(glm::vec3(480, 270,0));
	transform->SetScale(glm::vec3(50.0f, 50.0f, 0.0f));

	//TODO: Fix it. Adding second entity is not working
	 
	entity2 = new Entity();
	renderer2 = new SpriteRenderer("Sprite Renderer2");
	transform2 = new Transform("Transform2");

	entity2->AddComponent(*renderer2);
	entity2->AddComponent(*transform2);
	entity2->PrintAllComponents();

	transform2->SetPosition(glm::vec3(150,150,0));
	transform2->SetScale(glm::vec3(50.0f, 50.0f, 0.0f));

	m_scene->AddEntity(*entity2);
	m_scene->AddEntity(*entity);
}

void Game::Run()
{
	m_window->Update(*m_scene);
}
