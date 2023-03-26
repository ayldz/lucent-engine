#pragma once

#include <vector>

#include "component.h"


class Entity 
{
private:
	std::vector<Component> components;

public:
	Entity();
	void Update();

};