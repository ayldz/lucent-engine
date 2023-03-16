#include "sprite_renderer.h"

SpriteRenderer::SpriteRenderer(const Sprite& sprite) : m_sprite{sprite}
{
	float vertices[18];

	for (size_t i = 0; i < m_sprite.GetVertices().size(); i++)
	{
		vertices[i] = m_sprite.GetVertices()[i];
	}

	unsigned int vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SpriteRenderer::Render() 
{
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0.6f, 0.8f, 0.6f, 1.0f);

	glDrawArrays(GL_TRIANGLES, 0, 6);
}
