#include "sprite_renderer.h"
#include "graphics/renderer.h"


VertexArray* SpriteRenderer::m_vao = nullptr;

void SpriteRenderer::SetName(const std::string& n)
{
	name = n;
}

void SpriteRenderer::Prepare()
{
	// Initilize VertexArray for all sprites, only one time after initlizing Renderer api.
	if (m_vao == nullptr) SpriteRenderer::m_vao = new VertexArray(&Mesh::QuadMesh);
}


void SpriteRenderer::Render(Camera& camera)
{
	Renderer::DrawSprite(*this);
}
