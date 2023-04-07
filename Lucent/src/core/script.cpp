#include "Script.h"

void Script::Update(float dt)
{
	Transform& t = entity->GetComponent<Transform>();

	if (Input::GetButton(GLFW_KEY_LEFT))
	{
		glm::vec3 p = t.GetPosition();
		glm::vec3 newPos = glm::vec3(p.x - (1.0f * speed * dt), p.y, p.z) ;
		t.SetPosition(newPos);
	}

	else if (Input::GetButton(GLFW_KEY_RIGHT))
	{
		glm::vec3 p = t.GetPosition();
		glm::vec3 newPos = glm::vec3(p.x + (1.0f * speed * dt), p.y, p.z) ;
		t.SetPosition(newPos);
	}

	if (Input::GetButton(GLFW_KEY_UP))
	{
		glm::vec3 p = t.GetPosition();
		glm::vec3 newPos = glm::vec3(p.x, p.y + (1.0f * speed * dt), p.z) ;
		t.SetPosition(newPos);
	}

	else if (Input::GetButton(GLFW_KEY_DOWN))
	{
		glm::vec3 p = t.GetPosition();
		glm::vec3 newPos = glm::vec3(p.x, p.y - (1.0f * speed * dt), p.z);
		t.SetPosition(newPos);
	}
}

void Script::SetName(const std::string& n)
{
	name = n;
}
