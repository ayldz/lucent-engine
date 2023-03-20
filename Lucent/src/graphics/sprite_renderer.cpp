#include "sprite_renderer.h"
#include "stb_image.h"


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "camera.h"

SpriteRenderer::SpriteRenderer(const Sprite& sprite) : m_sprite{ sprite }
{
}

void SpriteRenderer::Prepare()
{
	shader.Prepare();

	float vertices[32];
	for (size_t i = 0; i < m_sprite.GetVertices().size(); i++)
	{
		vertices[i] = m_sprite.GetVertices()[i];
	}

	int triangles[6];
	for (size_t i = 0; i < m_sprite.GetTriangles().size(); i++)
	{
		triangles[i] = m_sprite.GetTriangles()[i];
	}

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &m_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangles), triangles, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//Texture Code


	Texture texture{"res/container.jpg"};
	 
	shader.Bind();
	glUniform1i(glGetUniformLocation(shader.GetID(), "texture1"), 0);

	texture.Bind();
	
}

void SpriteRenderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.6f, 0.8f, 0.6f, 1.0f);

	shader.Bind();

	Camera camera{glm::vec3(0.0f)};

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(720.0f, 270.0f, 0.0f));
	model = glm::scale(model, glm::vec3(100.0f, 100.0f, 100.0f));
	model = glm::rotate(model, -(float)glfwGetTime(), glm::vec3(0.0, 0.0f, 1.0));
	model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));

	glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "projection"), 1, GL_FALSE, glm::value_ptr(camera.GetPojectionMatrix()));

	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	shader.Unbind();

	shader.Bind();
	glm::mat4 model2 = glm::mat4(1.0f);
	model2 = glm::translate(model2, glm::vec3(240.0f, 270.0f, 0.0f));
	model2 = glm::scale(model2, glm::vec3(100.0f, 100.0f, 100.0f));
	model2 = glm::rotate(model2, (float)glfwGetTime(), glm::vec3(0.0, 0.0f, 1.0));
	model2 = glm::translate(model2, glm::vec3(1.0f, 0.0f, 0.0f));

	glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
	glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "projection"), 1, GL_FALSE, glm::value_ptr(camera.GetPojectionMatrix()));

	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	shader.Unbind();
}
