#pragma once
#include "vertex_array.h"
#include "core/sprite_renderer.h"
#include "graphics/uniform_buffer.h"

namespace Lucent {
	enum class RenderPrimitive {
		TRIANGLES = GL_TRIANGLES,
		LINES = GL_LINES,
		POINTS = GL_POINTS,
	};

	struct CameraData {
		glm::mat4 viewProjection{0.0f};
	};

	class Renderer {
	public:
		static CameraData cameraData;
		static UniformBuffer* cameraBuffer;

		static void Prepare();
		static void SetViewProjectionMatrix(glm::mat4 viewProjection);

		// Draw
		static void DrawIndexed(RenderPrimitive primitive, const VertexArray* vertexArray, unsigned int indiciesSize);
		static void DrawArray(RenderPrimitive primitive, const VertexArray* vertexArray, unsigned int veriticesSize);

		static void DrawIndexedTriangles(const VertexArray* vertexArray, unsigned int indiciesSize);
		static void DrawLines(const VertexArray* vertexArray, unsigned int veriticesSize);

		static void DrawSprite(const SpriteRenderer& spriteRenderer);
	};
}