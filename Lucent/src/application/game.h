#pragma once

#include <iostream>

#include "window.h"
#include "../core/scene.h"
#include "../core/script.h"

class Game 
{
private:
	Window* m_window;
	Scene* m_scene;

	Entity* entity;
	SpriteRenderer* renderer;
	Transform* transform;
	Script* script;

	Entity* entity2;
	SpriteRenderer* renderer2;
	Transform* transform2;

public:
	Game() = default;
	~Game();

	void Init();
	void Run();
};