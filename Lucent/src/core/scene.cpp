#include "scene.h"

Scene::Scene() 
{
	m_renderer = new SpriteRenderer();
	m_renderer->Prepare();
}

Scene::~Scene()
{
	delete m_renderer;
	m_renderer = nullptr;
}

void Scene::Update(double dt) const
{
	m_renderer->Render();
}
