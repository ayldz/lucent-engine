#pragma once
// this file is test purpose, it will be remove

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "component.h"
#include "transform.h"
#include "../application/input.h"



class Script : public Component
{
private:
	float speed = 1000.0f;
public:
	Script(const std::string& n)
		: Component(n)
	{
	}


	void Start() override {}
	void Update(float dt) override;

	void SetName(const std::string& n);
};