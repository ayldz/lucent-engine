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


public:
	static Game& Instance();

	Game() = default;
	~Game();

	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	void Init();
	void Run();
	void Render();

	// Todo: virtual void Load...
	virtual void Start() {} ;
	virtual void Update(double) {};
	virtual void Quit() {};
};