#include "entity.h"

void Entity::Update()

{
	for (size_t i = 0; i < components.size(); i++)
	{
		components[i].Update();
	}
}
