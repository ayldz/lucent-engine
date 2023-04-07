#include "entity.h"

void Entity::AddComponent(Component& c)
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
	for (auto& component : m_components) component.get().Start();

}

void Entity::Update(float dt)
{
	for (auto& component : m_components) component.get().Update(dt);
}