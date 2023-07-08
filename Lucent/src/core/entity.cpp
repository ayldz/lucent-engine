#include "entity.h"

namespace Lucent {

	void Entity::AddExistingComponent(Component& c)
	{
		c.entity = this;
		m_components.push_back(c);
	}

	void Entity::PrintAllComponents()
	{
		for (size_t i = 0; i < m_components.size(); i++)
		{
			m_components[i].get().PrintName();
		}
	}

	void Entity::Start()
	{
		for (size_t i = 0; i < m_components.size(); i++)
		{
			m_components[i].get().Start();
		}

	}

	void Entity::Update(float dt)
	{


		for (size_t i = 0; i < m_components.size(); i++)
		{
			m_components[i].get().Update(dt);
		}
	}

	void Entity::Render(Camera& camera) {
		for (size_t i = 0; i < m_components.size(); i++)
		{
			m_components[i].get().Render(camera);
		}
	}
}