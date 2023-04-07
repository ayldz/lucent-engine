#include "sprite_renderer.h"


void SpriteRenderer::SetName(const std::string& n)
{
	name = n;
}

void SpriteRenderer::Prepare()
{
	shader.Prepare("./res/Shaders/VertexShader.vert", "./res/Shaders/FragmentShader.frag");

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

	Texture texture{ "res/container.jpg" };

	shader.Bind();
	shader.SetInt("texture1", 0);

	texture.Bind();

}

void SpriteRenderer::Render()
{
	

	Camera camera{ glm::vec3(0.0f) };

	shader.Bind();
	Transform& t = entity->GetComponent<Transform>();
	glm::mat4 model = t.GetTransform();

	shader.SetMat4("model", model);
	shader.SetMat4("projection", camera.GetPojectionMatrix());

	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	shader.Unbind();
}
