#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera 
{
protected:
	glm::vec3 m_position;
	glm::vec3 m_rotation = { 0, 0, 0 };

	glm::mat4 m_projection;
	glm::mat4 m_view;

	void CalculateViewMatrix();

public:
	Camera(glm::vec3 position);
	~Camera() = default;

	glm::mat4 GetPojectionMatrix() { return m_projection; }
	glm::mat4 GetViewMatrix() { return m_view; }
	glm::vec3 GetPosition() { return m_position; };
	glm::vec3 GetRotation() { return m_rotation; };
	glm::mat4 GetViewProjectionMatrix();

	void SetPosition(glm::vec3 p);
	void SetRotation(glm::vec3 r);
	void Move(glm::vec3 p);
	void Rotate(glm::vec3 r);
};