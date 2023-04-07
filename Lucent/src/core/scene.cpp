#include "scene.h"

Scene::Scene() 
{
}

Scene::~Scene()
{
}

void Scene::AddEntity( Entity& e)
{
	m_entities.push_back(e);
}

void Scene::Start()
{
	for (auto& e : m_entities)
	{
		e.get().Start();
	}
}

void Scene::Update(double dt) const
{
	for (auto& e : m_entities)
	{
		e.get().Update(dt);
	}
}
