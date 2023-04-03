#include "scene.h"

Scene::Scene() 
{
	m_renderer = std::make_unique<SpriteRenderer>();
	m_renderer->Prepare();
}

Scene::~Scene()
{
}

void Scene::Update(double dt) const
{
	m_renderer->Render();
}
