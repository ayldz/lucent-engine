#pragma once

#include <vector>
#include <memory>

#include "../graphics/sprite.h"
#include "sprite_renderer.h"

#include "entity.h"

class Scene 
{
private:
	std::vector<std::reference_wrapper<Entity>> m_entities;

public:
	Scene();
	~Scene();

	void AddEntity( Entity& e);
	void RemoveEntity();

	void Start();
	void Update(double) const;
};