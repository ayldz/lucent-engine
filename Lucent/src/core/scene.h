#pragma once

#include <vector>
#include <memory>

#include "../graphics/sprite.h"
#include "sprite_renderer.h"

#include "entity.h"

class Scene 
{
private:
	std::unique_ptr<SpriteRenderer> m_renderer;
	std::vector<const Entity&> m_entities;

public:
	Scene();
	~Scene();

	void Start();
	void Update(double) const;
};