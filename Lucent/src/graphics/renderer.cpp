#include "renderer.h"

namespace Lucent {
	CameraData Renderer::cameraData;
	UniformBuffer* Renderer::cameraBuffer = nullptr;

	void Renderer::Prepare() {
		if (cameraBuffer == nullptr) cameraBuffer = new UniformBuffer(sizeof(cameraData), 0);
	}

	void Renderer::SetViewProjectionMatrix(glm::mat4 viewProjection) {
		Renderer::cameraData.viewProjection = viewProjection;
		cameraBuffer->SetData(&Renderer::cameraData, 0, sizeof(cameraData));
	}

	void Renderer::DrawSprite(const SpriteRenderer& spr)
	{
		spr.texture.Bind();
		spr.shader.Bind();

		Transform& t = spr.entity->GetComponent<Transform>();
		spr.shader.SetMat4("model", t.GetTransform());

		spr.m_vao->Bind();
		Renderer::DrawIndexedTriangles(spr.m_vao, spr.m_vao->GetIndexCount());
		spr.m_vao->Unbind();

		spr.shader.Unbind();
	}

	void Renderer::DrawIndexedTriangles(const VertexArray* vertexArray, unsigned int indiciesSize)
	{
		Renderer::DrawIndexed(RenderPrimitive::TRIANGLES, vertexArray, indiciesSize);
	}

	void Renderer::DrawLines(const VertexArray* vertexArray, unsigned int veriticesSize)
	{
		Renderer::DrawArray(RenderPrimitive::LINES, vertexArray, veriticesSize);
	}

	void Renderer::DrawIndexed(RenderPrimitive primitive, const VertexArray* vertexArray, unsigned int indiciesSize)
	{
		vertexArray->Bind();
		glDrawElements((GLenum)primitive, indiciesSize, GL_UNSIGNED_INT, 0);
	}


	void Renderer::DrawArray(RenderPrimitive primitive, const VertexArray* vertexArray, unsigned int veriticesSize)
	{
		vertexArray->Bind();
		glDrawArrays((GLenum)primitive, 0, veriticesSize);
	}
}