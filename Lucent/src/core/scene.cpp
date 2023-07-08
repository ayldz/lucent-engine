#include "scene.h"

namespace Lucent {

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

	void Scene::RemoveEntity()
	{
	}

	void Scene::S_Start()
	{
		this->Start();

		for (size_t i = 0; i < m_entities.size(); i++)
		{
			m_entities[i].get().Start();
		}

		Renderer::Prepare();
	}

	void Scene::S_Update(double dt)
	{
		this->Update(dt);

		for (size_t i = 0; i < m_entities.size(); i++)
		{
			m_entities[i].get().Update(dt);
		}
	}


	void Scene::S_Render()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.6f, 0.8f, 0.6f, 1.0f);

		Renderer::SetViewProjectionMatrix(camera.GetViewProjectionMatrix());

		for (size_t i = 0; i < m_entities.size(); i++)
		{
			if (m_entities[i].get().HasComponent<SpriteRenderer>()) {
				SpriteRenderer& renderer = m_entities[i].get().GetComponent<SpriteRenderer>();
				renderer.Render(camera);
			}

			//m_entities[i].get().Render(camera);		
		}
	}
}