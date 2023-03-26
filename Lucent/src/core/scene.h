#pragma once

#include <vector>

#include "../graphics/sprite.h"
#include "../graphics/sprite_renderer.h"

#include "entity.h"

class Scene 
{
private:
	std::vector<Entity> entities;

	Sprite m_sprite;
	SpriteRenderer m_spriteRenderer;

public:
	Scene(const Sprite& sprite, const SpriteRenderer& spriteRenderer);
	~Scene() = default;
	void Update();
};