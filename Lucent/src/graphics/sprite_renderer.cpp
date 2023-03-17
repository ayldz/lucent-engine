#include "sprite_renderer.h"

SpriteRenderer::SpriteRenderer(const Sprite& sprite) : m_sprite{ sprite }
{
}

void SpriteRenderer::Prepare()
{
	shader.Prepare();

	float vertices[18];
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glEnableVertexAttribArray(0);

}

void SpriteRenderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.6f, 0.8f, 0.6f, 1.0f);

	shader.Bind();
	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	shader.Unbind();
}
