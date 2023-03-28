#include "game.h"

Game::Game() {}

Game::~Game()
{
	delete m_window;
	m_window = nullptr;

	delete m_scene;
	m_scene = nullptr;
}

void Game::Init()
{
	m_window = new Window("Lucent Engine | FPS : 0.0", 960, 540);
	m_scene = new Scene();
}

void Game::Run()
{
	m_window->Update(*m_scene);
}
