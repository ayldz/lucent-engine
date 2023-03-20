#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera 
{
private:
	glm::vec3 m_position;
	
	glm::mat4 m_projection;
	glm::mat4 m_view;

public:
	Camera(glm::vec3 postiton);
	~Camera() = default;

	glm::mat4 GetPojectionMatrix() { return m_projection; }
	glm::mat4 GetViewMatrix() { return m_view; }
};