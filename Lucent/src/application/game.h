#pragma once

#include <iostream>

#include "window.h"
#include "../core/scene.h"
#include "../core/script.h"

namespace Lucent {
	class Game
	{
	private:

		Window* m_window = nullptr;
		Scene* m_scene = nullptr;

		Entity* entity;
		SpriteRenderer* renderer;
		Transform* transform;
		Script* script;

	public:
		static Game& Instance();

		Game() = default;
		~Game();

		Game(Game const&) = delete;
		void operator=(Game const&) = delete;

		void Init();
		void Run();
		void Start();
		void Update(double);
		void Render();
		void Quit();

		void SetScene(Scene* s) { m_scene = s; }
	};
}