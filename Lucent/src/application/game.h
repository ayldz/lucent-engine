#pragma once

#include <iostream>

#include "window.h"
#include "../core/scene.h"

class Game 
{
private:
	Window* m_window;
	Scene* m_scene;

public:
	Game() = default;
	~Game();

	void Init();
	void Run();
};