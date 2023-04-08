#pragma once

#include "component.h"
#include "glm/glm.hpp"
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform : public Component
{
private:
	glm::vec3 position = {0.0f, 0.0f, 0.0f};
	glm::vec3 rotation = {0.0f, 0.0f, 0.0f};
	glm::vec3 scale = {1.0f, 1.0f, 1.0f};

public:
	Transform(const std::string &n)
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
		return glm::translate(glm::mat4(1.0f), position) // Translation
					 * glm::toMat4(glm::quat(rotation))				 // Rotation
					 * glm::scale(glm::mat4(1.0f), scale);		 // Scale
	}

	void Start() override {}
	void Update(float dt) override {}

	void SetName(const std::string &n);
};
