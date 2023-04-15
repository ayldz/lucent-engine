#include "sprite_renderer.h"



VertexArray* SpriteRenderer::m_vao = nullptr;

void SpriteRenderer::SetName(const std::string& n)
{
	name = n;
}

void SpriteRenderer::Prepare()
{
	// Initilize VertexArray for all sprites, only one time after initlizing Renderer api.
	if (m_vao == nullptr) SpriteRenderer::m_vao = new VertexArray(&Mesh::QuadMesh);

	Resources::GetTexture("container").Bind();
}

void SpriteRenderer::Render(Camera& camera)
{
	Resources::GetShader("sprite").Bind();
	Transform& t = entity->GetComponent<Transform>();
	glm::mat4 model = t.GetTransform();

	Resources::GetShader("sprite").SetMat4("model", model);
	Resources::GetShader("sprite").SetMat4("viewProjection", camera.GetViewProjectionMatrix());

	SpriteRenderer::m_vao->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	Resources::GetShader("sprite").Unbind();
}
