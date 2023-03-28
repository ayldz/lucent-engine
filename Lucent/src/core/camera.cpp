#include "camera.h"

Camera::Camera(glm::vec3 postiton) : m_position{postiton}
{
	m_projection = glm::mat4(1.0f);
	m_view = glm::mat4(1.0f);

	m_projection = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, 0.0f, 100.0f);
}
