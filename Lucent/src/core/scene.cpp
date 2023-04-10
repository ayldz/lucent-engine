#include "scene.h"

Scene::Scene() 
{
}

Scene::~Scene()
{
}

void Scene::AddEntity(Entity& e)
{
	m_entities.push_back(e);
}

void Scene::Start()
{
	for (size_t i = 0; i < m_entities.size(); i++)
	{
		m_entities[i].get().Start();
	}
}

void Scene::Update(double dt) const
{
	for (size_t i = 0; i < m_entities.size(); i++)
	{
		m_entities[i].get().Update(dt);
	}
}


void Scene::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.6f, 0.8f, 0.6f, 1.0f);
	for (size_t i = 0; i < m_entities.size(); i++)
	{
		
		/* Maybe later...
		if (m_entities[i].get().HasComponent<SpriteRenderer>()) {
			SpriteRenderer& renderer = m_entities[i].get().GetComponent<SpriteRenderer>();
			renderer.Render(camera);
		}
		*/

		m_entities[i].get().Render(camera);
	}
}