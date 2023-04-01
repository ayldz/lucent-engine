#pragma once


#include "entity.h"

class Component 
{
public:
	const Entity& entity;

	Component();

	virtual void Start();
	virtual void Update(float);

};