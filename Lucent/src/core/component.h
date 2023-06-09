#pragma once

#include <string>
#include <iostream>

#include "entity.h"
#include "camera.h"
class Entity;

class Component 
{
public:
	std::string name;
	Entity* entity;

public:
	Component(const std::string& n)
		: name{ n }, entity{nullptr}
	{
		
	}

	virtual void Start() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(Camera& camera) {};

	void PrintName();
};