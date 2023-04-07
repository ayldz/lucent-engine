#pragma once

#include "component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform : public Component
{
private:
	glm::vec3 position = { 0.0f, 0.0f, 0.0f };

public:
	Transform(const std::string& n)
		: Component(n)
	{
	}

	inline glm::vec3 GetPosition() const { return position; }

	void SetPosition(glm::vec3 pos) 
	{
		position = pos;
	}

	inline glm::mat4 GetTransform() 
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, position);
		model = glm::scale(model, glm::vec3(50.0f, 50.0f, 0.0f));

		return model; 
	}

	void Start() override{}
	void Update(float dt) override {}

	void SetName(const std::string& n);
};