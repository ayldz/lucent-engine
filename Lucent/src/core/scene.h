#pragma once

#include <vector>
#include <memory>

#include "../graphics/sprite.h"
#include "camera.h"
#include "sprite_renderer.h"

#include "entity.h"

class Scene 
{
private:
	std::vector<std::reference_wrapper<Entity>> m_entities;

public:
	Camera camera;

	Scene();
	~Scene();

	void AddEntity( Entity& e);
	void RemoveEntity();

	// Todo: void Load...
	void Start();
	void Update(double) const;
	void Render();
};