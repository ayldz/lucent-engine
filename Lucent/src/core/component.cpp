#include "component.h"

void Component::Update(float dt)
{
}

template<typename T>
const T& Entity::GetComponent(const T&)
{
	for (auto& component : m_components)
	{
		T c = dynamic_cast<T&> (component);
		if (typeid(T) == typeid(c))
		{
			return *c;

		}
	}
}