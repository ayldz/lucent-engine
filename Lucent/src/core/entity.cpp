#include "entity.h"

void Entity::Start()
{
	for (auto component : m_components) component.Start();

}

void Entity::Update(float dt)
{
	for (auto component : m_components) component.Update(dt);
}