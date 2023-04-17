#pragma once

#include <vector>
#include <memory>

#include "camera.h"
#include "sprite_renderer.h"

#include "entity.h"
#include "graphics/renderer.h"

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
	void S_Start();
	void S_Update(double);
	void S_Render();

	virtual void Start() {};
	virtual void Update(double) {};
};