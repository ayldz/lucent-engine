#include "sprite_renderer.h"


void SpriteRenderer::SetName(const std::string& n)
{
	name = n;
}

void SpriteRenderer::Prepare()
{
	Sprite sprite{};

	float vertices[32];
	for (size_t i = 0; i < sprite.GetVertices().size(); i++)
	{
		vertices[i] = sprite.GetVertices()[i];
	}

	int triangles[6];
	for (size_t i = 0; i < sprite.GetTriangles().size(); i++)
	{
		triangles[i] = sprite.GetTriangles()[i];
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

	Resources::GetTexture("container").Bind();
}

void SpriteRenderer::Render(Camera& camera)
{
	Resources::GetShader("sprite").Bind();
	Transform& t = entity->GetComponent<Transform>();
	glm::mat4 model = t.GetTransform();

	Resources::GetShader("sprite").SetMat4("model", model);
	Resources::GetShader("sprite").SetMat4("viewProjection", camera.GetViewProjectionMatrix());

	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	Resources::GetShader("sprite").Unbind();
}
